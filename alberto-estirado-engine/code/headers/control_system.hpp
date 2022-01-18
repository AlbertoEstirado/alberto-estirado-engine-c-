
#pragma once

#include <system.hpp>
#include <vector>

namespace engine
{
	class Controller;

	class Control_System: public System
	{
	public:

		std::vector<Controller*> controllers;

		Control_System() {};

		void run(float) override;
		void add_controller(Controller*);

		~Control_System();
	
	};

}