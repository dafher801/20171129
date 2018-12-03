#pragma once

#include "GameState.h"
#include "SDLGameObject.h"

class GameOverState : public GameState
{
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateID() const;

private:
	static void _gameOverToMain();
	static void _restartPlay();
	static const std::string _gameOverID;
	std::vector<SDLGameObject*> _gameObjects;
};