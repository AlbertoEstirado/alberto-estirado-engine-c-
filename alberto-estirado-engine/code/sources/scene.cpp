#include <scene.hpp>
#include <fstream>
#include <sstream>
#include <iostream>
#include <transform.hpp>
#include <kernel.hpp>
#include <light_component.hpp>
#include <camera_component.hpp>
#include <keyboardcontrol_component.hpp>

using namespace rapidxml;
using namespace std;

namespace engine
{
	Scene::Scene(const std::string & name, Window & window)
	{
		this->name = name;
		state = UNINITIALIZED;
		std::cout << "New scene has been created: " << name << std::endl;
		Scene_manager::instance().add_scene(this);

		renderer_system = new Renderer_System(window);
		dispatcher = new Dispatcher();
	}

	void Scene::load_scene()
	{
		state = LOADING;

		xml_document<> doc;
		ifstream file("../../code/xml/sample-scene.xml");//fstream::binary?
		stringstream buffer;
		buffer << file.rdbuf();
		file.close();
		std::string content(buffer.str());
		doc.parse<0>(&content[0]);

		xml_node<>* pRoot = doc.first_node();

		cout << "Name of my first node is: " << doc.first_node()->name() << "\n";

		xml_attribute<>* pAttr = doc.first_node()->first_attribute("id");
		std::string strValue = pAttr->value();

		cout << "Id of my first node is: " << strValue << "\n";


		cout << "first node: " << pRoot->first_node()->name() << "\n";
		for (xml_node<>* entity = pRoot->first_node()->first_node();
			entity; entity = entity->next_sibling())
		{
			xml_attribute<>* pAttr = entity->first_attribute("id");
			std::string strValue = pAttr->value();

			cout << "**** " << entity->name() << "  id:" << strValue << "\n";

			Entity* newEntity = new Entity(strValue, this);
			
			parse_node_component(entity, newEntity);
			
			add_entity(newEntity);
		}

		cout << "numero de entidades a�adidas: " << entities.size() << endl;

		for (auto& e : entities)
		{
			cout << "         " << e.first << endl;
		}

		awake();
	}

	void Scene::parse_node_component(xml_node<>* xml_entity, Entity* newEntity)
	{
		for (xml_node<>* component = xml_entity->first_node();
			component; component = component->next_sibling())
		{
			xml_attribute<>* cAttr = component->first_attribute("id");
			std::string strCValue = cAttr->value();
			cout << "	**** " << component->name() << "  id:" << strCValue;
			cout << "value :" << component->value() << "\n";

			if (strCValue == "transform")
			{
				parse_transform(component, newEntity);
			}
			else if (strCValue == "render_component")
			{
				newEntity->add_component(new Render_Component(newEntity, component->value(), *renderer_system));
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
		transform[0][0] = std::stoi(component->first_node()->first_node()->value());
		transform[0][1] = std::stoi(component->first_node()->first_node()->next_sibling()->value());
		transform[0][2] = std::stoi(component->first_node()->last_node()->value());
		//Rotation
		transform[1][0] = std::stoi(component->first_node()->next_sibling()->first_node()->value());
		transform[1][1] = std::stoi(component->first_node()->next_sibling()->first_node()->next_sibling()->value());
		transform[1][2] = std::stoi(component->first_node()->next_sibling()->last_node()->value());
		//Scale
		transform[2][0] = std::stoi(component->last_node()->first_node()->value());
		transform[2][1] = std::stoi(component->last_node()->first_node()->next_sibling()->value());
		transform[2][2] = std::stoi(component->last_node()->last_node()->value());

		if (parent)
			newEntity->add_transform(new Transform(newEntity, transform, parent->get_transform()));
		else
			newEntity->add_transform(new Transform(newEntity, transform));
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
	void Scene::update(float time){}
	void Scene::read_input(){}

	void Scene::render()
	{
		renderer_system->run(0);
	}

	void Scene::save_scene()
	{

	}

	Dispatcher* Scene::get_dispatcher()
	{
		return dispatcher;
	}
}