
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
