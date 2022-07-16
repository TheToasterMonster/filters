#include <iostream>
#include "Image.h"

int main()
{
	Image image("images/tokyo.ppm");

	static Operator op = {
		{ -2, -1, -2 },
		{  0,  0,  0 },
		{  2,  1,  2 }
	};

	image.ApplyOperator(op);
	image.ApplyGrayScale();
	image.Save("images/output/tokyo_edges.ppm");
}