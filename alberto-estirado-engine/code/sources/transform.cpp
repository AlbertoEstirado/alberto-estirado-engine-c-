#include <transform.hpp>
#include <entity.hpp>
#include <iostream>

namespace engine
{
	
	Transform::Transform(Entity* e)
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

	Transform::Transform(Entity* e, float x, float y, float z, Transform* newParent)
	{
		entity = e;
		set_parent(newParent);
		if(newParent)
			std::cout << e->id <<" parent: " << newParent->entity->id << std::endl;

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
	
}