#include "Monster.h"

void Monster::load(int x, int y, int width, int height, std::string textureID)
{
	_directionLeft = false;
	_speed = y / 100;
	_moveLength = 0;

	GameObject::load(x, y, width, height, textureID);
}

void Monster::draw(SDL_Renderer * renderer)
{
	GameObject::draw(renderer);
}

void Monster::update()
{
	if (_moveLength >= 150)
		_directionLeft = true;

	if (_moveLength <= 0)
		_directionLeft = false;

	if (_directionLeft)
	{
		_x -= _speed;
		_moveLength -= _speed;
	}
	else
	{
		_x += _speed;
		_moveLength += _speed;
	}

	_currentFrame = int(((SDL_GetTicks() / 100) % 6));
}

void Monster::clean()
{
}
