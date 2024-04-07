#pragma once
#include <Windows.h>

namespace WindowsNative 
{
	namespace Utils
	{
		struct Vector2
		{
			double x, y;

			Vector2(POINT point)
			{
				x = point.x;
				y = point.y;
			}
		};

		struct Vector3
		{
			double x, y, z;

			Vector3(POINT point)
			{
				x = point.x;
				y = point.y;
				z = 0;
			}

			Vector3(Vector2 vec2)
			{
				x = vec2.x;
				y = vec2.y;
				z = 0;
			}
		};
	}

}
	
