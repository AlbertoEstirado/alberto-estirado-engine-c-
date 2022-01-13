#ifndef TRANSFORM
#define TRANSFORM

#pragma once

#include "component.hpp"

namespace engine
{
	class Transform: public Component
	{
	
	public:

		Transform* parent;

		float position[3];
		float rotation[4];
		float scale[3];

		//Transform();

		Transform(Entity* e) 
		{
			entity = e;
		}

		float get_position_x()
		{
			return position[0];
		}
	
		float get_position_y()
		{
			return position[1];
		}

		float get_position_z()
		{
			return position[2];
		}

		float get_rotation_x()
		{
			return rotation[0];
		}

		float get_rotation_y()
		{
			return rotation[1];
		}

		float get_rotation_z()
		{
			return rotation[2];
		}

		float get_scale_x()
		{
			return scale[0];
		}

		float get_scale_y()
		{
			return scale[1];
		}

		float get_scale_z()
		{
			return scale[2];
		}

	};

}

#endif