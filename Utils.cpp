#include "Utils.h"
#include <iostream>
using namespace std;

void WindowsNative::Utils::Print(const wchar_t* content)
{
	wcout << content << endl;
}
