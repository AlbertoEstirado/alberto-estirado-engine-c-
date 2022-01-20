
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


		//virtual void on_collider_enter(Collider_Component* other) = 0;
	};

}