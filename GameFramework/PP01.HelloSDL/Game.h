#pragma once

#include <vector>
#include <SDL.h>
#include "TextureManager.h"
#include "GameObject.h"
#include "Monster.h"

#define MONSTER_NUM 2

class Game
{
public:
	Game() :_running(true) {}
	~Game() {}

	bool init(const char * title, int xpos, int ypos, int width, int height, bool fullscreen);
	void render();
	void update();
	void clean();
	bool running() { return _running; }

	void handleEvents();

private:
	SDL_Window * _window;
	SDL_Renderer * _renderer;
	bool _running;

	SDL_Texture * _texture;
	SDL_Rect _sourceRectangle;
	SDL_Rect _destinationRectangle;

	int _currentFrame;

	GameObject * _monsters[MONSTER_NUM];
	std::vector<GameObject*> _gameObjects;
};
