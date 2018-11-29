#pragma once

#include "GameState.h"

class MenuState : public GameState
{
public:
	static MenuState * Instance();

	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateID() const;

	static void _menuToPlay();
	static void _exitFromMenu();

private:
	static const std::string _menuID;
	static MenuState * _instance;
};