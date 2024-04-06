// dllmain.cpp : Defines the entry point for the DLL application.

#include "Utils.h"
using namespace WindowsNative;

extern "C"
{
    //仅测试
    __declspec(dllexport) int Print(int num) {
        return num * 2;
    }
}

