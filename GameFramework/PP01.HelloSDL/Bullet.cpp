#include "Bullet.h"

Bullet::Bullet(const LoaderParams * params, Vector2D velocity)
	: SDLGameObject(params)
{
	_velocity = velocity;
}

void Bullet::update()
{
	SDLGameObject::update();
}

void Bullet::draw()
{
	SDLGameObject::draw();
}
