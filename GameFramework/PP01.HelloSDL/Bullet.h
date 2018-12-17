#pragma once

#include "SDLGameObject.h"

class Bullet : public SDLGameObject
{
public:
	Bullet(const LoaderParams * params, Vector2D velocity);

	virtual void update();
	virtual void draw();

private:
};