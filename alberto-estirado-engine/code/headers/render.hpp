#include "task.hpp"
#include "kernel.hpp"

namespace engine
{

	class Render : public Task
	{

	public:

		Window* window;

		Render(int priority, Window * window) : Task(priority)
		{
			this->window = window;

			this->priority = priority;

			Kernel::instance().add_task(this);
		}

		void initialize();
		void run(float time);
		void end();

	};
}


