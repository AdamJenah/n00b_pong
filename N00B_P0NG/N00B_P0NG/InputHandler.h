#pragma once
#include "NoobClass.h"

class InputHandler
{
public:
	InputHandler();
	~InputHandler();

	void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
};

