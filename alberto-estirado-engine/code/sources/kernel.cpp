#include "../headers/kernel.hpp"


namespace engine
{
	Kernel::Kernel()
	{
		window = new Window(800, 600);
	}

	void Kernel::initialization()
	{
		
		Update* update = new Update(20);
		Render* render = new Render(30);
		Read_input* read_input = new Read_input(10);

		add_task(update);
		add_task(render);
		add_task(read_input);

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