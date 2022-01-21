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

		std::string id;							//< Id of the entity

		std::vector<Component*> components;		//< List of all the diferent components

		Transform* transform = nullptr;			//< Transform os the entity

		Scene* scene = nullptr;					//< Current scene where the entity remains

		Entity();
		Entity(std::string& id, Scene* scene);
		/*
		* Entity constructor, needs an id and a transform
		* @param id
		* @param transform
		**/
		Entity(std::string & id, Transform* transform);
		Entity(std::string & id);

		/*
		* Functition to add new components to the list
		* @param new_component
		**/
		void add_component(Component* new_component);
		/*
		* Functition to establish a transform
		* @param new_component
		**/
		void add_transform(Transform* new_component);
		
		/*
		* Returns the transform entity
		**/
		Transform* get_transform();

		//template<class T>
		//T * get_component(T* component)
		//{
		//	for (size_t i = 0; i < components[i]; i++)
		//	{
		//		if (dynamic_cast<component*>(component[i]))
		//		{
		//			return component[i];
		//		}
		//	}
		//}
	};
}

#endif
