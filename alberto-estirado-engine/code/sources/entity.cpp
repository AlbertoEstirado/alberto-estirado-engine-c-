#include <entity.hpp>
#include <transform.hpp>

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

	Entity::Entity(std::string & id, Transform* transform)
	{
		this->id = id;

		this->transform = transform;
		add_component(transform);
	}

	Entity::Entity(std::string & id)
	{
		this->id = id;

		this->transform = nullptr;
	}

	void Entity::add_component(Component * new_component)
	{
		components.push_back(new_component);
	}

	void Entity::add_transform(Transform* new_component)
	{
		transform = new_component;
		components.push_back(new_component);
	}

	Transform * Entity::get_transform()
	{
		return this->transform;
	}

}