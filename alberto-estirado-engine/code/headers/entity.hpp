#include <vector>
#include <iostream>

#include "component.hpp"

#pragma once

namespace engine
{
	class Entity
	{
	public:

		std::string id;

		std::vector<Component*> components;

		Component* transform = nullptr;

		//referencia a la scene

		void awake();
		void start();
		void update(float time);

		Entity();
		//Entity(std::string id, std::vector<Component*> components);
		Entity(std::string id, Component* transform);
		Entity(std::string id);

		void add_component(Component* new_component);
		void add_transform(Component* new_component);

	};
}