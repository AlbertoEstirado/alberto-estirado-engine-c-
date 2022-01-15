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
		Scene_manager::instance().current_scene->render();
	}

	void Render::end()
	{
		Kernel::instance().stop_kernel();
	}
}

