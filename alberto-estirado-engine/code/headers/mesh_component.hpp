#pragma once

#include <Model.hpp>
#include <Model_Obj.hpp>
#include <renderer_system.hpp>
#include <render_component.hpp>

namespace engine
{
	class Mesh_Component : public Render_Component
	{

		~Mesh_Component() = default;

	public:

		std::shared_ptr< glt::Model > model = nullptr;

		Mesh_Component(Entity* e, const std::string&, Renderer_System&);

		glt::Node & get_node() override
		{
			return *model;
		}
	};
}
