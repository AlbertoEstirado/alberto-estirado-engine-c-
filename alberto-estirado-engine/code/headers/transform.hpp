#ifndef TRANSFORM
#define TRANSFORM

#pragma once

#include "component.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/matrix_decompose.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace engine
{
	typedef glm::mat4 Matrix44;
	typedef glm::vec3 Vector3;

	class Transform: public Component
	{
	
	public:

		Transform* parent;

		Matrix44 transformation;
		Matrix44 local_scale;
		Matrix44 local_anchor;

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

		Matrix44 get_total_transformation() const
		{
			if (parent)
			{
				return parent->get_total_transformation() * transformation;
			}
			else
				return transformation;
		}

		void reset_transformation()
		{
			transformation = local_scale * local_anchor;
		}

		void translate(const Vector3& displacement)
		{
			transformation = glm::translate(transformation, displacement);
		}

		void scale(float scale)
		{
			transformation = glm::scale(transformation, Vector3(scale, scale, scale));
		}

		void rotate_around_x(float angle)
		{
			transformation = glm::rotate(transformation, angle, glm::vec3(1.f, 0.f, 0.f));
		}

		void rotate_around_y(float angle)
		{
			transformation = glm::rotate(transformation, angle, glm::vec3(0.f, 1.f, 0.f));
		}

		void rotate_around_z(float angle)
		{
			transformation = glm::rotate(transformation, angle, glm::vec3(0.f, 0.f, 1.f));
		}

		float get_position_x()
		{
			return transformation[0][0];
		}
		float get_position_y()
		{
			return transformation[0][1];
		}
		float get_position_z()
		{
			return transformation[0][2];
		}
		float get_rotation_x()
		{
			return transformation[1][0];
		}
		float get_rotation_y()
		{
			return transformation[1][1];
		}
		float get_rotation_z()
		{
			return transformation[1][2];
		}
		float get_scale_x()
		{
			return transformation[2][0];
		}
		float get_scale_y()
		{
			return transformation[2][1];
		}
		float get_scale_z()
		{
			return transformation[2][2];
		}

	};

}

#endif