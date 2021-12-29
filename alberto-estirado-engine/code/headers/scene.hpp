#include <iostream>
#include <map>

#include "entity.hpp"
#include "scene_manager.hpp"

#pragma once

namespace engine
{
	typedef std::string Id;

	class Scene
	{
		enum STATE
		{
			UNINITIALIZED,
			LOADING,
			ONGOIN,
			WAITTING,
			FINISHED,
		};

		STATE state;

		std::map<Entity, Id> entities;

	public:

		std::string name;
	
		Scene(std::string name);

		void load_scene();
	
	};


}