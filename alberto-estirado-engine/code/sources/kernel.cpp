#include <kernel.hpp>


namespace engine
{
	Kernel::Kernel()
	{
		running = true;
	}

	void Kernel::initialization()
	{
        for (auto task : tasks)
        {
            task->initialize();
			std::cout << task->priority;
        }
	}

	void Kernel::execute()
	{
		//do while
		for(auto task : tasks)
		{
			task->run(0);
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

	void Kernel::stop_kernel()
	{
		running = false;
	}
	
}