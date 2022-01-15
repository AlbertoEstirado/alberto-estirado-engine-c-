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
		render_system.render_node->get(entity->id)->translate(
			Vector3(
				entity->transform->get_position_x(),
				entity->transform->get_position_y(),
				entity->transform->get_position_z()
			));

		render_system.add_component(this);
	}
	
	

}