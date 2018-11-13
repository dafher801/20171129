#include "Player.h"

void Player::draw()
{
	SDLGameObject::draw();
}

Player::Player(const LoaderParams * params)
	: SDLGameObject(params) {}

void Player::update()
{
	_currentFrame = int(((SDL_GetTicks() / 100) % 6));
	_acceleration.setX(1);
	SDLGameObject::update();
}

void Player::clean()
{
}
