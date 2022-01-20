
#include <box_collider_component.hpp>
#include <entity.hpp>
#include <transform.hpp>

namespace engine
{

	Box_Collider_Component::Box_Collider_Component(Entity* e, float scale_x, float scale_z, engine::Collider_Component::Type type = STATIC)
	{
		entity = e;
		this->type = type;

		Transform* t = entity->get_transform();

		x = t->get_position_x() - scale_x / 2;
		y = t->get_position_z() - scale_z / 2;
		width =scale_x;
		height = scale_z;

		std::cout << "col: [" << x << ", " << y << ", "<< width << ", " << height << "]"<< std::endl;
	}

	void Box_Collider_Component::im_colliding_with(Box_Collider_Component* other)
	{
		float left1 = x;
		float right1 = x + width;
		float bot1 = y;
		float top1 = y + height;
		
		float left2 = other->x;
		float right2 = other->x + other->width;
		float bot2 = other->y;
		float top2 = other->y + other->height;

		//std::cout << "#################" << std::endl;
		//std::cout << "col: [" << x << ", " << y << ", " << width << ", " << height << "]" << std::endl;
		//std::cout << "col: [" << other->x << ", " << other->y << ", " << other->width << ", " << other->height << "]" << std::endl;
		//std::cout << "#################" << std::endl;

		if ((right1 >= left2 && left1 <= right2 && top1 >= bot2 && bot1 <= top2) ||
			(right2 >= left1 && left2 <= right1 && top2 >= bot1 && bot2 <= top1))
		{
			std::cout << entity->id << " im colliding with: " << other->entity->id << std::endl;
			//on_collider_enter(other);
		}

	}

}