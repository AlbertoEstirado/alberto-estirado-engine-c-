
#include <colision_system.hpp>
#include <collider_component.hpp>
#include <box_collider_component.hpp>
#include <transform.hpp>
#include <entity.hpp>

namespace engine
{
	void Colision_System::run(float time = 0)
	{
		for (size_t i = 0; i < scene_dynamic_colliders.size(); i++)
		{
			Transform* t = scene_dynamic_colliders[i]->entity->get_transform();

			scene_dynamic_colliders[i]->x = t->get_position_x() - scene_dynamic_colliders[i]->width / 2;
			scene_dynamic_colliders[i]->y = t->get_position_z() - scene_dynamic_colliders[i]->height / 2;
		}

		for (size_t i = 0; i < scene_dynamic_colliders.size(); i++)
		{
			for (size_t j = i+1; j < scene_colliders.size(); j++)
			{
				scene_dynamic_colliders[i]->im_colliding_with(scene_colliders[j]);
			}
		}
	}

	void Colision_System::add_collider(Box_Collider_Component* new_collider)
	{

		std::cout << "collider added" << std::endl;

		if(new_collider->type == engine::Collider_Component::Type::DYNAMIC)
		{
			scene_colliders.push_back(new_collider);
			scene_dynamic_colliders.push_back(new_collider);
		}
		else
		{
			scene_colliders.push_back(new_collider);
		}
	}

}