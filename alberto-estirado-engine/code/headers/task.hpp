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
