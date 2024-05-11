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



bool WindowsNative::Desktop::ShowDialog(const wchar_t* title, const wchar_t* message, IconType iconType, ButtonType buttonType)
{
    long button = 0L;
    switch (buttonType)
    {
        case WindowsNative::YesNo:
            button = MB_YESNO;
            break;
        
        case WindowsNative::OkCancel:
            button = MB_OKCANCEL;
            break;

        default:
        case WindowsNative::Ok:
            button = MB_OK;
            break;
    }

    long icon = 0L;
    switch (iconType)
    {
        case Hand:
            icon = MB_ICONHAND;
            break;
        case Question:
            icon = MB_ICONQUESTION;
            break;
        case Exclamation:
            icon = MB_ICONEXCLAMATION;
            break;
        case Asterisk:
            icon = MB_ICONASTERISK;
            break;
        case Information:
            icon = MB_ICONINFORMATION;
            break;
        case Error:
            icon = MB_ICONERROR;
            break;
        case Stop:
            icon = MB_ICONSTOP;
            break;

        default:
        case Warning:
            icon = MB_ICONWARNING;
            break;
    }

    long defaultButton = button == MB_OK ? MB_DEFBUTTON1 : MB_DEFBUTTON2;
    HWND window = GetWindow(); //GetForegroundWindow()
    int msgboxID = MessageBox(NULL, message, title, icon | button | defaultButton | MB_TOPMOST); //第一个参数不要填入window，否则一旦玩家没有对对话框做出回应，直接返回游戏窗口后则无法再点击对话框
    SetForegroundWindow(window); // 将游戏窗口带回到前台
    return msgboxID == IDYES;
}
