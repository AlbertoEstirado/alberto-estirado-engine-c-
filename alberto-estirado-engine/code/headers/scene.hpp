/**
*
* @author Alberto Estirado L�pez
*
* Distributed under the Boost Software License, version  1.0
* See documents/LICENSE.TXT or www.boost.org/LICENSE_1_0.txt
*
* @date 26/01/2022
*
* estiradoalberto@gmail.com
*/

#include <iostream>
#include <map>

#include "entity.hpp"
#include "scene_manager.hpp"
#include <rapidxml.hpp>
#include <dispatcher.hpp>
#include <render_component.hpp>
#include <control_system.hpp>
#include <colision_system.hpp>

#pragma once

namespace engine
{
	class Window;

	typedef std::string Id;

	class Scene
	{
		enum STATE											//< Enum of the possible states of the scene
		{
			UNINITIALIZED,
			LOADING,
			ONGOIN,
			WAITTING,
			FINISHED,
		};

		STATE state;										//< State of the scene

		std::map<Id, Entity*> entities;						//< List of all the entities that belong to the scene, each entity has an Id to identify them
		
	public:

		Dispatcher		* dispatcher		= nullptr;		//< Menssage system
		Renderer_System	* renderer_system	= nullptr;		//< Pointer of the render system 
		Control_System	* control_system	= nullptr;		//< Pointer of the control system
		Colision_System	* colision_system	= nullptr;		//< Pointor of the colision system

		std::string name;									//< Name of the scene
		std::string path;									//< Path where the xml file persist
	
		/*
		* Constructor of the scene, we initialize all systems and save the path
		* @param name
		* @param path
		* @param window
		*/
		Scene(const std::string & name, const std::string & path , Window & window);

		/*
		* Funtion that parse the xml and creates entities and their componensts
		*/
		void load_scene();

		/*
		* Runs the awake method of all systems
		*/
		void awake();

		/*
		* Runs the start method of all systems
		*/
		void start();

		/*
		* Runs the run method of all systems
		* @param time
		*/
		void update(float time);

		/*
		* Runs the Render System
		*/
		void render();

		/*
		* Reset all systems, clear all entities and load scene from the xml file
		*/
		void reload();

		/*
		* We add to the map a new entity
		* @param Entity
		*/
		void add_entity(Entity*);

		/*
		* Getter of the dispatcher
		*/
		Dispatcher* get_dispatcher();

		/*
		* Returns the entity with the same id
		* @param id
		*/
		Entity * get_entity(const std::string &);

		void parse_transform(rapidxml::xml_node<>*, Entity*);
		void parse_box_collider_component(rapidxml::xml_node<>*, Entity*);
		void parse_node_component(rapidxml::xml_node<>*, Entity*);


		std::string get_name ()
		{
			return name;
		}
	
	};


}
