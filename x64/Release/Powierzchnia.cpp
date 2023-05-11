#include"Powierzchnia.h"
#include"ChiliWin.h"
#include<cassert>
#include<fstream>
Powierzchnia::Powierzchnia(const std::string& f)
{
	std::ifstream file(f, std::ios::binary);
	BITMAPFILEHEADER bmf;
	file.read(reinterpret_cast<char*>(&bmf), sizeof(bmf));

		BITMAPINFOHEADER info;

	file.read(reinterpret_cast<char*>(&info), sizeof(info));
	assert(info.biBitCount == 24);
	assert(info.biCompression == BI_RGB);
	width = info.biWidth;
	heigth = info.biHeight;
	pPixels = new Color[width * heigth];
	file.seekg(bmf.bfOffBits);
	const int pad = (4 - (width * 3) % 4) % 4;
	int x = 0;
	int	y = heigth-1;
	while (y >=0)
	{
		x = 0;
		while (x < width)
		{
			PutPixel(x, y,Color( file.get(),file.get(),file.get() ));
			x++;
		}
		file.seekg(pad, std::ios::cur);
			y--;
	}
}
Powierzchnia::Powierzchnia(int width, int heigth)
	:
	width(width),
	heigth(heigth),
	pPixels(new Color[width * heigth]) 
{
}
Powierzchnia::Powierzchnia(const Powierzchnia& rhs)
	:
	Powierzchnia(rhs.width, rhs.heigth)
{
	int i=0;
	const int apix = width * heigth;
	while (i < apix)
	{
		pPixels[i] = rhs.pPixels[i];
		i++;
	}

}
Powierzchnia::~Powierzchnia()
{
	delete[]pPixels;
	pPixels = nullptr;
}

Powierzchnia & Powierzchnia::operator=(const Powierzchnia& rhs)
{
	int i = 0;
	width = rhs.width;
	heigth = rhs.heigth;
	delete[] pPixels;
	pPixels = new Color[width * heigth];
	const int apix = width * heigth;
	while (i < apix)
	{
		pPixels[i] = rhs.pPixels[i];
		i++;
	}
	return *this;
}
void Powierzchnia::PutPixel(int x, int y, Color c)
{ 
	assert(x >= 0);
	assert(x < width);
	assert(y >= 0);
	assert(y < heigth);
	 pPixels[y * width + x]=c;
}
Color Powierzchnia::GetPixel(int x,int y) const
{
	assert(x >= 0);
	assert(x < width);
	assert(y >= 0);
	assert(y < heigth);
	return pPixels[y * width + x];
}
int Powierzchnia::Getwidth() const
{
	return width;
}
int Powierzchnia::Getheigth() const
{
	return heigth;
}
