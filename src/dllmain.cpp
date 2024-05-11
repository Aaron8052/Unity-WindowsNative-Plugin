// dllmain.cpp : Defines the entry point for the DLL application.
#define EXPORT __declspec(dllexport)
#define IMPORT __declspec(dllimport)

#include "Native/Utils.h"
#include "Native/Desktop.h"
using namespace WindowsNative;

extern "C"
{
    EXPORT void GetCursorPosition(int* pixelX, int* pixelY)
    {
        Desktop::GetCursorPosition(pixelX, pixelY);
    }

    EXPORT void SetCursorPosition(int pixelX, int pixelY) 
    {
        Desktop::SetCursorPosition(pixelX, pixelY);
    }

    EXPORT void SetWindowTitle(const wchar_t* title) 
    {
        Desktop::SetWindowTitle(title);
    }

    EXPORT const wchar_t* GetWindowTitle() 
    {
        return Desktop::GetWindowTitle();
    }

    EXPORT void ReleaseWindowTitlePtr() 
    {
        Desktop::ReleaseWindowTitlePtr();
    }

    EXPORT bool ShowDialog(const wchar_t* title, const wchar_t* message, int iconType, int buttonType)
    {
        return Desktop::ShowDialog(title, message, (IconType)iconType, (ButtonType)buttonType);
    }
}

 