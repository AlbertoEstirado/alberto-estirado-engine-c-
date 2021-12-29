#include "task.hpp"

namespace engine
{
	class Render : public Task
	{

	public:

		Render(int priority) : Task(priority)
		{
			this->priority = priority;
		}

		void initialize();
		void run();
		void end();

	};
}


