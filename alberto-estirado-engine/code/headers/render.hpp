#include "task.hpp"
#include "kernel.hpp"

namespace engine
{

	class Render : public Task
	{

	public:

		Render(int priority) : Task(priority)
		{
			this->priority = priority;

			Kernel::instance().add_task(this);
		}

		void initialize();
		void run();
		void end();

	};
}


