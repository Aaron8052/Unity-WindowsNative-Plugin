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

bool WindowsNative::Desktop::ShowDialog(const wchar_t* title, const wchar_t* message, IconType iconType)
{
    long icon = 0L;
    switch (iconType)
    {
    case Hand:
        icon = MB_ICONHAND | MB_YESNO;
        break;
    case Question:
        icon = MB_ICONQUESTION | MB_YESNO;
        break;
    case Exclamation:
        icon = MB_ICONEXCLAMATION | MB_YESNO;
        break;
    case Asterisk:
        icon = MB_ICONASTERISK | MB_YESNO;
        break;
    case Warning:
        icon = MB_ICONWARNING | MB_YESNO;
        break;
    case Information:
        icon = MB_ICONINFORMATION | MB_YESNO;
        break;
    case Error:
        icon = MB_ICONERROR | MB_YESNO;
        break;
    case Stop:
        icon = MB_ICONSTOP | MB_YESNO;
        break;
    default:
        icon = MB_YESNO;
        break;
    }

    int msgboxID = MessageBox(
        GetForegroundWindow(),
        message,
        title,
        icon | MB_TOPMOST
    );

    if (msgboxID == IDYES)
    {
        return true;
    }

    return false;
}
