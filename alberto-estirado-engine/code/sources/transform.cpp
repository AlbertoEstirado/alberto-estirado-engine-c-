#include <transform.hpp>
#include <entity.hpp>
#include <iostream>

namespace engine
{
	
	Transform::Transform(Entity* e)
	{
		active = true;
		entity = e;
		parent = nullptr;
		//Position
		transformation[0][0] = 0;
		transformation[0][1] = 0;
		transformation[0][2] = 0;
		//Rotation
		transformation[1][0] = 0;
		transformation[1][1] = 0;
		transformation[1][2] = 0;
		transformation[1][3] = 1;
		//Scale
		transformation[2][0] = 1;
		transformation[2][1] = 1;
		transformation[2][2] = 1;
	}

	Transform::Transform(Entity* e, float x, float y, float z, Transform* newParent)
	{
		active = true;
		entity = e;
		set_parent(newParent);
		if(newParent)
			std::cout << e->id <<" parent: " << newParent->entity->id << std::endl;

		//Position
		transformation[0][0] = x;
		transformation[0][1] = y;
		transformation[0][2] = z;
		//Rotation
		transformation[1][0] = 0;
		transformation[1][1] = 0;
		transformation[1][2] = 0;
		transformation[1][3] = 1;
		//Scale
		transformation[2][0] = 1;
		transformation[2][1] = 1;
		transformation[2][2] = 1;
	}

	Transform::Transform(Entity* e, Matrix44 t, Transform* newParent)
	{
		active = true;
		entity = e;
		set_parent(newParent);
		if (newParent)
			std::cout << e->id << " parent: " << newParent->entity->id << std::endl;
		
		transformation = t;
	}
	
}