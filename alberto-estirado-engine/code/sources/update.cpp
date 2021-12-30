#include "../headers/update.hpp"
#include "../headers/scene_manager.hpp"
#include "../headers/scene.hpp"
namespace engine
{
	
	void Update::run(float time)
	{
		//std::cout << "update   -   priority: " << this->priority << std::endl;

		Scene_manager::instance().current_scene->update(time);
	}
}

