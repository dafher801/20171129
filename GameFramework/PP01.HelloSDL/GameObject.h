#pragma once

#include <iostream>
#include <SDL.h>

class GameObject
{
public:
	virtual void load(int x, int y, int width, int height, std::string textureID);
	virtual void draw(SDL_Renderer * renderer);
	virtual void update();
	virtual void clean();

protected:
	std::string _textureID;
	int _currentFrame;
	int _currentRow;
	int _x;
	int _y;
	int _width;
	int _height;
};