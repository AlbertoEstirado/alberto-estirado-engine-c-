#include <system.hpp>


namespace engine
{

	void System::run(float time = 0)
	{
		
	}

	void System::add_component(Component * new_component)
	{
		components.push_back(new_component);
	}

}