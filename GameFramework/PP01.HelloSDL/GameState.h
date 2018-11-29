#pragma once

#include "SDLGameObject.h"

#include <string>
#include <vector>

class GameState
{
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter() = 0;
	virtual bool onExit();

	virtual std::string getStateID() const = 0;

protected:
	std::vector<SDLGameObject*> _gameObjects;
};