#include "task.hpp"
#include "kernel.hpp"

namespace engine
{
	class Update : public Task
	{

	public:

		Update(int priority) : Task(priority)
		{
			this->priority = priority;

			Kernel::instance().add_task(this);
		}

		void initialize() {};
		void run();
		void end() {};
		
	};
}



