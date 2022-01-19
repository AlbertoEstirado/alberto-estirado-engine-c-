
#pragma once

#include <component.hpp>


namespace engine
{
	class Collider_Component: public Component
	{
	public:
		enum Type
		{
			STATIC,
			DYNAMIC
		};

		Type type;

		//virtual void im_colliding_with(Collider_Component*) = 0; 
	};

}