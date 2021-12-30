#include "../headers/scene.hpp"

namespace engine
{
	Scene::Scene(std::string name)
	{
		this->name = name;
		state = UNINITIALIZED;
		std::cout << "New scene has been created: " << name << std::endl;
		Scene_manager::instance().add_scene(this);
	}

	void Scene::load_scene()
	{
		state = LOADING;
		awake();
	}

	void Scene::add_entity(Entity * new_entity)
	{
		entities.insert(std::pair<Id, Entity*>(new_entity->id, new_entity));
	}

	void Scene::awake()
	{
		state = ONGOIN;

		for (auto& e : entities)
		{
			e.second->awake();
		}

		start();
	}

	void Scene::start()
	{
		for (auto& e : entities)
		{
			e.second->start();
		}
	}

	void Scene::update(float time)
	{
		for(auto & e : entities)
		{
			e.second->update(time);
		}
	}

	void Scene::render()
	{
	
	}

}