# Unity-WindowsNative-Plugin
为本人的Unity游戏项目编写的Windows C++原生插件，仅对外作为参考用途，因此不提供完整的C#端代码，请自行参考下方文档

## IDE
- [Visual Studio 2022 Community](https://visualstudio.microsoft.com/vs/community/)


## 功能介绍、示例
### 'Desktop.cpp' Windows桌面相关功能

#### `void GetCursorPosition(int* pixelX, int* pixelY)`
> 获取当前鼠标像素位置（左上原点）
- C#调用示例

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
- C#调用示例

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
