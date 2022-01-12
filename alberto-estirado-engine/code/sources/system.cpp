#include <system.hpp>


namespace engine
{

	void System::run(float time = 0)
	{
		for (size_t i = 0; i < components.size(); i++)
		{
			components[i]->update(time);
		}
	}

	void System::add_component(Component * new_component)
	{
		components.push_back(new_component);
	}

}