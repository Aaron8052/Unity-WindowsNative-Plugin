#include <Windows.h>

namespace WindowsNative
{
	namespace Desktop
	{
		HWND GetWindow();
		void GetWindowPosition(int* x, int* y, int* width, int* height);
		void SetWindowPosition(int x, int y);
		const wchar_t* GetWindowTitle();
		void SetWindowTitle(const wchar_t* title);
		void ReleaseWindowTitlePtr();
		void SetCursorPosition(int pixelX, int pixelY);
		void GetCursorPosition(int* pixelX, int* pixelY);
	}
}
