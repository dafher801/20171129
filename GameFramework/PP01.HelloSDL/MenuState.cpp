#include "MenuState.h"
#include "TextureManager.h"
#include "Game.h"
#include "MenuButton.h"
#include "PlayState.h"

MenuState * MenuState::_instance = nullptr;
const std::string MenuState::_menuID = "MENU";

MenuState * MenuState::Instance()
{
	if (!_instance)
		_instance = new MenuState;

	return _instance;
}

void MenuState::update()
{
	for (int i = 0; i < _gameObjects.size(); i++)
		_gameObjects[i]->update();
}

void MenuState::render()
{
	for (int i = 0; i < _gameObjects.size(); i++)
		_gameObjects[i]->draw();
}

bool MenuState::onEnter()
{
	if (!TheTextureManager::Instance()->load("assets/button.png",
		"playbutton", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("assets/exit.png",
		"exitbutton", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	SDLGameObject * button1 = new MenuButton(
		new LoaderParams(100, 100, 400, 100, "playbutton"), _menuToPlay);
	SDLGameObject * button2 = new MenuButton(
		new LoaderParams(100, 300, 400, 100, "exitbutton"), _exitFromMenu);

	_gameObjects.push_back(button1);
	_gameObjects.push_back(button2);
	return true;
}

bool MenuState::onExit()
{
	for (int i = 0; i < _gameObjects.size(); i++)
		_gameObjects[i]->clean();

	_gameObjects.clear();

	TheTextureManager::Instance()->clearFromTextureMap("playbutton");
	TheTextureManager::Instance()->clearFromTextureMap("exitbutton");
	return true;
}

std::string MenuState::getStateID() const
{
	return _menuID;
}

void MenuState::_menuToPlay()
{
	TheGame::Instance()->getStateMachine()->changeState(new PlayState());
}

void MenuState::_exitFromMenu()
{
	TheGame::Instance()->quit();
}
