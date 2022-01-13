
#pragma once

#include <renderer_system.hpp>

using namespace glt;

namespace engine 
{
	Renderer_System::Renderer_System(Window& w)
	{
		window = &w;
		//render_node = nullptr;
		render_node.reset(new Render_Node);
	}
	

	void Renderer_System::run(float time = 0)
	{
		std::cout << "rendering..";

		GLsizei width = GLsizei(window->get_width());
		GLsizei height = GLsizei(window->get_height());
		
		render_node->get_active_camera()->set_aspect_ratio(float(width) / height);
		
		glViewport(0, 0, width, height);
		
		window->clear();
		render_node->render();
		window->swap_buffers();
	}

	//Renderer_System::Renderer_System(Window& window)
	//{
	//	//this->window = &window;
	//	
	//	//renderer.reset(new Render_Node);
	//}


	Renderer_System::~Renderer_System()
	{
	
	}

}
