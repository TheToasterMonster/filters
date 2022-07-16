#include "Color.h"
#include <cmath>

Color operator*(const Color& color, int scalar)
{
	return { color.r * scalar, color.g * scalar, color.b * scalar };
}

Color operator*(int scalar, const Color& color)
{
	return { color.r * scalar, color.g * scalar, color.b * scalar };
}

Color operator+(const Color& c1, const Color& c2)
{
	return { c1.r + c2.r, c1.g + c2.g, c1.b + c2.b };
}

void operator+=(Color& c1, const Color& c2)
{
	c1 = c1 + c2;
}

Color sqrt(const Color& color)
{
	return { (int)sqrt(color.r), (int)sqrt(color.g), (int)sqrt(color.b) };
}

Color dot(const Color& v1, const Color& v2)
{
	return { v1.r * v2.r, v1.g * v2.g, v1.b * v2.b };
}

Color clamp(const Color& color, int minVal, int maxVal)
{
	Color result(color);
	if (result.r < minVal) result.r = minVal;
	if (result.r > maxVal) result.r = maxVal;
	if (result.g < minVal) result.g = minVal;
	if (result.g > maxVal) result.g = maxVal;
	if (result.b < minVal) result.b = minVal;
	if (result.b > maxVal) result.b = maxVal;
	return result;
}

Color abs(const Color& color)
{
	return { abs(color.r), abs(color.g), abs(color.b) };
}
