#include <iostream>
#include "scene_manager.hpp"

#pragma once

namespace engine
{
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

	public:

		std::string name;
	
		Scene(std::string name);
	
	};


}