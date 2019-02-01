#pragma once
#include "NoobClass.h"

class InputHandler
{
public:
	InputHandler();

	void KeyboardHandler(UINT message, WPARAM wParam);
	void MouseHandler(UINT message, WPARAM wParam);
	

	~InputHandler();
};

