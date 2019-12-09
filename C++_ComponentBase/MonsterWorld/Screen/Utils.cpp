#include "stdafx.h"
#include "Utils.h"
#include <time.h>

// =========== Vector2 Struct
Vector2 Vector2::zero{ 0.0f, 0.0f };
Vector2 Vector2::ones{ 1.0f, 1.0f };
Vector2 Vector2::up{ 0.0f, 1.0f };
Vector2 Vector2::down{ 0.0f, -1.0f };
Vector2 Vector2::left{ -1.0f, 0.0f };
Vector2 Vector2::right{ 1.0f, 0.0f };

Vector2 operator-(Vector2& a, const Vector2& b)
{

	return (a.operator-(b));
}

float Vector2::Distance(Vector2& a, const Vector2& b)
{
	return (a.operator-(b)).magnitude();
}


int Random_Range(int min, int max)
{
	
	if (min < 0)
	{
		return rand() % ((max*2)+1) + min;
	}
	else if (min > 0)
	{
		int value = rand() % (max+1);
		if (value < min)
			return value + min;
		else
			return value;
	}
	else
	{
		return rand() % (max+1);
	}

}

void setColor(int foreground, int background)
{
	int color = foreground + background * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}