#include <render.hpp>
#include <scene_manager.hpp>
#include <scene.hpp>

namespace engine
{
	
	void Render::initialize()
	{
		
	}

	void Render::run(float time)
	{
		//std::cout << "render   -   priority: " << this->priority << std::endl;

		//Kernel::instance().window->render();

		Scene_manager::instance().current_scene->render();
	}

	void Render::end()
	{
		Kernel::instance().window->end();
	}
}

