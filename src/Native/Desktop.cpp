#include "Desktop.h"
HWND WindowsNative::Desktop::GetWindow()
{
    HWND hwnd = FindWindowA("UnityWndClass", NULL);
    return hwnd;
}

void WindowsNative::Desktop::GetWindowPosition(int* x, int* y, int* width, int* height)
{
    HWND hwnd = GetWindow();
    RECT rect;
    GetWindowRect(hwnd, &rect);

    *x = rect.left;
    *y = rect.top;
    *width = rect.right - rect.left;
    *height = rect.bottom - rect.top;
}

void WindowsNative::Desktop::SetWindowPosition(int x, int y)
{
}

wchar_t* titleArr;
const wchar_t* WindowsNative::Desktop::GetWindowTitle()
{
    ReleaseWindowTitlePtr();
    HWND hwnd = GetWindow();
    int length = GetWindowTextLengthW(hwnd) + 1; // 多出来的位置给\0
    titleArr = new wchar_t[length];
    GetWindowTextW(hwnd, titleArr, length);
    return titleArr;
}

void WindowsNative::Desktop::SetWindowTitle(const wchar_t* title)
{
    HWND hwnd = GetWindow();
    SetWindowTextW(hwnd, title);
}

void WindowsNative::Desktop::ReleaseWindowTitlePtr()
{
    if (titleArr == nullptr)
        return;
    delete[] titleArr;
}


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
