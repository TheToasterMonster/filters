#pragma once
#include "Image.h"

#define SOBEL_OPERATOR_2D Filter::SobelGx, Filter::SobelGy
#define PREWITT_OPERATOR_2D Filter::PrewittGx, Filter::PrewittGy

namespace Filter
{
	const Operator SobelGx = {
		{ -1,  0,  1 },
		{ -2,  0,  2 },
		{ -1,  0,  1 },
	};
	const Operator SobelGy = {
		{ -1, -2, -1 },
		{  0,  0,  0 },
		{  1,  2,  1 },
	};

	const Operator PrewittGx = {
		{ -1,  0,  1 },
		{ -1,  0,  1 },
		{ -1,  0,  1 },
	};
	const Operator PrewittGy = {
		{ -1, -1, -1 },
		{  0,  0,  0 },
		{  1,  1,  1 },
	};
}
