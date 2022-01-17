
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

		//for (size_t i = 0; i < components.size(); i++)
		//{
		//	std::cout << components[i]->entity->id << " position: ";
		//	std::cout << components[i]->entity->transform->get_position_x() << ",";
		//	std::cout << components[i]->entity->transform->get_position_y() << ",";
		//	std::cout << components[i]->entity->transform->get_position_z() << std::endl;
		//	//render_node->get(components[i]->entity->id)->translate
		//	//(Vector3(
		//	//	components[i]->entity->transform->get_position_x(),
		//	//	components[i]->entity->transform->get_position_y(),
		//	//	components[i]->entity->transform->get_position_z()
		//	//));
		//}

		auto player = render_node->get("player");
		//player->translate(Vector3(.1f, 0, 0));
		//player->rotate_around_x(0.01f);
		//player->rotate_around_y(0.02f);
		//player->rotate_around_z(0.03f);
		
		window->clear();
		render_node->render();
		window->swap_buffers();
	}

	Renderer_System::~Renderer_System()
	{
	
	}

}
