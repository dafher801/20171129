#include "PlayState.h"
#include "TextureManager.h"
#include "Game.h"
#include "Player.h"

PlayState * PlayState::_instance = nullptr;
const std::string PlayState::_playID = "PLAY";

PlayState * PlayState::Instance()
{
	if (!_instance)
		_instance = new PlayState;

	return _instance;
}

void PlayState::update()
{
	for (int i = 0; i < _gameObjects.size(); i++)
		_gameObjects[i]->update();
}

void PlayState::render()
{
	for(int i =0; i < _gameObjects.size(); i++)
		_gameObjects[i]->draw();
}

bool PlayState::onEnter()
{
	if (!TheTextureManager::Instance()->load(
		"assets/helicopter.png", "helicopter",
		TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	SDLGameObject * player = new Player(new LoaderParams(100, 100, 128, 55, "helicopter"));
	_gameObjects.push_back(player);

	return true;
}

bool PlayState::onExit()
{
	for (int i = 0; i < _gameObjects.size(); i++)
		_gameObjects[i]->clean();

	_gameObjects.clear();

	TheTextureManager::Instance()->clearFromTextureMap("helicopter");
	return true;
}

std::string PlayState::getStateID() const
{
	return _playID;
}
