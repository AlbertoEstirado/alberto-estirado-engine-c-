
#include <render_component.hpp>
#include <iostream>
#include <Cube.hpp>


using namespace glt;
using namespace std;

namespace engine
{
	Render_Component::Render_Component(const std::string & path, Renderer_System * render_system)
	{ 
		model.reset( new Model_Obj(path));
	
		render_system->add_component(this);
	}
	
}
