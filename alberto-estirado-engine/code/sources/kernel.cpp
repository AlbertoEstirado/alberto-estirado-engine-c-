#include <kernel.hpp>


namespace engine
{
	Kernel::Kernel()
	{
		window = new Window("engine",800, 600);
		window->enable_vsync();
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
	
}