
#pragma once

#include <component.hpp>
#include <Model.hpp>
#include <Model_Obj.hpp>
#include <renderer_system.hpp>

namespace engine
{
	class Render_Component : public Component
	{

		~Render_Component() = default;

	public:

		std::shared_ptr< glt::Model > model;

		Render_Component(const std::string &, Renderer_System *);
	};
}

