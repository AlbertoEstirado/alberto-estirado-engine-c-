#include <system.hpp>
#include <entity.hpp>


namespace engine
{

	void System::run(float time = 0)
	{
		
	}

	void System::add_component(Component * new_component)
	{
		std::cout << "se ha añadido un componente de: "<< new_component->entity->id << std::endl;
		components.push_back(new_component);
	}

}