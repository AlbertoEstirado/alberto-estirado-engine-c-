#include <iostream>
#include <map>

#include "entity.hpp"
#include "scene_manager.hpp"
#include <rapidxml.hpp>
#include <dispatcher.hpp>
#include <render_component.hpp>

#pragma once

namespace engine
{
	class Window;

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

		std::map<Id, Entity*> entities;
		
	public:

		Dispatcher* dispatcher = nullptr;
		Renderer_System* renderer_system = nullptr;
		std::string name;
	
		Scene(const std::string & name, Window & window);

		void load_scene();
		void parse_node_component(rapidxml::xml_node<>*, Entity*);
		void awake();
		void start();
		void update(float time);
		void read_input();
		void render();
		void save_scene();
		Dispatcher* get_dispatcher();
		void add_entity(Entity *);
		Entity * get_entity(const std::string &);

		void parse_transform(rapidxml::xml_node<>*, Entity*);

		std::string get_name ()
		{
			return name;
		}
	
	};


}