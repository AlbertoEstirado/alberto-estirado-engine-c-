#include <mesh_component.hpp>
#include <iostream>
#include <Cube.hpp>
#include <entity.hpp>
#include <transform.hpp>

using namespace glt;
using namespace std;

namespace engine
{
	Mesh_Component::Mesh_Component(Entity* e, const std::string& path, Renderer_System& render_system)
	{
		std::cout << "Mesh_Component creado" << std::endl;

		entity = e;

		model.reset(new Model_Obj(path));

		render_system.render_node->add(entity->id, model);

		render_system.add_render_component(this);
	}

}