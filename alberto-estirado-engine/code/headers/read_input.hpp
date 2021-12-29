#include "task.hpp"

namespace engine
{

	class Read_input : public Task
	{

	public:

		Read_input(int priority) : Task(priority)
		{
			this->priority = priority;
		}

		void initialize() {};
		void run();
		void end() {};

	};
}



