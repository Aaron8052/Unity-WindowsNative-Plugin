// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the UNITYWINDOWSNATIVEPLUGIN_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// UNITYWINDOWSNATIVEPLUGIN_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef UNITYWINDOWSNATIVEPLUGIN_EXPORTS
#define UNITYWINDOWSNATIVEPLUGIN_API __declspec(dllexport)
#else
#define UNITYWINDOWSNATIVEPLUGIN_API __declspec(dllimport)
#endif

// This class is exported from the dll
class UNITYWINDOWSNATIVEPLUGIN_API CUnityWindowsNativePlugin {
public:
	CUnityWindowsNativePlugin(void);
	// TODO: add your methods here.
};

extern UNITYWINDOWSNATIVEPLUGIN_API int nUnityWindowsNativePlugin;

UNITYWINDOWSNATIVEPLUGIN_API int fnUnityWindowsNativePlugin(void);
