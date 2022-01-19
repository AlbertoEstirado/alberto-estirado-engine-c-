
#ifndef CONTROLLER
#define CONTROLLER

#pragma once

#include "entity.hpp"

namespace engine
{
	class Controller 
	{

	public:

		Entity* entity = nullptr;

		virtual void update() = 0;
	};


	/*
	class Control_System() : public System
	{
		map<string, Controller *> controllers;
		list< Control_Componet *> components;

		public:

		shared_ptr<Component> create_compoent(xml_node<> * node) override
		{
			string id = ...;

			auto controller = get_controller(id);

			if(controller)

				auto component = make_shared< Controle_Component >(controller)

				compoenent.push_back(compoenent);

				return component;

			return shared_ptr<Component>();
		}

		void register_controller(const strring & id, Controller & controller)
		{
			controllers[id] = &controller;
		}

		private:

		Controller * get_controller( const ID & id);
	}
	
	*/
}

#endif
