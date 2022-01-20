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

#ifndef TASK
#define TASK

#pragma once

#include <iostream>

namespace engine
{
	class Task
	{

	public:

		int priority;

		struct Compare
		{
			bool operator () (const Task * a, const Task * b) const
			{
				return  a->priority < b->priority;
			}
		};


		Task(int priority = 0)
		{
			this->priority = priority;
		}

		virtual void run(float time) = 0;
		virtual void initialize() = 0;
		virtual void end() = 0;

		bool operator < (const Task& other) const
		{
			return this->priority < other.priority;
		}

	};

}

#endif // !TASK
