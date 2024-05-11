# Unity-WindowsNative-Plugin
为本人的Unity游戏项目编写的Windows C++原生插件，仅对外作为参考用途，因此不提供完整的C#端代码，请自行参考下方文档

## IDE
- [Visual Studio 2022 Community](https://visualstudio.microsoft.com/vs/community/)


## 功能介绍、C#示例
### `Desktop.cpp` Windows桌面相关功能

#### `const wchar_t* GetWindowTitle()`
> 获取当前窗口标题

#### `void SetWindowTitle(const wchar_t* title)`
> 更改窗口标题

#### `void ReleaseWindowTitlePtr()`
> 用于释放 `GetWindowTitle()` 调用时动态创建的字符串（无需手动调用，每次调用 `GetWindowTitle()` 时会自动释放一次）

```
//该代码示例仅在unsafe上下文中可用

using System.Runtime.InteropServices;

const string DllName = "UnityWindowsNativePlugin.dll";
[DllImport(DllName)] static extern void SetWindowTitle(char* title);
[DllImport(DllName)] static extern char* GetWindowTitle();
[DllImport(DllName)] static extern void ReleaseWindowTitlePtr();

public static string GameWindowTitle
{
    get
    {
        var titlePtr = GetWindowTitle();        //调用C++代码返回一个窗口标题字符串指针
        if(titlePtr == null)                    //判断指针是否为空
            return string.Empty;
        var title = new string(titlePtr);       //将字符串指针转换为C#的string
        ReleaseWindowTitlePtr();                //释放C++动态分配的指针
        return title;
    }
    set
    {
        var title = value ?? string.Empty;

        fixed (char* titlePtr = title)
        {
            SetWindowTitle(titlePtr);
        }
    }
}
```


#### `void GetCursorPosition(int* pixelX, int* pixelY)`
> 获取当前鼠标像素位置（左上原点）

```
using System.Runtime.InteropServices;

//引入DLL以及函数
[DllImport("UnityWindowsNativePlugin.dll")]
public static extern void GetCursorPosition(ref int pixelX, ref int pixelY);

void PrintCursorPosition()
{
	int x = 0;
	int y = 0;

	//传入int指针到C++对应的方法中
	GetCursorPosition(ref x, ref y);

	//调用GetCursorPosition之后x和y会被修改为当前光标位置
	Debug.Log("Cursor position: " + x + ", " + y);
}
```

#### `void SetCursorPosition(int pixelX, int pixelY) `
> 设置当前鼠标像素位置（左上原点）

```
using System.Runtime.InteropServices;

//引入DLL以及函数
[DllImport("UnityWindowsNativePlugin.dll")]
public static extern void SetCursorPosition(int pixelX, int pixelY);

void SetCursorPosition()
{
	int x = 50;
	int y = 50;
	SetCursorPosition(x, y);
}
```
