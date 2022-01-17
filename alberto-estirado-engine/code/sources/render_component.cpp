
#include <render_component.hpp>
#include <iostream>
#include <Cube.hpp>
#include <entity.hpp>
#include <transform.hpp>

using namespace glt;
using namespace std;

namespace engine
{
	Render_Component::Render_Component(Entity * e, const std::string & path, Renderer_System & render_system)
	{ 
		std::cout << "render component creado" << std::endl;

		entity = e;

		model.reset( new Model_Obj(path));
	
		render_system.render_node->add(entity->id , model);

		render_system.add_render_component(this);
	}
	
}
