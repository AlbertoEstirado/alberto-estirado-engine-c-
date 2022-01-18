
#pragma once

#include <controller.hpp>
#include <entity.hpp>


namespace engine
{
	class Payer_Movement_Controller: public Controller
	{
	public:

		float speed;
		int dir[2];

		Payer_Movement_Controller(Entity * e)
		{
			entity = e;
			speed = 1;
			dir[0] = 0;
			dir[1] = 0;
		}

		void update() override;

	};

}