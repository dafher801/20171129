#pragma once

#include <iostream>

class LoaderParams
{
public:
	LoaderParams(int x, int y, int width, int height, std::string textureID);
	int getX() const;
	int getY() const;
	int getWidth() const;
	int getHeight() const;
	std::string getTextureID() const;
private:
	int _x;
	int _y;
	int _width;
	int _height;
	std::string _textureID;
};