/**
*
* @author Alberto Estirado López
*
* Distributed under the Boost Software License, version  1.0
* See documents/LICENSE.TXT or www.boost.org/LICENSE_1_0.txt
*
* @date 26/01/2022
*
* estiradoalberto@gmail.com
*/

#include <SDL.h>
#include <ciso646>
#include <iostream>

#pragma once

namespace engine
{
	class Window
	{

	public:


		bool exit;

		size_t width = 0;
		size_t height = 0;

		SDL_Window* window = nullptr;
		SDL_Surface* surface = nullptr;
		SDL_GLContext gl_context;

		Window(const std::string& title, size_t  width, size_t height, bool fullscreen = false);

		void end();
		void handle_events();

		void enable_vsync();
		void disable_vsync();
		void clear() const;
		void swap_buffers() const;

		unsigned get_width() const;
		unsigned get_height() const;
	};
}
