
#include <colision_system.hpp>
#include <collider_component.hpp>



namespace engine
{
	void Colision_System::run(float time = 0)
	{
		for (size_t i = 0; i < scene_dynamic_colliders.size(); i++)
		{
			for (size_t j = i+1; j < scene_colliders.size(); j++)
			{
				//scene_dynamic_colliders[i]->im_colliding_with(scene_colliders[j]);
			}
		}
	}

	void Colision_System::add_collider(Collider_Component* new_collider)
	{
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
