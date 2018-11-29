#pragma once

#include "SDLGameObject.h"

enum button_state
{
	MOUSE_OUT = 0,
	MOUSE_OVER = 1,
	CLICKED = 2
};

class MenuButton : public SDLGameObject
{
public:
	MenuButton(const LoaderParams * params, void(*callback)());

	virtual void update();
	virtual void draw();
	virtual void clean();

private:
	bool _released;
	void(*_callback)();
};