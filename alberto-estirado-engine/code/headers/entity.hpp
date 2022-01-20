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

#ifndef ENTITY
#define ENTITY

#include <vector>
#include <iostream>

#include "component.hpp"

#pragma once

namespace engine
{
	class Transform;
	class Scene;

	class Entity
	{
	public:

		std::string id;

		std::vector<Component*> components;

		Transform* transform = nullptr;

		Scene* scene = nullptr;

		Entity();
		Entity(std::string& id, Scene* scene);
		Entity(std::string & id, Transform* transform);
		Entity(std::string & id);

		void add_component(Component* new_component);
		void add_transform(Transform* new_component);

		Transform* get_transform();

	};
}

#endif
