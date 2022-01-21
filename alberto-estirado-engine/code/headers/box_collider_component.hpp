/**
*
* @author Alberto Estirado L�pez
*
* Distributed under the Boost Software License, version  1.0
* See documents/LICENSE.TXT or www.boost.org/LICENSE_1_0.txt
*
* @date 26/01/2022
*
* estiradoalberto@gmail.com
*/
#pragma once

#include <collider_component.hpp>
#include <collision_handler.hpp>

namespace engine
{
	class Box_Collider_Component : public Collider_Component
	{
	public:

		Collision_Handler* on_colision;
	
		float x, y, width, height;		//< Square of the collider

		Box_Collider_Component(Entity* e ,float, float, Type t);

		void im_colliding_with(Box_Collider_Component*);

		//void on_collider_enter(Collider_Component* other)override {};
	};

}
