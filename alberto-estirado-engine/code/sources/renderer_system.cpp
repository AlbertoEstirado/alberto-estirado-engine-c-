
#pragma once

#include <renderer_system.hpp>
#include <render_component.hpp>
#include <entity.hpp>
#include <transform.hpp>

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
		GLsizei width = GLsizei(window->get_width());
		GLsizei height = GLsizei(window->get_height());
		
		render_node->get_active_camera()->set_aspect_ratio(float(width) / height);
		
		glViewport(0, 0, width, height);

		for (auto & component : render_components)
		{
			Matrix44 transform_matrix = component->entity->get_transform()->get_transform_matrix();
			//component->entity->transform->print_transform();
			component->model->set_transformation(transform_matrix);
		}
		for (auto& component : components)
		{
			Matrix44 transform_matrix = component->entity->get_transform()->get_transform_matrix();
			//component->entity->transform->print_transform();
			//component->model->set_transformation(transform_matrix);
			//component->node
		}

		window->clear();
		render_node->render();
		window->swap_buffers();
	}

	void Renderer_System::add_render_component(Render_Component* new_component)
	{
		render_components.push_back(new_component);
	}

	Renderer_System::~Renderer_System()
	{
	
	}

}
