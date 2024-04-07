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

    //仅测试
    EXPORT int Print(int num) 
    {
        return num * 2;
    }
}

