#include "../headers/scene_manager.hpp"


namespace engine
{
	Scene_manager::Scene_manager()
	{
		scenes.resize(1);
	}


	void Scene_manager::initialize()
	{
		if(scenes.size() <= 0)
		{
			std::cout << "There is no scene created!";
		}
		else
		{


		}
	}


}