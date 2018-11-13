#include "TextureManager.h"

bool TextureManager::load(std::string fileName, std::string id, SDL_Renderer * renderer)
{
	SDL_Surface * tempSurface = IMG_Load(fileName.c_str());

	if (tempSurface == 0)
		return false;

	SDL_Texture * texture =
		SDL_CreateTextureFromSurface(renderer, tempSurface);
	SDL_FreeSurface(tempSurface);

	if (texture != nullptr)
	{
		_textureMap[id] = texture;
		return false;
	}

	return true;
}

void TextureManager::draw(std::string id, int x, int y, int width, int height,
	SDL_Renderer * renderer, SDL_RendererFlip flip)
{
	SDL_Rect srcRect;
	SDL_Rect destRect;

	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;
	destRect.x = x;
	destRect.y = y;

	SDL_RenderCopyEx(renderer, _textureMap[id], &srcRect, &destRect, 0, 0, flip);
}

void TextureManager::drawFrame(std::string id, int x, int y, int width, int height,
	int currentRow, int currentFrame, SDL_Renderer * renderer, SDL_RendererFlip flip)
{
	SDL_Rect srcRect;
	SDL_Rect destRect;
	srcRect.x = width * currentFrame;
	srcRect.y = height * (currentRow - 1);
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;
	destRect.x = x;
	destRect.y = y;

	SDL_RenderCopyEx(renderer, _textureMap[id], &srcRect,
		&destRect, 0, 0, flip);

}