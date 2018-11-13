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
	_y++;
	_x++;
	_currentFrame = int(((SDL_GetTicks() / 100) % 6));
}

void Enemy::clean()
{
}
