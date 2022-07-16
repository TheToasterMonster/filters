#pragma once

#include <string>
#include <vector>
#include "Color.h"

typedef std::vector<std::vector<Color>> ImageData;
typedef int Operator[3][3];

class Image
{
public:
	void ApplyOperator(const Operator& matrix);
	void ApplyOperator2D(const Operator& Gx, const Operator& Gy);
	void ApplyGrayScale();
	void Save(std::string filePath);

	Image(std::string filePath);

private:
	std::string m_MagicNumber;
	int m_Width, m_Height, m_ColorRange;
	ImageData m_ImageData;
};

