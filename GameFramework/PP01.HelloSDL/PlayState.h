#pragma once

#include "GameState.h"

class PlayState : public GameState
{
public:
	static PlayState * Instance();

	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateID() const;

private:
	static PlayState * _instance;
	static const std::string _playID;
};