#include "Game.h"
#include <iostream>

bool Game::init(const char * title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		_window = SDL_CreateWindow(title, xpos, ypos, width, height, fullscreen);

		if (SDL_CreateWindow(title, xpos, ypos, width, height, fullscreen) != 0)
		{
			_renderer = SDL_CreateRenderer(_window, -1, 0);
		}
	}
	else
	{
		return false;
	}

	return true;
}

void Game::render()
{
	SDL_RenderClear(_renderer);
	SDL_RenderPresent(_renderer);
}

void Game::update()
{
}

void Game::clean()
{
	std::cout << "cleaning game" << std::endl;
	SDL_DestroyWindow(_window);
	SDL_DestroyRenderer(_renderer);
	SDL_Quit();
}

void Game::handleEvents()
{
	SDL_Event event;

	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			_running = false;
			break;
		default:
			break;
		}
	}
}
