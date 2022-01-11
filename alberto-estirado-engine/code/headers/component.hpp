#ifndef COMPONENT
#define COMPONENT

#pragma once

namespace engine
{
	class Component
	{
	protected:

		virtual ~Component() = default;


	public:

		virtual void awake() = 0;
		virtual void start() = 0;
		virtual void update(float time) = 0;

		//Component() {};

		
	};

}

#endif