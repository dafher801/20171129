#include "Enemy.h"

Enemy::Enemy(const LoaderParams * params)
	: SDLGameObject(params)
{
}

void Enemy::draw()
{
	SDLGameObject::draw();
}

void Enemy::update()
{
	_position.setX(_position.getX() + 1);
	_position.setY(_position.getY() + 1);

	_currentFrame = int(((SDL_GetTicks() / 100) % 6));
}

void Enemy::clean()
{
}
