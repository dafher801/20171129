#include "PlayState.h"

PlayState * PlayState::_instance = nullptr;
const std::string PlayState::_playID = "PLAY";

PlayState * PlayState::Instance()
{
	if (!_instance)
		_instance = new PlayState;

	return _instance;
}

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
