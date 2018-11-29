#pragma once

#include <SDL.h>
#include <vector>
#include "Vector2D.h"

enum mouse_buttons
{
	LEFT = 0,
	MIDDLE = 1,
	RIGHT = 2
};

class InputHandler
{
public:
	static InputHandler * Instance();
	void update();
	void clean();

	bool isKeyDown(SDL_Scancode key);

	bool getMouseButtonState(int buttonNumber);

	Vector2D * getMousePosition();

	void onKeyDown(SDL_Event event);
	void onKeyUp(SDL_Event event);
	void onMouseMove(SDL_Event event);
	void onMouseButtonDown(SDL_Event event);
	void onMouseButtonUp(SDL_Event event);

	void reset();

private:
	InputHandler();
	~InputHandler() {}

	static InputHandler * _instance;

	const Uint8 * _keyStates;

	std::vector<bool> m_mouseButtonStates;

	Vector2D * m_mousePosition;
};

typedef InputHandler TheInputHandler;