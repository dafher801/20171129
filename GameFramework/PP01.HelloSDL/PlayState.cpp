#include "PlayState.h"
#include "TextureManager.h"
#include "Game.h"
#include "Player.h"
#include "PauseState.h"

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
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		TheGame::Instance()->getStateMachine()->pushState(PauseState::Instance());
	}

	GameState::update();
}

void PlayState::render()
{
	GameState::render();
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
	GameState::onExit();

	TheTextureManager::Instance()->clearFromTextureMap("helicopter");
	return true;
}

std::string PlayState::getStateID() const
{
	return _playID;
}
