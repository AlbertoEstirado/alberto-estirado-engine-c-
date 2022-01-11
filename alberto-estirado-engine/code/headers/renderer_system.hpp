
#pragma once

#include <system.hpp>
#include <window.hpp>
#include <renderer.hpp>


namespace engine
{
	class glt::Render_Node;

	class Renderer_System : public System
	{

		std::shared_ptr< Window > window;
		//std::unique_ptr < glt::Render_Node > render_node;
		glt::Render_Node* render_node;
	
	public:

		Renderer_System(Window& window) ;

		~Renderer_System() {};


	};

}
