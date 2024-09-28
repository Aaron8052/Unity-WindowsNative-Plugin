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
	typedef enum ButtonType
	{
		YesNo = 0,
		Ok,
		OkCancel,
	};
	class Desktop
	{
	private:
		static HWND GetWindow();
	public:
		static void GetWindowPosition(int*, int*, int*, int*);
		static void SetWindowPosition(int, int);
		static const wchar_t* GetWindowTitle();
		static void SetWindowTitle(const wchar_t*);
		static void ReleaseWindowTitlePtr();
		static void SetCursorPosition(int, int);
		static void GetCursorPosition(int*, int*);
		static bool ShowDialog(const wchar_t*, const wchar_t*, IconType iconType, ButtonType buttonType);
	};
}
