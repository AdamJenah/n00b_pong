#pragma once
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>

class InputHandler
{
public:
	InputHandler();

	void KeyboardHandler(UINT message, WPARAM wParam);
	void MouseHandler(UINT message, WPARAM wParam);
	

	~InputHandler();
};

