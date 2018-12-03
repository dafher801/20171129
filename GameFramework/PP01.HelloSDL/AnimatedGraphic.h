#pragma once

#include "SDLGameObject.h"
#include "LoaderParams.h"

class AnimatedGraphic : public SDLGameObject
{
public:
	AnimatedGraphic(const LoaderParams * params, int animSpeed);

	virtual void update();

private:
	int _animSpeed;
};