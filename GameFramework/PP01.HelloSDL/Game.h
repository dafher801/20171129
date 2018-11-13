#pragma once

#include <vector>
#include <SDL.h>
#include "TextureManager.h"
#include "GameObject.h"
#include "InputHandler.h"

class Game
{
public:

	~Game() {}

	bool init(const char * title, int xpos, int ypos, int width, int height, bool fullscreen);
	void render();
	void update();
	void clean();
	void quit();
	bool running() { return _running; }

	void handleEvents();

	SDL_Renderer * getRenderer() const;

	static Game * Instance();

private:

	Game();

	SDL_Window * _window;
	SDL_Renderer * _renderer;
	bool _running;

	SDL_Texture * _texture;
	SDL_Rect _sourceRectangle;
	SDL_Rect _destinationRectangle;

	int _currentFrame;

	std::vector<GameObject*> _gameObjects;

	static Game * _instance;
};

typedef Game TheGame;