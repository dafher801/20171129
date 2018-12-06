#include "GameOverState.h"
#include "Game.h"
#include "MenuState.h"
#include "PlayState.h"
#include "AnimatedGraphic.h"
#include "MenuButton.h"

GameOverState * GameOverState::_instance = nullptr;
const std::string GameOverState::_gameOverID = "GAMEOVER";

void GameOverState::update()
{
	for (int i = 0; i < _gameObjects.size(); i++)
		_gameObjects[i]->update();
}

void GameOverState::render()
{
	for (int i = 0; i < _gameObjects.size(); i++)
		_gameObjects[i]->draw();
}

bool GameOverState::onEnter()
{
	if (!TheTextureManager::Instance()->load(
		"assets/gameover.png", "gameovertext",
		TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load(
		"assets/main.png", "mainbutton",
		TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load(
		"assets/restart.png", "restartbutton",
		TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	SDLGameObject * gameOverText = new AnimatedGraphic(
		new LoaderParams(200, 100, 190, 30, "gameovertext"), 2);

	SDLGameObject * button1 = new MenuButton(
		new LoaderParams(200, 200, 200, 80, "mainbutton"), _gameOverToMain);

	SDLGameObject * button2 = new MenuButton(
		new LoaderParams(200, 300, 200, 80, "restartbutton"), _restartPlay);

	_gameObjects.push_back(gameOverText);
	_gameObjects.push_back(button1);
	_gameObjects.push_back(button2);

	return true;
}

bool GameOverState::onExit()
{
	return false;
}

std::string GameOverState::getStateID() const
{
	return _gameOverID;
}

GameOverState * GameOverState::Instance()
{
	if (!_instance)
		_instance = new GameOverState();
	return _instance;
}

void GameOverState::_gameOverToMain()
{
	TheGame::Instance()->getStateMachine()->changeState(new MenuState());
}

void GameOverState::_restartPlay()
{
	TheGame::Instance()->getStateMachine()->changeState(new PlayState());
}
