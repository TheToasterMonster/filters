#include "Image.h"
#include <fstream>
#include <iostream>
#include <filesystem>

void Image::ApplyOperator(const Operator& matrix)
{
	ImageData tmp(m_ImageData);
	for (int i = 0; i < m_Height; i++)
	{
		for (int j = 0; j < m_Width; j++)
		{
			Color sum{};

			for (int di = -1; di <= 1; di++)
			{
				for (int dj = -1; dj <= 1; dj++)
				{
					if (i + di < 0 || i + di >= m_Height || j + dj < 0 || j + dj >= m_Width)
					{
						continue;
					}

					sum += (m_ImageData[i + di][j + dj] * matrix[di + 1][dj + 1]);
				}
			}

			//tmp[i][j] = clamp(sum, 0, 255);
			tmp[i][j] = abs(sum);
		}
	}
	m_ImageData = tmp;
}

void Image::ApplySobelOperator()
{
	static int Gx[3][3] = {
		{ -1,  0,  1 },
		{ -2,  0,  2 },
		{ -1,  0,  1 },
	};
	static int Gy[3][3] = {
		{ -1, -2, -1 },
		{  0,  0,  0 },
		{  1,  2,  1 },
	};

	ImageData tmp(m_ImageData);
	for (int i = 0; i < m_Height; i++)
	{
		for (int j = 0; j < m_Width; j++)
		{
			Color sumGx{};
			Color sumGy{};

			for (int di = -1; di <= 1; di++)
			{
				for (int dj = -1; dj <= 1; dj++)
				{
					if (i + di < 0 || i + di >= m_Height || j + dj < 0 || j + dj >= m_Width)
					{
						continue;
					}

					sumGx += (m_ImageData[i + di][j + dj] * Gx[di + 1][dj + 1]);
					sumGy += (m_ImageData[i + di][j + dj] * Gy[di + 1][dj + 1]);
				}
			}

			tmp[i][j] = sqrt(dot(sumGx, sumGx) + dot(sumGy, sumGy));
		}
	}
	m_ImageData = tmp;
}

void Image::ApplyGrayScale()
{
	for (int i = 0; i < m_Height; i++)
	{
		for (int j = 0; j < m_Width; j++)
		{
			int sum = m_ImageData[i][j].r + m_ImageData[i][j].g + m_ImageData[i][j].b;
			int avg = (int)(sum / 3.0f);
			m_ImageData[i][j] = Color{ avg, avg, avg };
		}
	}
}

void Image::Save(std::string filePath)
{
	std::filesystem::create_directory("images/output");
	std::ofstream outputFile(filePath);
	if (!outputFile.is_open())
	{
		std::cout << "Failed to open " << filePath << ".\n";
		throw;
	}

	outputFile << m_MagicNumber << '\n';
	outputFile << m_Width << " " << m_Height << '\n';
	outputFile << m_ColorRange << '\n';

	for (int i = 0; i < m_Height; i++)
	{
		for (int j = 0; j < m_Width; j++)
		{
			outputFile << m_ImageData[i][j].r << " " << m_ImageData[i][j].g << " " << m_ImageData[i][j].b << '\n';
		}
	}

	std::cout << "Image saved." << '\n';
}

Image::Image(std::string filePath)
{
	std::ifstream inputFile(filePath);
	if (!inputFile.is_open())
	{
		std::cout << "Failed to open " << filePath << ".\n";
		throw;
	}

	inputFile >> m_MagicNumber;
	inputFile >> m_Width >> m_Height >> m_ColorRange;

	m_ImageData = ImageData(m_Height);
	for (int i = 0; i < m_Height; i++)
	{
		m_ImageData[i].resize(m_Width);
	}

	for (int i = 0; i < m_Height; i++)
	{
		for (int j = 0; j < m_Width; j++)
		{
			inputFile >> m_ImageData[i][j].r >> m_ImageData[i][j].g >> m_ImageData[i][j].b;
		}
	}

	std::cout << "Image loaded." << '\n';
}
