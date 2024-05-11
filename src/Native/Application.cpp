#include "Application.h"


HWND WindowsNative::Application::GetWindow()
{
    HWND hwnd = FindWindowA("UnityWndClass", NULL);
    return hwnd;
}

void WindowsNative::Application::GetWindowPosition(int* x, int* y, int* width, int* height)
{
    HWND hwnd = GetWindow();
    RECT rect;
    GetWindowRect(hwnd, &rect);

    *x = rect.left;
    *y = rect.top;
    *width = rect.right - rect.left;
    *height = rect.bottom - rect.top;
}

void WindowsNative::Application::SetWindowPosition(int x, int y)
{
}

wchar_t* titleArr;
const wchar_t* WindowsNative::Application::GetWindowTitle()
{
    ReleaseWindowTitlePtr();
    HWND hwnd = GetWindow();
    int length = GetWindowTextLengthW(hwnd) + 1; // 多出来的位置给\0
    titleArr = new wchar_t[length];
    GetWindowTextW(hwnd, titleArr, length);
    return titleArr;
}

void WindowsNative::Application::SetWindowTitle(const wchar_t* title)
{
    HWND hwnd = GetWindow();
    SetWindowTextW(hwnd, title);
}

void WindowsNative::Application::ReleaseWindowTitlePtr()
{
    if (titleArr == nullptr)
        return;
    delete[] titleArr;
}

