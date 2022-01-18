#include <player_movement_controller.hpp>
#include <transform.hpp>
#include <entity.hpp>
#include <scene.hpp>

namespace engine
{
	Payer_Movement_Controller::Payer_Movement_Controller(Entity* e)
	{
		entity = e;
		speed = 0.01;
		dir[0] = 0;
		dir[1] = 0;

		entity->scene->get_dispatcher()->add_listener("w", *this);
		entity->scene->get_dispatcher()->add_listener("a", *this);
		entity->scene->get_dispatcher()->add_listener("s", *this);
		entity->scene->get_dispatcher()->add_listener("d", *this);
	}

	void Payer_Movement_Controller::update()
	{
		Transform* t = entity->get_transform();

		t->position.x += speed * dir[0];
		t->position.z += speed * dir[1];

	}

	void Payer_Movement_Controller::receptor(Message& message)
	{
		if (message.get_Id() == "w")
		{
			dir[1] = -1;
		}
		if (message.get_Id() == "a")
		{
			dir[0] = -1;
		}
		if (message.get_Id() == "s")
		{
			dir[1] = 1;
		}
		if (message.get_Id() == "d")
		{
			dir[0] = 1;
		}
	}

}