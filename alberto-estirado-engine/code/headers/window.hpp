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

		void render();
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