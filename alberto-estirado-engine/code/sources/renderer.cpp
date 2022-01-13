
#include <renderer.hpp>
#include <iostream>
#include <Cube.hpp>


using namespace glt;
using namespace std;

namespace engine
{
	Renderer::Renderer(std::string path, Renderer_System * render_system)
	{ 
		//model.reset( new Model_Obj(path));
	
		shared_ptr< Model  > cube(new Model);
		cube->add(shared_ptr< Drawable >(new Cube), Material::default_material());
	
	
		shared_ptr< Camera > camera(new Camera(20.f, 1.f, 50.f, 1.f));
	
		//renderer_node->add("cube", cube);
	
		render_system->render_node->add("cube", cube);
		render_system->render_node->add("camera", camera);
	
		//shared_ptr< Model > a(new Model_Obj(path));
		//this->model = model;
	
		render_system->add_component(this);
	}
	
	void Renderer::update(float time)
	{


		//cout << "renderizando.." << endl;
	}

}
