#include "InputHandler.h"

InputHandler::InputHandler()
{
}

InputHandler::~InputHandler()
{
}

void InputHandler::handlePlayerInput(sf::Keyboard::Key key, bool isPressed) {

	if (isPressed)//For when pressed
	{
		//if (key == sf::Keyboard::A) mIsMovingLeft = true;
		//else if (key == sf::Keyboard::D) mIsMovingRight = true;
	}

	if (!isPressed)//For when not pressed
	{
		//if (key == sf::Keyboard::A) mIsMovingLeft = false;
		//else if (key == sf::Keyboard::D) mIsMovingRight = false;
	}
}
