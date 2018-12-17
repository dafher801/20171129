#pragma once

#include "GameState.h"
#include "SDLGameObject.h"

class WinState : public GameState
{
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateID() const;

	static WinState * Instance();

private:
	WinState() {}

	static void _gameOverToMain();
	static void _restartPlay();
	static const std::string _gameOverID;

	std::vector<SDLGameObject*> _gameObjects;
	static WinState * _instance;
};