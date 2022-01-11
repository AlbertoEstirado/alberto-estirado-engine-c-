#include <read_input.hpp>


namespace engine
{

	void Read_input::run(float time)
	{
		//std::cout << "read input   -   priority: " << this->priority << std::endl;

		Kernel::instance().window->handle_events();
	}
}

