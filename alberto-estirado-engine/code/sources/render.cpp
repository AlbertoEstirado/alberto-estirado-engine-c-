#include "../headers/render.hpp"

namespace engine
{
	

	void Render::initialize()
	{
		
	}

	void Render::run()
	{
		std::cout << "render   -   priority: " << this->priority << std::endl;

		Kernel::instance().window->render();
		
	}

	void Render::end()
	{
		Kernel::instance().window->end();
	}
}

