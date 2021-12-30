#pragma once

#include <map>
#include <vector>
#include <iostream>


namespace engine
{
	class Scene;

	typedef std::string Id;

	class Scene_manager
	{
	
	public:

		static Scene_manager & instance()
		{
			static Scene_manager scene_manager;
			return scene_manager;
		}

		std::vector<Scene *> scenes; //smartpointer??
		//std::map<Id, Scene *> scenes;

		Scene* current_scene;

		void add_scene(Scene* newscene);
		void initialize();
		void run_scene(Scene* scene);

	private:

		Scene_manager();

		~Scene_manager() = default;

		Scene_manager(const Scene_manager&) = delete;

	};

}