#include "SDLGameObject.h"
#include "TextureManager.h"
#include "Game.h"

SDLGameObject::SDLGameObject(const LoaderParams * params)
	: GameObject(params)
{
	_x = params->getX();
	_y = params->getY();
	_width = params->getWidth();
	_height = params->getHeight();

	_textureID = params->getTextureID();
	_currentRow = 1;
	_currentFrame = 1;

}

void SDLGameObject::draw()
{
	TextureManager::Instance()->drawFrame(_textureID, _x, _y,
		_width, _height, _currentRow, _currentFrame, TheGame::Instance()->getRenderer());

}

void SDLGameObject::update()
{
}

void SDLGameObject::clean()
{
}
