#include <read_input.hpp>
#include <scene_manager.hpp>
#include <scene.hpp>

namespace engine
{

	void Read_input::run(float time)
	{
		//std::cout << "read input   -   priority: " << this->priority << std::endl;
		Scene_manager::instance().current_scene->read_input();
		window->handle_events();
	}
}

