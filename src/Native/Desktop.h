#include <Windows.h>

namespace WindowsNative
{
	typedef enum IconType
	{
		None = 0,
		Hand,
		Question,
		Exclamation,
		Asterisk,
		Warning,
		Information,
		Error,
		Stop,
	};

	namespace Desktop
	{
		HWND GetWindow();
		void GetWindowPosition(int*, int*, int*, int*);
		void SetWindowPosition(int, int);
		const wchar_t* GetWindowTitle();
		void SetWindowTitle(const wchar_t*);
		void ReleaseWindowTitlePtr();
		void SetCursorPosition(int, int);
		void GetCursorPosition(int*, int*);
		bool ShowDialog(const wchar_t*, const wchar_t*, IconType iconType);
	}
}
