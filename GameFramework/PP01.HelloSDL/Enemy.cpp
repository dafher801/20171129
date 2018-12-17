#include "Enemy.h"
#include "Game.h"
#include "TextureManager.h"
#include "BulletManager.h"
#include "PlayState.h"
#include "WinState.h"

#include <random>
#include <ctime>

#define TICK 200

Enemy::Enemy(const LoaderParams * params)
	: SDLGameObject(params)
{
	srand((int)time(nullptr));
	_velocity.setX(2);
	_HP = 100;
}

void Enemy::draw()
{
	SDLGameObject::draw();
}

void Enemy::update()
{
	_currentFrame = int(((SDL_GetTicks() / 100) % 5));

	if (_position.getX() < 0)
		_velocity.setX(2);
	else if (_position.getX() > 690)
		_velocity.setX(-2);

	SDLGameObject::update();

	static Uint32 next_time = 0;
	Uint32 now;

	int x = rand() % 800;

	int direction = 1;

	if (rand() % 2)
		direction *= -1;

	now = SDL_GetTicks();

	if (next_time <= now)
	{
		next_time = now + TICK;

		BulletManager::Instance()->shootBullet(new Bullet(
			new LoaderParams(rand() % 800, 50, 50, 50, "PlayerBullet"),
			Vector2D((rand() % 10 + 1) * direction, rand() % 10 + 1)));
	}

	for (Bullet * iter : BulletManager::Instance()->getBullets())
	{
		if (PlayState::Instance()->checkCollision(this, iter))
		{
			_HP--;
			BulletManager::Instance()->deleteBullet(iter);

			if (_HP <= 0)
				TheGame::Instance()->getStateMachine()->changeState(WinState::Instance());
		}
	}
}

void Enemy::clean()
{
}
