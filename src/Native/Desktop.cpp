#include "Desktop.h"

void WindowsNative::Desktop::SetCursorPosition(int pixelX, int pixelY)
{
	SetCursorPos(pixelX, pixelY);
}

void WindowsNative::Desktop::GetCursorPosition(int* pixelX, int* pixelY)
{
	POINT cursorPos;
	GetCursorPos(&cursorPos);
	*pixelX = cursorPos.x;
	*pixelY = cursorPos.y;
}
