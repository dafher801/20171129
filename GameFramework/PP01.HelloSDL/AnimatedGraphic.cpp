#include "AnimatedGraphic.h"

AnimatedGraphic::AnimatedGraphic(const LoaderParams * params, int animSpeed)
	: SDLGameObject(params)
	, _animSpeed(animSpeed) {}

void AnimatedGraphic::update()
{
	_currentFrame = int(((SDL_GetTicks() / (1000 / _animSpeed)) % _numFrames));
}
