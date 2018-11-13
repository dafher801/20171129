#include "Game.h"
#include <iostream>

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

	SDL_Surface * tempSurface = SDL_LoadBMP("assets/rider.bmp");
	_texture = SDL_CreateTextureFromSurface(_renderer, tempSurface);

	SDL_FreeSurface(tempSurface);
	SDL_QueryTexture(_texture, NULL, NULL, &_sourceRectangle.w, &_sourceRectangle.h);

	return true;
}

void Game::render()
{
	_destinationRectangle.x = _sourceRectangle.x = 0;
	_destinationRectangle.y = _sourceRectangle.y = 0;
	_destinationRectangle.w = _sourceRectangle.w;
	_destinationRectangle.h = _sourceRectangle.h;

	SDL_RenderClear(_renderer);
	SDL_RenderCopy(_renderer, _texture, &_sourceRectangle, &_destinationRectangle);
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
