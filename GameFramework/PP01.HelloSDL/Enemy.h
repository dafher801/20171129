#pragma once

#include <iostream>
#include <SDL.h>
#include "SDLGameObject.h"

class Enemy : public SDLGameObject
{
public:
	Enemy(const LoaderParams * params);

	void draw();
	void update();
	void clean();
};