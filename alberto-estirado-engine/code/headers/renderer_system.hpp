#ifndef RENDERER_SYSTEM
#define RENDERER_SYSTEM

#pragma once

#include <system.hpp>
#include <window.hpp>
#include <Render_Node.hpp>
#include <memory>


namespace engine
{
	class glt::Render_Node;

	class Renderer_System : public System
	{

		//std::shared_ptr< Window > window;
		Window* window;
		//glt::Render_Node* render_node = nullptr;
	
	public:
		std::unique_ptr < glt::Render_Node > render_node;

		void run(float) override;

		Renderer_System(Window& window) ;

		~Renderer_System();


	};

}

#endif