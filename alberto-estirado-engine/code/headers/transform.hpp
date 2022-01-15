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
			parent = nullptr;
			position[0] = 0;
			position[1] = 0;
			position[2] = 0;
			rotation[0] = 0;
			rotation[1] = 0;
			rotation[2] = 0;
			rotation[3] = 1;
			scale[0] = 0;
			scale[1] = 0;
			scale[2] = 0;
		}

		Transform(Entity* e, float x, float y, float z, Transform * newParent = nullptr)
		{
			entity = e;
			set_parent(newParent);
			position[0] = x;
			position[1] = y;
			position[2] = z;
			rotation[0] = 0;
			rotation[1] = 0;
			rotation[2] = 0;
			rotation[3] = 1;
			scale[0] = 0;
			scale[1] = 0;
			scale[2] = 0;
		}

		void set_parent(Transform * newParent)
		{
			parent = newParent;
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