#include "../headers/scene_manager.hpp"
#include "../headers/scene.hpp"

namespace engine
{
	Scene_manager::Scene_manager()
	{
		//scenes.resize(0);
	}

	void Scene_manager::add_scene(Scene* newscene)
	{
		//scenes.insert(std::pair<Id, Scene*>(newscene->get_name(), newscene));
		scenes.push_back(newscene);
	}

	void Scene_manager::initialize()
	{
		if(scenes.size() <= 0)
		{
			std::cout << "There is no scene created!";
			return;
		}
		else
		{
			current_scene = scenes[0];
			std::cout << current_scene->get_name();
		}
	}

	void Scene_manager::run_scene(Scene * scene)
	{
		current_scene = scene;
		scene->load_scene();
	}


}