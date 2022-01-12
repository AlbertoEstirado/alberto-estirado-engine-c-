
#pragma once

#include <component.hpp>
#include <Model.hpp>
#include <Model_Obj.hpp>
#include <renderer_system.hpp>

namespace engine
{

	class Renderer : public Component
	{

		~Renderer() = default;

	public:

		//std::shared_ptr< glt::Model*  > model;
		//glt::Model* model;

		Renderer(std::string, Renderer_System *);

		void awake() {};
		void start() {};
		void update(float time);
	};
}

