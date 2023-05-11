#pragma once
#include<string>
#include"Colors.h"
class Powierzchnia
{	public:
	Powierzchnia(const std::string& f);
	Powierzchnia(int width, int heigth);
	Powierzchnia(const Powierzchnia& );
	~Powierzchnia();
	Powierzchnia& operator=(const Powierzchnia&);
	void PutPixel(int x, int y, Color c);
	Color GetPixel(int x,int y) const;
	int Getwidth() const;
	int Getheigth() const;
private:
	Color* pPixels = nullptr;
	int width;
	int heigth;
};