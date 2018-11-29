#pragma once

#include "SDLGameObject.h"

#include <vector>

class PauseState : public GameState
{
public:
	static PauseState * Instance();

	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateID() const;

private:
	static void _pauseToMain();
	static void _resumePlay();

	static PauseState * _instance;
	static const std::string _pauseID;
};