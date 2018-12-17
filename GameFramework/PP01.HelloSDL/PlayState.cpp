#include "PlayState.h"
#include "TextureManager.h"
#include "Game.h"
#include "Player.h"
#include "Enemy.h"
#include "PauseState.h"
#include "GameOverState.h"
#include "BulletManager.h"

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
		TheGame::Instance()->getStateMachine()->changeState(PauseState::Instance());
	}

	for (int i = 0; i < _gameObjects.size(); i++)
		_gameObjects[i]->update();

	BulletManager::Instance()->update();
}

void PlayState::render()
{
	for (int i = 0; i < _gameObjects.size(); i++)
		_gameObjects[i]->draw();

	BulletManager::Instance()->draw();
}

bool PlayState::onEnter()
{
	if (!TheTextureManager::Instance()->load(
		"assets/plate.png", "plate", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load(
		"assets/helicopter.png", "helicopter", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load(
		"assets/PlayerBullet.png", "PlayerBullet", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	SDLGameObject * player = new Player(new LoaderParams(500, 550, 128, 55, "plate"));
	_gameObjects.push_back(player);

	SDLGameObject * enemy = new Enemy(new LoaderParams(500, 0, 128, 55, "helicopter"));
	_gameObjects.push_back(enemy);

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

bool PlayState::checkCollision(SDLGameObject * p1, SDLGameObject * p2)
{
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	leftA = p1->getPosition().getX();
	rightA = p1->getPosition().getX() + p1->getWidth();
	topA = p1->getPosition().getY();
	bottomA = p1->getPosition().getY() + p1->getHeight();

	leftB = p2->getPosition().getX();
	rightB = p2->getPosition().getX() + p2->getWidth();
	topB = p2->getPosition().getY();
	bottomB = p2->getPosition().getY() + p2->getHeight();

	if (bottomA <= topB)
		return false;

	if (topA >= bottomB)
		return false;

	if (rightA <= leftB)
		return false;

	if (leftA >= rightB)
		return false;

	return true;
}
