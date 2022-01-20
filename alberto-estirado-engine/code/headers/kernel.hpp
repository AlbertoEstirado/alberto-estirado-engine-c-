/**
*
* @author Alberto Estirado López
*
* Distributed under the Boost Software License, version  1.0
* See documents/LICENSE.TXT or www.boost.org/LICENSE_1_0.txt
*
* @date 26/01/2022
*
* estiradoalberto@gmail.com
*/

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
