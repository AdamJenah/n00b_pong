#include "stdafx.h"
#include "InputHandler.h"


InputHandler::InputHandler()
{
}

void InputHandler::KeyboardHandler(UINT message, WPARAM wParam)
{
	wchar_t msg[32];
	switch (message)
	{
	case WM_SYSKEYDOWN:
		swprintf_s(msg, L"WM_SYSKEYDOWN: 0x%x\n", wParam);
		OutputDebugString((LPCSTR)msg);
		break;

	case WM_SYSCHAR:
		swprintf_s(msg, L"WM_SYSCHAR: %c\n", (wchar_t)wParam);
		OutputDebugString((LPCSTR)msg);
		break;

	case WM_SYSKEYUP:
		swprintf_s(msg, L"WM_SYSKEYUP: 0x%x\n", wParam);
		OutputDebugString((LPCSTR)msg);
		break;

	case WM_KEYDOWN:
		swprintf_s(msg, L"WM_KEYDOWN: 0x%x\n", wParam);
		OutputDebugString((LPCSTR)msg);
		break;

	case WM_KEYUP:
		swprintf_s(msg, L"WM_KEYUP: 0x%x\n", wParam);
		OutputDebugString((LPCSTR)msg);
		break;

	case WM_CHAR:
		swprintf_s(msg, L"WM_CHAR: %c\n", (wchar_t)wParam);
		OutputDebugString((LPCSTR)msg);
		break;

	}



}

void InputHandler::MouseHandler(UINT message, WPARAM wParam)
{
	wchar_t msg[38];
	switch (message)
	{
	case WM_LBUTTONDOWN:
		swprintf_s(msg, L"WM_LBUTTONDOWN: Left Mouse Down\n", wParam);
		OutputDebugString((LPCSTR)msg);
		break;

	case WM_LBUTTONUP:
		swprintf_s(msg, L"WM_LBUTTONDOWN: Left Mouse Up\n", wParam);
		OutputDebugString((LPCSTR)msg);
		break;

	case WM_MBUTTONDOWN:
		swprintf_s(msg, L"WM_LBUTTONDOWN: Middle Mouse Down\n", wParam);
		OutputDebugString((LPCSTR)msg);
		break;

	case WM_MBUTTONUP:
		swprintf_s(msg, L"WM_LBUTTONDOWN: Middle Mouse Up\n", wParam);
		OutputDebugString((LPCSTR)msg);
		break;

	case WM_RBUTTONDOWN:
		swprintf_s(msg, L"WM_LBUTTONDOWN: Right Mouse Down\n", wParam);
		OutputDebugString((LPCSTR)msg);
		break;

	case WM_RBUTTONUP:
		swprintf_s(msg, L"WM_LBUTTONDOWN: Right Mouse Up\n", wParam);
		OutputDebugString((LPCSTR)msg);
		break;

	}
}

InputHandler::~InputHandler()
{
}
