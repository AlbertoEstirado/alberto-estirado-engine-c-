#ifndef ENTITY
#define ENTITY

#include <vector>
#include <iostream>

#include "component.hpp"

#pragma once

namespace engine
{
	class Transform;

	class Entity
	{
	public:

		std::string id;

		std::vector<Component*> components;

		Transform* transform = nullptr;

		//referencia a la scene

		Entity();
		//Entity(std::string id, std::vector<Component*> components);
		Entity(std::string & id, Transform* transform);
		Entity(std::string & id);

		void add_component(Component* new_component);
		void add_transform(Transform* new_component);

		Transform* get_transform();

	};
}

#endif