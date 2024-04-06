// Unity-WindowsNative-Plugin.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "Unity-WindowsNative-Plugin.h"


// This is an example of an exported variable
UNITYWINDOWSNATIVEPLUGIN_API int nUnityWindowsNativePlugin=0;

// This is an example of an exported function.
UNITYWINDOWSNATIVEPLUGIN_API int fnUnityWindowsNativePlugin(void)
{
    return 0;
}

// This is the constructor of a class that has been exported.
CUnityWindowsNativePlugin::CUnityWindowsNativePlugin()
{
    return;
}
