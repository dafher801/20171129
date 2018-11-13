#include <iostream>
#include <SDL_image.h>
#include <stdio.h>
#include "Game.h"
#include "Player.h"
#include "Enemy.h"

Game * Game::_instance = 0;

Game::Game()
	: _running(true) {}

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

	_gameObjects.push_back(new Player(new LoaderParams(100, 100, 128, 82, "animate")));
	_gameObjects.push_back(new Enemy(new LoaderParams(300, 300, 128, 82, "animate")));

	return true;
}

void Game::render()
{
	SDL_RenderClear(_renderer);

	for (std::vector<GameObject*>::size_type i = 0; i != _gameObjects.size(); i++)
	{
		_gameObjects[i]->draw();
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
	TheInputHandler::Instance()->clean();

	quit();
}

void Game::quit()
{
	SDL_DestroyWindow(_window);
	SDL_DestroyRenderer(_renderer);
	SDL_Quit();
}

void Game::handleEvents()
{
	TheInputHandler::Instance()->update();
}

SDL_Renderer * Game::getRenderer() const
{
	return _renderer;
}

Game * Game::Instance()
{
	if (_instance == 0)
	{
		_instance = new Game();
		return _instance;
	}

	return _instance;
}
