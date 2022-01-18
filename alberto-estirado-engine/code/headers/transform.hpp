#ifndef TRANSFORM
#define TRANSFORM

#pragma once

#include "component.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/matrix_decompose.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>

namespace engine
{
	typedef glm::mat4 Matrix44;
	typedef glm::vec3 Vector3;

	class Transform: public Component
	{
	
	public:

		Vector3 position;
		Vector3 rotation;
		Vector3 scale;

		Transform* parent;

		bool active;
		//Transform();

		Transform(Entity* e);
		Transform(Entity* e, float x, float y, float z, Transform* newParent = nullptr);
		Transform(Entity* e, Matrix44 t, Transform* newParent = nullptr);

		void set_parent(Transform * newParent)
		{
			parent = newParent;
		}

		void set_active(bool state)
		{
			active = state;
		}

		Matrix44 get_transform_matrix()
		{
			Matrix44 matrix(1);

			matrix = glm::translate(matrix, position);
			matrix = glm::rotate(matrix, rotation.x, Vector3(1, 0, 0));
			matrix = glm::rotate(matrix, rotation.y, Vector3(0, 1, 0));
			matrix = glm::rotate(matrix, rotation.z, Vector3(0, 0, 1));
			matrix = glm::scale(matrix, scale);

			if (parent)
			{
				return parent->get_transform_matrix() * matrix;
			}

			return matrix;
		}

		float get_position_x()
		{
			return position.x;
		}
		float get_position_y()
		{
			return position.y;
		}
		float get_position_z()
		{
			return position.z;
		}
		float get_rotation_x()
		{
			return rotation.x;
		}
		float get_rotation_y()
		{
			return rotation.y;
		}
		float get_rotation_z()
		{
			return rotation.z;
		}
		float get_scale_x()
		{
			return scale.x;
		}
		float get_scale_y()
		{
			return scale.y;
		}
		float get_scale_z()
		{
			return scale.z;
		}

		void print_transform()
		{
			std::cout << "Position [" << position.x << "," << position.y << "," << position.z << "]" << std::endl;
			std::cout << "Rotation [" << rotation.x << "," << rotation.y << "," << rotation.z << "]" << std::endl;
			std::cout << "Scale    [" << scale.x << "," << scale.y << "," << scale.z << "]" << std::endl;
		}

	};

}

#endif