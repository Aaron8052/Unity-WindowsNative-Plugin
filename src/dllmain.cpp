// dllmain.cpp : Defines the entry point for the DLL application.
#define EXPORT __declspec(dllexport)
#define IMPORT __declspec(dllimport)

#include "Native/Utils.h"
#include "Native/Desktop.h"
#include "Native/Application.h"
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
        Application::SetWindowTitle(title);
    }

    EXPORT const wchar_t* GetWindowTitle() 
    {
        return Application::GetWindowTitle();
    }

    EXPORT void ReleaseWindowTitlePtr() 
    {
        Application::ReleaseWindowTitlePtr();
    }
}

