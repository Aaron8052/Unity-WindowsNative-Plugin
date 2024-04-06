// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "Utils.h"
using namespace WindowsNative;

extern "C"
{
    __declspec(dllexport) void Print(const wchar_t* str) {
        Utils::Print(str);
    }
}

