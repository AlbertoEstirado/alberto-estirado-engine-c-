
#pragma once

#include <system.hpp>
#include <vector>

namespace engine
{
	class Box_Collider_Component;

	class Colision_System: public System
	{
	public:

		std::vector<Box_Collider_Component*> scene_colliders;
		std::vector<Box_Collider_Component*> scene_dynamic_colliders;

		Colision_System() = default;

		void run(float) override;
		void add_collider(Box_Collider_Component*);

		~Colision_System() {};


	};

}