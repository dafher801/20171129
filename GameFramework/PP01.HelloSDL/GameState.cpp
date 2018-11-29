#include "GameState.h"

void GameState::update()
{
	for (int i = 0; i < _gameObjects.size(); i++)
		_gameObjects[i]->update();
}

void GameState::render()
{
	for (int i = 0; i < _gameObjects.size(); i++)
		_gameObjects[i]->draw();
}

bool GameState::onExit()
{
	for (int i = 0; i < _gameObjects.size(); i++)
		_gameObjects[i]->clean();

	_gameObjects.clear();
	return true;
}
