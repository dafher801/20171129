#include "SDLGameObject.h"
#include "TextureManager.h"
#include "Game.h"

SDLGameObject::SDLGameObject(const LoaderParams * params)
	: GameObject(params)
	, _position(params->getX(), params->getY())
	, _velocity(0.0f, 0.0f)
	, _acceleration(0.0f, 0.0f)
{
	_width = params->getWidth();
	_height = params->getHeight();

	_textureID = params->getTextureID();
	_currentRow = 1;
	_currentFrame = 1;
}

void SDLGameObject::draw()
{
	TextureManager::Instance()->drawFrame(_textureID, (int)_position.getX(),
		(int)_position.getY(), _width, _height, _currentRow, _currentFrame, TheGame::Instance()->getRenderer());

}

void SDLGameObject::update()
{
	_velocity += _acceleration;
	_position += _velocity;
}

void SDLGameObject::clean()
{
}
