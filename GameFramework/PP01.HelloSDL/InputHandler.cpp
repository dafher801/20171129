#include "InputHandler.h"
#include "Game.h"

InputHandler * InputHandler::_instance = 0;

InputHandler * InputHandler::Instance()
{
	if (!_instance)
		_instance = new InputHandler;

	return _instance;
}

void InputHandler::update()
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			TheGame::Instance()->quit();
			break;
		case SDL_KEYUP:
			_keyStates = SDL_GetKeyboardState(0);
			break;
		case SDL_KEYDOWN:
			_keyStates = SDL_GetKeyboardState(0);
			break;
		}
	}
}

void InputHandler::clean()
{
}

bool InputHandler::isKeyDown(SDL_Scancode key)
{
	if (_keyStates && _keyStates[key] == 1)
		return true;

	return false;
}
