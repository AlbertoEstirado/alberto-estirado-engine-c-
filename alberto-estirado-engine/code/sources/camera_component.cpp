#include <camera_component.hpp>
#include <iostream>
#include <entity.hpp>
#include <transform.hpp>

using namespace glt;
using namespace std;

namespace engine
{

	Camera_Component::Camera_Component(Entity* e, Renderer_System& render_system)
	{
		entity = e;

		camera.reset(new Camera(20.f, 1.f, 50.f, 1.f));

		render_system.render_node->add(entity->id, camera);
		render_system.render_node->get(entity->id)->translate(
			Vector3(
				entity->transform->get_position_x(),
				entity->transform->get_position_y(),
				entity->transform->get_position_z()
			));

		render_system.add_component(this);
	}


}