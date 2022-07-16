#pragma once
#include "Image.h"

#define SOBEL_OPERATOR_2D Filter::SobelGx, Filter::SobelGy

namespace Filter
{
	const Operator SobelGx = {
		{ -1, -2, -1 },
		{  0,  0,  0 },
		{  1,  2,  1 },
	};
	const Operator SobelGy = {
		{ -1,  0,  1 },
		{ -2,  0,  2 },
		{ -1,  0,  1 },
	};
}
