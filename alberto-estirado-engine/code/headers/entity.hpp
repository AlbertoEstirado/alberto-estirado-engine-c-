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

		std::vector<Component*> componets;

		void awake();
		void start();
		void update(float time);

		Entity();
		//Entity(std::string id, std::vector<Component*> components);
		Entity(std::string id, Component* components);

		void add_component(Component* new_component);

	};
}