#include "PlayState.h"

void PlayState::update()
{
}

void PlayState::render()
{
}

bool PlayState::onEnter()
{
	std::cout << "entering PlayState" << std::endl;
	return true;
}

bool PlayState::onExit()
{
	std::cout << "exiting PlayState" << std::endl;
	return true;
}

std::string PlayState::getStateID() const
{
	return _playID;
}
