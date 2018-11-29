#include "Game.h"
#include "Player.h"
#include "Enemy.h"
#include "MenuState.h"
#include "PlayState.h"

#include <iostream>
#include <SDL_image.h>
#include <stdio.h>

Game * Game::_instance = nullptr;

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

	_gameStateMachine = new GameStateMachine;
	_gameStateMachine->changeState(MenuState::Instance());
	return true;
}

void Game::update()
{
	_gameStateMachine->update();
}

void Game::render()
{
	SDL_RenderClear(_renderer);
	_gameStateMachine->render();
	SDL_RenderPresent(_renderer);
}

void Game::clean()
{
	TheInputHandler::Instance()->clean();

	quit();
}

void Game::quit()
{
	_running = false;
	SDL_DestroyWindow(_window);
	SDL_DestroyRenderer(_renderer);
	SDL_Quit();
}

void Game::handleEvents()
{
	TheInputHandler::Instance()->update();
	
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RETURN))
		_gameStateMachine->changeState(PlayState::Instance());
}

SDL_Renderer * Game::getRenderer() const
{
	return _renderer;
}

GameStateMachine * Game::getStateMachine() const
{
	return _gameStateMachine;
}

Game * Game::Instance()
{
	if (!_instance)
		_instance = new Game;

	return _instance;
}
