#include "WinState.h"
#include "Game.h"
#include "MenuState.h"
#include "PlayState.h"
#include "AnimatedGraphic.h"
#include "MenuButton.h"

WinState * WinState::_instance = nullptr;
const std::string WinState::_gameOverID = "GAMEOVER";

void WinState::update()
{
	for (int i = 0; i < _gameObjects.size(); i++)
		_gameObjects[i]->update();
}

void WinState::render()
{
	for (int i = 0; i < _gameObjects.size(); i++)
		_gameObjects[i]->draw();

	TextureManager::Instance()->draw("youWinText", 100, 50, 600, 200, Game::Instance()->getRenderer());
}

bool WinState::onEnter()
{
	if (!TheTextureManager::Instance()->load(
		"assets/youWin.png", "youWinText",
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

	SDLGameObject * button1 = new MenuButton(
		new LoaderParams(300, 250, 200, 80, "mainbutton"), _gameOverToMain);

	SDLGameObject * button2 = new MenuButton(
		new LoaderParams(300, 350, 200, 80, "restartbutton"), _restartPlay);

	_gameObjects.push_back(button1);
	_gameObjects.push_back(button2);

	return true;
}

bool WinState::onExit()
{
	return false;
}

std::string WinState::getStateID() const
{
	return _gameOverID;
}

WinState * WinState::Instance()
{
	if (!_instance)
		_instance = new WinState();
	return _instance;
}

void WinState::_gameOverToMain()
{
	TheGame::Instance()->getStateMachine()->changeState(new MenuState());
}

void WinState::_restartPlay()
{
	TheGame::Instance()->getStateMachine()->changeState(new PlayState());
}
