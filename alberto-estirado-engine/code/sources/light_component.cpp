#include <light_component.hpp>
#include <iostream>
#include <entity.hpp>
#include <transform.hpp>

using namespace glt;
using namespace std;

namespace engine
{
	Light_Component::Light_Component(Entity * e, Renderer_System & render_system)
	{ 
		entity = e;

		light.reset( new Light);
	
		render_system.render_node->add(entity->id , light);
		render_system.render_node->get(entity->id)->translate(Vector3(10.f, 10.f, 10.f));

		render_system.add_component(this);
	}
	
	Light_Component::Light_Component(Entity* e, Renderer_System& render_system, Transform * transform)
	{
		entity = e;

		light.reset(new Light);

		render_system.render_node->add(entity->id, light);
		render_system.render_node->get(entity->id)->translate(
			Vector3(
				transform->get_position_x(),
				transform->get_position_y(),
				transform->get_position_z()
			));

		render_system.add_component(this);
	}

}