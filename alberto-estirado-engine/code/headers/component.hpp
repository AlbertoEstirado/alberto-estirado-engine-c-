
#ifndef COMPONENT
#define COMPONENT

#pragma once

namespace engine
{
	class Entity;

	class Component
	{
	protected:

		virtual ~Component() = default;

	public:

		Entity* entity = nullptr;

	};

}

#endif