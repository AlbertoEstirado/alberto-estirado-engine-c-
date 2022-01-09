#include "../headers/entity.hpp"

namespace engine
{
	Entity::Entity()
	{
		id = "";
	}

	//Entity::Entity(std::string id, std::vector<Component*> components)
	//{
	//	this->id = id;
	//
	//	for (size_t i = 0; i < components.size(); i++)
	//	{
	//		add_component(components[i]);
	//	}
	//}

	Entity::Entity(std::string id, Component* transform)
	{
		this->id = id;

		this->transform = transform;
		add_component(transform);
	}

	Entity::Entity(std::string id)
	{
		this->id = id;

		this->transform = nullptr;
	}


	void Entity::awake()
	{
		for (size_t i = 0; i < components.size(); i++)
		{
			std::cout << id << "	:";
			components[i]->awake();
		}
	}

	void Entity::start()
	{
		for (size_t i = 0; i < components.size(); i++)
		{
			std::cout << id << "	:";
			components[i]->start();
		}
	}

	void Entity::update(float time)
	{
		for (size_t i = 0; i < components.size(); i++)
		{
			components[i]->update(time);
		}
	}

	void Entity::add_component(Component * new_component)
	{
		components.push_back(new_component);
	}

	void Entity::add_transform(Component* new_component)
	{
		transform = new_component;
		components.push_back(new_component);
	}

}