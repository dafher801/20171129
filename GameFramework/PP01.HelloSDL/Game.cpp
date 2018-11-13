#include "Game.h"
#include <iostream>
#include <SDL_image.h>

bool Game::init(const char * title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		_window = SDL_CreateWindow(title, xpos, ypos, width, height, fullscreen);

		if (_window != 0)
		{
			_renderer = SDL_CreateRenderer(_window, -1, 0);
		}
	}
	else
	{
		return false;
	}

	SDL_SetRenderDrawColor(_renderer, 255, 0, 0, 255);
	_textureManager.load("assets/animate-alpha.png", "animate", _renderer);

	return true;
}

void Game::render()
{
	SDL_RenderClear(_renderer);
	_textureManager.draw("animate", 0, 0, 128, 82, _renderer);
	_textureManager.drawFrame("animate", 100, 100, 128, 82, 1, _currentFrame, _renderer);
	SDL_RenderPresent(_renderer);
}

void Game::update()
{
	_currentFrame = int(((SDL_GetTicks() / 100) % 6));
}

void Game::clean()
{
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
