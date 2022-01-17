#ifndef RENDERER_SYSTEM
#define RENDERER_SYSTEM

#pragma once

#include <system.hpp>
#include <window.hpp>
#include <Render_Node.hpp>
#include <memory>



namespace engine
{
	//class glt::Render_Node;
	class Render_Component;

	class Renderer_System : public System
	{

		//std::shared_ptr< Window > window;
		Window* window;
		//glt::Render_Node* render_node = nullptr;
	
	public:

		std::vector<Render_Component*> render_components;

		std::unique_ptr < glt::Render_Node > render_node;

		Renderer_System(Window& window);

		void run(float) override;
		void add_render_component(Render_Component*);

		~Renderer_System();


	};

}

#endif