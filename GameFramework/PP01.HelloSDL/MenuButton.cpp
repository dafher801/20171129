#include "MenuButton.h"
#include "InputHandler.h"

MenuButton::MenuButton(const LoaderParams * params, void(*callback)())
	: SDLGameObject(params), _callback(callback)
{
}

void MenuButton::update()
{
	Vector2D * mousePos = TheInputHandler::Instance()->getMousePosition();

	if (mousePos->getX() < (_position.getX() + _width) &&
		mousePos->getX() > _position.getX() &&
		mousePos->getY() < (_position.getY() + _height) &&
		mousePos->getY() > _position.getY())
	{
		if (TheInputHandler::Instance()->getMouseButtonState(LEFT)
			&& _released)
		{
			_currentFrame = CLICKED;
			_callback();
			_released = false;
		}
		else if (!TheInputHandler::Instance()->getMouseButtonState(LEFT))
		{
			_released = true;
			_currentFrame = MOUSE_OVER;
		}
	}
	else
	{
		_currentFrame = MOUSE_OUT;
	}
}

void MenuButton::draw()
{
	SDLGameObject::draw();
}

void MenuButton::clean()
{
	SDLGameObject::clean();
}
