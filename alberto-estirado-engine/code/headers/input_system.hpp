#pragma once

#include <system.hpp>
#include <window.hpp>
#include <Render_Node.hpp>
#include <memory>



namespace engine
{

	class Input_System : public System
	{
	public:

		Input_System() = default;

		void run(float) override;

		~Input_System();

	};

}