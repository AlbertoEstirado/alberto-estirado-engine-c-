
#pragma once

#include <component.hpp>
#include <Model.hpp>
#include <Model_Obj.hpp>

namespace engine
{
	class Renderer : public Component
	{

		~Renderer() = default;

	public:

		//std::shared_ptr< glt::Model*  > model;
		glt::Model* model;

		Renderer(std::string);

		void awake() {};
		void start() {};
		void update(float time);
	};
}

