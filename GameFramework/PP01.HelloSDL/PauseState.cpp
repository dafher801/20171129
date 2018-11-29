#include "PauseState.h"
#include "Game.h"
#include "MenuState.h"
#include "MenuButton.h"

const std::string PauseState::_pauseID = "PAUSE";

PauseState * PauseState::Instance()
{
	if (!_instance)
		_instance = new PauseState;

	return _instance;
}

void PauseState::update()
{
	GameState::update();
}

void PauseState::render()
{
	GameState::render();
}

bool PauseState::onEnter()
{
	if (!TheTextureManager::Instance()->load("assets/resume.png",
		"resumebutton", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("assets/main.png",
		"mainbutton", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	SDLGameObject * button1 = new MenuButton(new LoaderParams(200, 100, 200, 80, "mainbutton"), _pauseToMain);
	SDLGameObject * button2 = new MenuButton(new LoaderParams(200, 300, 200, 80, "resumebutton"), _resumePlay);

	_gameObjects.push_back(button1);
	_gameObjects.push_back(button2);
	return true;
}

bool PauseState::onExit()
{
	GameState::onExit();

	TheTextureManager::Instance()->clearFromTextureMap("resumebutton");
	TheTextureManager::Instance()->clearFromTextureMap("mainbutton");

	TheInputHandler::Instance()->reset();
	return true;
}

std::string PauseState::getStateID() const
{
	return std::string();
}

void PauseState::_pauseToMain()
{
	TheGame::Instance()->getStateMachine()->changeState(new MenuState());
}

void PauseState::_resumePlay()
{
	TheGame::Instance()->getStateMachine()->popState();
}
