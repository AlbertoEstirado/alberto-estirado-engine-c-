#include <vector>
#include <iostream>

#pragma once

namespace engine
{
	class Scene;

	class Scene_manager
	{
	
	public:

		static Scene_manager & instance()
		{
			static Scene_manager scene_manager;
			return scene_manager;
		}

		std::vector<Scene *> scenes; //smartpointer??

		void add_scene(Scene * newscene)
		{
			scenes.push_back(newscene);
		}

	private:

		Scene_manager() = default;

		~Scene_manager() = default;

		Scene_manager(const Scene_manager&) = delete;

	};

}