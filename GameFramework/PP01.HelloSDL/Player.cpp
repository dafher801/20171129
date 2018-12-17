#include "Player.h"
#include "Vector2D.h"
#include "InputHandler.h"
#include "BulletManager.h"
#include "PlayState.h"
#include "Game.h"
#include "GameOverState.h"

#define TICK 200

void Player::draw()
{
	TextureManager::Instance()->draw(_textureID, (int)_position.getX(),
		(int)_position.getY(), _width, _height, TheGame::Instance()->getRenderer());
}

Player::Player(const LoaderParams * params)
	: SDLGameObject(params)
	, _HP(5) {}

void Player::update()
{
	handleInput();
	SDLGameObject::update();

	static Uint32 next_time = 0;
	Uint32 now;

	now = SDL_GetTicks();

	if (next_time <= now)
	{
		next_time = now + TICK;
		BulletManager::Instance()->shootBullet(new Bullet(
			new LoaderParams(_position.getX(), 500, 50, 50, "PlayerBullet"), Vector2D(0, -10)));
	}

	for (Bullet * iter : BulletManager::Instance()->getBullets())
	{
		if (PlayState::Instance()->checkCollision(this, iter))
		{
			_HP--;
			BulletManager::Instance()->deleteBullet(iter);

			if (_HP <= 0)
				TheGame::Instance()->getStateMachine()->changeState(GameOverState::Instance());
		}
	}
}

void Player::clean()
{
}

int Player::getHP() const
{
	return _HP;
}

void Player::handleInput()
{
	Vector2D * target = TheInputHandler::Instance()->getMousePosition();

	if (target->getX() < 0)
		_position.setX(0);

	_position.setX(target->getX());

	if (_position.getX() > 700)
		_position.setX(700);
}
