#include <iostream>
#include <SDL_image.h>
#include <stdio.h>
#include "Game.h"
#include "Monster.h"

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

	if (!TheTextureManager::Instance()->load("assets/animate-alpha.png", "animate", _renderer))
	{
		return false;
	}

	for (int i = 0; i < MONSTER_NUM; i++)
	{
		_monsters[i] = new Monster;
		_monsters[i]->load(0, 100 * (i + 1), 128, 82, "animate");
		_gameObjects.push_back(_monsters[i]);
	}

	return true;
}

void Game::render()
{
	SDL_RenderClear(_renderer);

	for (std::vector<GameObject*>::size_type i = 0; i != _gameObjects.size(); i++)
	{
		_gameObjects[i]->draw(_renderer);
	}

	SDL_RenderPresent(_renderer);
}

void Game::update()
{
	for (std::vector<GameObject*>::size_type i = 0; i != _gameObjects.size(); i++)
	{
		_gameObjects[i]->update();
	}
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
