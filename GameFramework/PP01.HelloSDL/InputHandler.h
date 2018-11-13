#pragma once

#include <SDL.h>

class InputHandler
{
public:
	static InputHandler * Instance();
	void update();
	void clean();

	bool isKeyDown(SDL_Scancode key);

private:
	InputHandler() {}
	~InputHandler() {}

	static InputHandler * _instance;

	const Uint8 * _keyStates;
};

typedef InputHandler TheInputHandler;