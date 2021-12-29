#include "../headers/kernel.hpp"


namespace engine
{
	Kernel::Kernel()
	{
		window = new Window(800, 600);
	}

	void Kernel::initialization()
	{
        for (auto task : tasks)
        {
            task->initialize();
        }
	}

	void Kernel::execute()
	{
		for(auto task : tasks)
		{
			task->run();
		}
	}

	void Kernel::end()
	{
		for (auto task : tasks)
		{
			task->end();
		}
	}

	void Kernel::add_task(Task * new_task)
	{
		tasks.insert(new_task);
	}
	
}