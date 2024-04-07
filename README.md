# This project is still under development
# 本插件处于开发阶段

# Unity-WindowsNative-Plugin
适用于Unity引擎的Windows端Native插件
## IDE
### C++
- [Visual Studio 2022 Community](https://visualstudio.microsoft.com/vs/community/)

## 兼容性
- Windows 10 / 11
- 任何Unity版本（理论上，因为需要你自己写C#代码对接）

# 使用
## 导入
### 选择1
- Clone整个项目用上述IDE打开并自行编译成DLL
- 导入到Unity项目的Plugins对应文件夹

### 选择2
- 从Release里下载打包好的DLL（暂时没有，还没开发完）
- 导入到Unity项目的Plugins对应文件夹

## 调用插件
- 自行参考下方示例编写对应的C#代码来调用DLL

## 功能介绍、示例
### Windows桌面相关功能

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
