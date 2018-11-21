#pragma once

#include "GameState.h"

class PlayState : public GameState
{
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const;

private:
	static const std::string _playID;
	static PlayState * _instance;
};