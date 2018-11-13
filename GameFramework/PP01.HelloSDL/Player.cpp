#include "Player.h"

void Player::draw()
{
	SDLGameObject::draw();
}

Player::Player(const LoaderParams * params)
	: SDLGameObject(params) {}

void Player::update()
{
	_x--;
	_currentFrame = int(((SDL_GetTicks() / 100) % 6));
}

void Player::clean()
{
}
