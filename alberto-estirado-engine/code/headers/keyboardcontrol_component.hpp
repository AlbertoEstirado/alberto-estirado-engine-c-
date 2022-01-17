
#pragma once

#include <component.hpp>
#include <dispatcher.hpp>

namespace engine
{
	
	class Keyboardcontrol_Component : public Component, public Dispatcher::Listener
	{

		~Keyboardcontrol_Component() = default;

	public:

		Keyboardcontrol_Component(Entity* e);

		void receptor(Message& message) override;
	};

}