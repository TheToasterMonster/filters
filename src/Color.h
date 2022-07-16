#pragma once

#include <stdint.h>

struct Color
{
	int r, g, b;
};

Color operator*(const Color& color, int scalar);
Color operator*(int scalar, const Color& color);
Color operator+(const Color& c1, const Color& c2);
void operator+=(Color& c1, const Color& c2);
Color sqrt(const Color& color);
Color dot(const Color& v1, const Color& v2);
Color clamp(const Color& color, int minVal, int maxVal);
Color abs(const Color& color);
