#include <player_movement_controller.hpp>
#include <transform.hpp>
#include <entity.hpp>

namespace engine
{
	void Payer_Movement_Controller::update()
	{
		Transform* t = entity->get_transform();

		t->position.x += speed * dir[0];
		t->position.z += speed * dir[1];
	}

}