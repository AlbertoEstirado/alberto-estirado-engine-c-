
#pragma once

#include <system.hpp>
#include <vector>
#include <collider_component.hpp>

namespace engine
{
	class Colision_System: public System
	{
	public:

		std::vector<Collider_Component*> scene_colliders;
		std::vector<Collider_Component*> scene_dynamic_colliders;

		Colision_System() = default;

		void run(float) override;
		void add_collider(Collider_Component*);

		~Colision_System();


	};

}