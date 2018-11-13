#pragma once

#include <iostream>
#include <map>
#include <SDL.h>
#include <SDL_image.h>

class TextureManager
{
public:
	bool load(std::string fileName, std::string id, SDL_Renderer * renderer);

	void draw(std::string id, int x, int y, int width, int height,
		SDL_Renderer * renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

	void drawFrame(std::string id, int x, int y, int width, int height,
		int currentRow, int currentFrame, SDL_Renderer * renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

private:
	std::map<std::string, SDL_Texture*> _textureMap;
};

