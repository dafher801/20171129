#include "LoaderParams.h"

LoaderParams::LoaderParams(int x, int y, int width, int height, std::string textureID)
	: _x(x), _y(y), _width(width), _height(height), _textureID(textureID) {}

int LoaderParams::getX() const
{
	return _x;
}

int LoaderParams::getY() const
{
	return _y;
}

int LoaderParams::getWidth() const
{
	return _width;
}

int LoaderParams::getHeight() const
{
	return _height;
}

std::string LoaderParams::getTextureID() const
{
	return _textureID;
}
