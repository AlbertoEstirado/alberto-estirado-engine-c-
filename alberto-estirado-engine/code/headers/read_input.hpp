#include "task.hpp"
#include "kernel.hpp"

namespace engine
{

	class Read_input : public Task
	{

	public:

		Read_input(int priority) : Task(priority)
		{
			this->priority = priority;

			Kernel::instance().add_task(this);

		}

		void initialize() {};
		void run(float time);
		void end() {};

	};
}



