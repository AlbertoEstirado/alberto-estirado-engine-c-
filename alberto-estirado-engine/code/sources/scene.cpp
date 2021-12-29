#include "../headers/scene.hpp"


namespace engine
{
	Scene::Scene(std::string name)
	{
		this->name = name;
		state = UNINITIALIZED;
		std::cout << "New scene has been created: " << name << std::endl;
		Scene_manager::instance().add_scene(this);
	}

}