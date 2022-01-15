#ifndef KERNEL
#define KERNEL

#pragma once

#include <set>

#include "window.hpp"
#include "task.hpp"

#include <iostream>


namespace engine
{
	class Render;

	class Kernel
	{

	public:

		static Kernel& instance()
		{
			static Kernel kernel;
			return kernel;
		}

		std::set<Task*, Task::Compare> tasks;  //Esto deberia de ser unique_ptr? //task

		bool running = true;

		Kernel();


		void initialization();
		void execute();
		void end();

		void stop_kernel();
		void add_task(Task*);

	};

	
}

#endif