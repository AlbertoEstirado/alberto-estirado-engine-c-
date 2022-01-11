#include <update.hpp>
#include <scene_manager.hpp>
#include <scene.hpp>
namespace engine
{
	
	void Update::run(float time)
	{
		//std::cout << "update   -   priority: " << this->priority << std::endl;

		Scene_manager::instance().current_scene->update(time);
	}
}

