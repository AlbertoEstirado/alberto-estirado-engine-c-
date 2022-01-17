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
		position.x = 0;
		position.y = 0;
		position.z = 0;
		//Rotation
		rotation.x = 0;
		rotation.y = 0;
		rotation.z = 0;
		//Scale
		scale.x = 1;
		scale.y = 1;
		scale.z = 1;
	}

	Transform::Transform(Entity* e, float x, float y, float z, Transform* newParent)
	{
		active = true;
		entity = e;
		set_parent(newParent);
		if(newParent)
			std::cout << e->id <<" parent: " << newParent->entity->id << std::endl;

		//Position
		position.x = x;
		position.y = y;
		position.z = z;
		//Rotation
		rotation.x = 0;
		rotation.y = 0;
		rotation.z = 0;
		//Scale
		scale.x = 1;
		scale.y = 1;
		scale.z = 1;
	}

	Transform::Transform(Entity* e, Matrix44 t, Transform* newParent)
	{
		active = true;
		entity = e;
		set_parent(newParent);
		if (newParent)
			std::cout << e->id << " parent: " << newParent->entity->id << std::endl;
		
		//Position
		position.x = t[0][0];
		position.y = t[0][1];
		position.z = t[0][2];
		//Rotation
		rotation.x = t[1][0];
		rotation.y = t[1][1];
		rotation.z = t[1][2];
		//Scale		 
		scale.x = t[2][0];
		scale.y = t[2][1];
		scale.z = t[2][2];

		print_transform();
	}
	
}