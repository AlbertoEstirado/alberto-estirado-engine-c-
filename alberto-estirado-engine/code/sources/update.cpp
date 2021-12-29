#include "../headers/update.hpp"

namespace engine
{
	
	void Update::run(float time)
	{
		std::cout << "update   -   priority: " << this->priority << std::endl;
	}
}

