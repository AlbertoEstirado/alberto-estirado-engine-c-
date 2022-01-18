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
		
		render_system.add_render_component(this);
	}
	
	

}