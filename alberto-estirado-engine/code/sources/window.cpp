#include <iostream>

#include "../headers/window.hpp"

namespace engine
{
	Window::Window(size_t width, size_t height)
	{
		exit = false;

		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			SDL_Log("Error SDL2.");
		}
		else
		{
			window = SDL_CreateWindow("engine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
		}

		if (not window)
		{
			SDL_Log("Error window.");
		}
		else
		{
			SDL_Surface* surface = SDL_GetWindowSurface(window);
		}
	}


	void Window::render()
	{
		if(surface)
		{
			SDL_FillRect(surface, 0, SDL_MapRGB(surface->format, 225, 225, 225));
			SDL_UpdateWindowSurface(window);
		}
	}

	void Window::end()
	{
		SDL_DestroyWindow(window);
		SDL_Quit();
	}

	void Window::handle_events()
	{
		SDL_Event event;

		while (SDL_PollEvent(&event) > 0)
		{
			if (event.type == SDL_QUIT)
			{
				exit = true;
			}
		}
	}

}
