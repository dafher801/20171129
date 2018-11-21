#pragma once

#include "GameState.h"

class GameStateMachine
{
public:
	void update();
	void render();

	void pushState(GameState * state);
	void popState();

	void changeState(GameState * state);

private:
	std::vector<GameState*> _gameStates;

	GameState * _currentState;
	GameState * _prevState;
};