#include "Enemy.h"

Enemy::Enemy(const LoaderParams * params)
	: SDLGameObject(params)
{
	_velocity.setY(2);
	_velocity.setX(0.001);
}

void Enemy::draw()
{
	SDLGameObject::draw();
}

void Enemy::update()
{
	_currentFrame = int(((SDL_GetTicks() / 100) % 5));

	if (_position.getX() < 0)
		_velocity.setY(2);
	else if (_position.getY() > 400)
		_velocity.setY(-2);

	SDLGameObject::update();
}

void Enemy::clean()
{
}
