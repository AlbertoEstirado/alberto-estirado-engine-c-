
#include <box_collider_component.hpp>
#include <entity.hpp>
#include <transform.hpp>

namespace engine
{

	Box_Collider_Component::Box_Collider_Component(Entity* e, float scale_x, float scale_z, Type type = STATIC)
	{
		entity = e;
		this->type = type;

		Transform* t = entity->get_transform();

		x = t->get_position_x() - scale_x / 2;
		y = t->get_position_z() - scale_z / 2;
		with = x + scale_x;
		height = y + scale_z;
	}

}