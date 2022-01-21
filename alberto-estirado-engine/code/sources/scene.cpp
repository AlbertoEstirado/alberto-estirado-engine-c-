/**
*
* @author Alberto Estirado López
*
* Distributed under the Boost Software License, version  1.0
* See documents/LICENSE.TXT or www.boost.org/LICENSE_1_0.txt
*
* @date 26/01/2022
*
* estiradoalberto@gmail.com
*/

#include <scene.hpp>
#include <fstream>
#include <sstream>
#include <iostream>
#include <transform.hpp>
#include <kernel.hpp>
#include <light_component.hpp>
#include <camera_component.hpp>
#include <keyboardcontrol_component.hpp>
#include <mesh_component.hpp>
#include <player_movement_controller.hpp>
#include <enemie_behaviour_controller.hpp>
#include <box_collider_component.hpp>
#include <Render_Node.hpp>

using namespace rapidxml;
using namespace std;

namespace engine
{
	Scene::Scene(const std::string & name, const std::string & path, Window & window)
	{
		this->name = name;
		this->path = path;

		state = UNINITIALIZED;

		//std::cout << "New scene has been created: " << name << std::endl;
		Scene_manager::instance().add_scene(this);

		renderer_system = new Renderer_System(window);
		control_system = new Control_System();
		dispatcher = new Dispatcher();
		colision_system = new Colision_System();
	}

	void Scene::reload()
	{
		renderer_system->render_node.reset(new glt::Render_Node);

		entities.clear();

		delete control_system;
		delete dispatcher;
		delete colision_system;

		control_system = new Control_System();
		dispatcher = new Dispatcher();
		colision_system = new Colision_System();

		load_scene();
	}

	void Scene::load_scene()
	{
		state = LOADING;

		xml_document<> doc;
		ifstream file(path); 
		stringstream buffer;
		buffer << file.rdbuf();
		file.close();
		std::string content(buffer.str());
		doc.parse<0>(&content[0]);

		xml_node<>* pRoot = doc.first_node();

		//cout << "Name of my first node is: " << doc.first_node()->name() << "\n";

		xml_attribute<>* pAttr = doc.first_node()->first_attribute("id");
		std::string strValue = pAttr->value();

		//cout << "Id of my first node is: " << strValue << "\n";
		//cout << "first node: " << pRoot->first_node()->name() << "\n";

		for (xml_node<>* entity = pRoot->first_node()->first_node();
			entity; entity = entity->next_sibling())
		{
			xml_attribute<>* pAttr = entity->first_attribute("id");
			std::string strValue = pAttr->value();

			//cout << "**** " << entity->name() << "  id:" << strValue << "\n";

			Entity* newEntity = new Entity(strValue, this);
			
			parse_node_component(entity, newEntity);
			
			add_entity(newEntity);
		}

		//cout << "numero de entidades añadidas: " << entities.size() << endl;

		

		awake();
	}

	void Scene::parse_node_component(xml_node<>* xml_entity, Entity* newEntity)
	{
		for (xml_node<>* component = xml_entity->first_node();
			component; component = component->next_sibling())
		{
			xml_attribute<>* cAttr = component->first_attribute("id");
			std::string strCValue = cAttr->value();
			//cout << "	**** " << component->name() << "  id:" << strCValue;
			//cout << "value :" << component->value() << "\n";

			if (strCValue == "transform")
			{
				parse_transform(component, newEntity);
			}
			else if (strCValue == "mesh_component")
			{
				newEntity->add_component(new Mesh_Component(newEntity, component->value(), *renderer_system));
			}
			else if(strCValue == "camera_component")
			{
				newEntity->add_component(new Camera_Component(newEntity, *renderer_system));
			}
			else if (strCValue == "light_component")
			{
				newEntity->add_component(new Light_Component(newEntity, *renderer_system));
			}
			else if (strCValue == "keyboardcontrol_component")
			{
				newEntity->add_component(new Keyboardcontrol_Component(newEntity));
			}
			else if (strCValue == "player_movement_controller")
			{
				control_system->add_controller(new Payer_Movement_Controller(newEntity));
			}
			else if (strCValue == "enemie_behaviour_controller")
			{
				control_system->add_controller(new Enemie_Behaviour_Controller(newEntity));
			}
			else if (strCValue == "box_collider_component")
			{
				parse_box_collider_component(component, newEntity);
			}
		}
	}

	void Scene::parse_transform(xml_node<>* component, Entity* newEntity)
	{
		Entity* parent = nullptr;
		if (component->last_attribute("parent"))
		{
			cout << component->last_attribute("parent")->value() << endl;
			parent = get_entity(component->last_attribute("parent")->value());
		}

		Matrix44 transform;

		//Position
		transform[0][0] = std::stof(component->first_node()->first_node()->value());
		transform[0][1] = std::stof(component->first_node()->first_node()->next_sibling()->value());
		transform[0][2] = std::stof(component->first_node()->last_node()->value());
		//std::cout << "position: " << transform[0][0] <<"," << transform[0][1] << "," << transform[0][2] << std::endl;
		//Rotation
		transform[1][0] = std::stof(component->first_node()->next_sibling()->first_node()->value());
		transform[1][1] = std::stof(component->first_node()->next_sibling()->first_node()->next_sibling()->value());
		transform[1][2] = std::stof(component->first_node()->next_sibling()->last_node()->value());
		//std::cout << "rotation: " << transform[1][0] << "," << transform[1][1] << "," << transform[1][2] << std::endl;
		//Scale
		transform[2][0] = std::stof(component->last_node()->first_node()->value());
		transform[2][1] = std::stof(component->last_node()->first_node()->next_sibling()->value());
		transform[2][2] = std::stof(component->last_node()->last_node()->value());
		//std::cout << "scale: " << transform[2][0] << "," << transform[2][1] << "," << transform[2][2] << std::endl;

		if (parent)
			newEntity->add_transform(new Transform(newEntity, transform, parent->get_transform()));
		else
			newEntity->add_transform(new Transform(newEntity, transform));
	}

	void Scene::parse_box_collider_component(xml_node<>* component, Entity* newEntity)
	{

		float scale_x = std::stof(component->first_node()->value());
		float scale_z = std::stof(component->first_node()->next_sibling()->value());

		std::string s_type = component->last_node()->value();

		engine::Collider_Component::Type type;

		if(s_type == "dynamic")
		{
			type = engine::Collider_Component::Type::DYNAMIC;
		}
		else
		{
			type = engine::Collider_Component::Type::STATIC;
		}

		colision_system->add_collider(new Box_Collider_Component(newEntity, scale_x, scale_z, type));
	}

	void Scene::add_entity(Entity * new_entity)
	{
		entities.insert(std::pair<Id, Entity*>(new_entity->id, new_entity));
	}

	Entity * Scene::get_entity(const std::string & id)
	{
		for (auto& e : entities)
		{
			if(e.first == id)
			{
				return e.second;
			}
		}
	}

	void Scene::awake()
	{
		state = ONGOIN;
		start();
	}

	void Scene::start(){}

	void Scene::update(float time)
	{
		control_system->run(time);
		colision_system->run(time);
	}

	void Scene::render()
	{
		renderer_system->run(0);
	}


	Dispatcher* Scene::get_dispatcher()
	{
		return dispatcher;
	}
}
