#pragma once
#include <SDL.h>

class Game
{
public:
	Game() {}
	~Game() {}

	bool init(const char * title, int xpos, int ypos, int width, int height, bool fullscreen);
	void render();
	void update();
	void clean();
	bool running() { return true; }

	void handleEvents();

private:
	SDL_Window * _window;
	SDL_Renderer * _renderer;
	bool _running;

	SDL_Texture * _texture;
	SDL_Rect _sourceRectangle;
	SDL_Rect _destinationRectangle;
};
