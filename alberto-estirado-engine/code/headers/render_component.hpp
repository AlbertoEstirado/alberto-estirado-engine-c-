
#pragma once

#include <component.hpp>
#include <Model.hpp>
#include <Model_Obj.hpp>
#include <renderer_system.hpp>

namespace engine
{
	class Render_Component : public Component
	{
	public:

		virtual glt::Node& get_node() = 0;
		
	};
}

