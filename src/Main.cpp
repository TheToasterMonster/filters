#include <iostream>
#include "Image.h"
#include "Filters.h"

int main()
{
	Image image("images/tokyo.ppm");

	image.ApplyOperator2D(SOBEL_OPERATOR_2D);
	image.ApplyGrayScale();
	image.Save("images/output/tokyo_output.ppm");

#ifdef WINDOWS
	std::system("images\\output\\tokyo_output.ppm");
#else
	std::system("open images/output/tokyo_output.ppm");
#endif
}