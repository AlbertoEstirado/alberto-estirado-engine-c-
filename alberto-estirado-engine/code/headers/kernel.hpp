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

		std::set<Task*> tasks;  //Esto deberia de ser unique_ptr?

		Window* window = nullptr;

		Kernel();


		void initialization();
		void execute();
		void end();

		void add_task(Task*);

	};

	
}

#endif