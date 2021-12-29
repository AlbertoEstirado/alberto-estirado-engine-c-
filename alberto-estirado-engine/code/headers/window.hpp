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

		Window(size_t  width, size_t height);

		void render();
		void end();
		void handle_events();
	};
}