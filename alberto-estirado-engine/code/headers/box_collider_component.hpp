
#pragma once

#include <collider_component.hpp>

namespace engine
{
	class Box_Collider_Component : public Collider_Component
	{
	public:
	
		float x, y, width, height;

		Box_Collider_Component(Entity* e ,float, float, Type t);

		void im_colliding_with(Box_Collider_Component*);

		//void on_collider_enter(Collider_Component* other)override {};
	};

}