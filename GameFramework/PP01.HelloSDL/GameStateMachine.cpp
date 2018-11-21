#include "GameStateMachine.h"

void GameStateMachine::update()
{
	if (_currentState)
		_currentState->update();
}

void GameStateMachine::render()
{
	if (_currentState)
		_currentState->render();
}

void GameStateMachine::pushState(GameState * state)
{
	_gameStates.push_back(state);
	_gameStates.back()->onEnter();
}

void GameStateMachine::popState()
{
	changeState(_prevState);
}

void GameStateMachine::changeState(GameState * state)
{
	if (state)
	{
		if (_currentState)
		{
			_prevState = _currentState;
			_currentState->onExit();
		}

		_currentState = state;
		_currentState->onEnter();
	}
}
