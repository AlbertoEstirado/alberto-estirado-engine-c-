#include <scene.hpp>
#include <fstream>
#include <sstream>
#include <iostream>
#include <transform.hpp>
#include <kernel.hpp>

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

			Entity* newEntity = new Entity(strValue);
			

			for (xml_node<>* component = entity->first_node();
				component; component = component->next_sibling())
			{
				xml_attribute<>* cAttr = component->first_attribute("id");
				std::string strCValue = cAttr->value();
				cout << "	**** " << component->name() << "  id:" << strCValue;
				cout << "value :" << component->value() << "\n";
				if(strCValue == "transform")
				{
					newEntity->add_transform(new Transform(newEntity));
				}
				if (strCValue == "render_component")
				{
					newEntity->add_component(new Render_Component(newEntity, component->value(), *renderer_system));
					//renderer_system->add_component(newEntity->components.back());
				}

			}

			add_entity(newEntity);
		}

		cout << "numero de entidades a�adidas: " << entities.size() << endl;

		for (auto& e : entities)
		{
			cout << "         " << e.first << endl;
		}

		awake();
	}

	void Scene::add_entity(Entity * new_entity)
	{
		entities.insert(std::pair<Id, Entity*>(new_entity->id, new_entity));
	}

	void Scene::awake()
	{
		state = ONGOIN;

		start();
	}

	void Scene::start()
	{
		
	}

	void Scene::update(float time)
	{
		
	}

	void Scene::render()
	{
		renderer_system->run(0);
	}

	void Scene::save_scene()
	{

	}
}