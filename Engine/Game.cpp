/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"
#include <iostream>
#include<conio.h>
#include"ChiliWin.h"
#include<ctime>
Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	ggg(L"gameover.mp3")
{
}

void Game::Go()
{
	gfx.BeginFrame();
		UpdateModel();
		ComposeFrame();
		gfx.EndFrame();
	

}

void Game::UpdateModel()
{

	if (wnd.kbd.KeyIsPressed(0x48))
	{
		hardmode = true;
	}
	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		kierunek = 1;
	}

	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		kierunek = 2;
	}

	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		kierunek = 3;
	
	}

	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		kierunek = 4;
	
	}
	int p = y - 30;
	if (kierunek==1 && p < 0)
	{
		gameover = true;
	}
	if(kierunek==1 && (p<60 && x<180)) // tu na stalo bo to sprawdza element gorny
	{
		gameover = true;
	}
	if(turned==true)
	{
		p = y + h;
	}
	else {

		p = y + 30;
	}
	if (p > 770-zmienna1 && kierunek == 2)
	{
		gameover = true;
	}
	p = x - 30;
	if (kierunek == 3 && p < 0)
	{
		gameover = true;
	}
	if (kierunek == 3 && p < 180 && y<60 ) // tu na stalo bo to sprawdza element gorny
	{
		gameover = true;
	}
	p = l + x + 30;
	if (kierunek == 4 && p >= gfx.ScreenWidth-zmienna1)

	{
		gameover = true;
	}
	if (wnd.kbd.KeyIsPressed(0x50))

	{
		Sleep(7000);

	}
	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		kierunek = 1;
	}
	while (!wnd.kbd.KeyIsEmpty())
	{
		// get an event from the queue
		const Keyboard::Event e = wnd.kbd.ReadKey();	
		if (e.IsPress())
		{
			if (e.GetCode() == 0x45)
			{
				turned = !turned;
				int temp;
				temp = l;
				l = h;
				h = temp;
				if (y + h > 770)
				{
					gameover = true;
				}
				else if (x + l > 1060)
				{
					gameover = true;
				}
				
			}
			else if (e.GetCode() == 0x51)
			{
				turned = !turned;
				int temp;
				temp = l;
				l = h;
				h = temp;
				if (y + h > 770)
				{
					gameover = true;
				}
				else if (x + l > 1060)
				{
					gameover = true;
				}
			}
			
		}
	}
	
}

void Game::ComposeFrame() {
	bool czydalrade = false;
	srand(time(NULL));
	int zz = 0;
		if (kierunek == 1)
		{
			y = y - 30;
		}

		else if (kierunek == 2)
		{
			y = y + 30;
		}
		else if (kierunek == 4)
		{
			x = x + 30;
		}
		else if (kierunek == 3)
		{
			x = x - 30;
		}		
		for (int op = 0; op < 1080-zmienna1; op++)
		{
			gfx.PutPixel(op, 779-zmienna1, Colors::Red);
		}
		for (int po = 0; po < 780-zmienna1; po++)
		{
			gfx.PutPixel(1079-zmienna1, po, Colors::Red);
		}
		for (int op = 0; op < 180; op++)
		{
			gfx.PutPixel(op, 61, Colors::Red);
		}
		for (int po = 0; po < 60; po++)
		{
			gfx.PutPixel(181, po, Colors::Red);
		}
		
		while (zz < i)
		{
			gfx.DrawSprite(ixy[zz], iy[zz], mina, 3);
			zz++;
		}
		zz = 0;

		
		if (isEaten == true)
		{	if(i==-1)
		{
		}
			if (turned == false)
				l = l + 30;
			else
				h = h + 30;
			z = z - 20;
			xx = (rand() % ((gfx.ScreenWidth - 30-zmienna1) / 30)) * 30;
			yy = (rand() % ((gfx.ScreenHeight - 30-zmienna1) / 30)) * 30;
			if (i == -1)
			{
				xx = (rand() % 10) * 30;
				yy = (rand() % 10) * 30;
			}
			while (yy<60)
			{
				if (xx < 180) {
					
					srand(time(NULL));
					yy = (rand() % 26) * 30;
					if (i == -1)
					{
						yy = (rand() % 10) * 30;
					}
				}
				else
					break;
				}
			if (hardmode == true)
			{
				zmienna1 += 15;
			}
			i++;
			isEaten = false;
			bomba = true;
			ixy.clear();
			iy.clear();
		}
		if (bomba == true)
		{
			int ww = 0;
			bomba = false;
			while (zz < i)
			{
				xxx = (rand() % 35) * 30;
				yyy = (rand() % 25) * 30;
				while ((xxx==xx && yyy==yy) || (xxx==x && yyy==y)|| (xxx == x-30 && yyy == y)|| (xxx == x && yyy == y-30)|| (xxx == x && yyy == y+30)||(xxx == x+30 && yyy == y))
				{

						srand(time(NULL));
						xxx = (rand() % 35) * 30;
						yyy = (rand() % 25) * 30;

					}
				

				ixy.push_back(xxx);
				iy.push_back(yyy);
				if (turned == false)
				{
					while (ww != l)
					{
						if (xxx == x + ww && yyy == y)
						{
							ixy.pop_back();
							iy.pop_back();
							zz = zz - 1;
							ww = 0;
							break;
						}
						ww += 30;
					}
				}
				else
				{
					while (ww != h)
					{
						if (xxx == x && yyy == y + ww)
						{
							ixy.pop_back();
							iy.pop_back();
							zz = zz - 1;
							ww = 0;
							break;
						}
						ww += 30;
					}
				}
				zz++;

			}
			zz = 0;
			czydalrade = true;
		}
		int w = 0;
		if (turned == false)
		{
			while (w != l)
			{
				if (w + x == xx && y == yy)
					isEaten = true;
				w += 30;
			}
			w = 0;
			while (w != l)
			{
				if (bomba == true)
				{
					while (zz < i - 1)
					{
						if (x + w == ixy[zz] && y == iy[zz])
						{
							if (czydalrade == false)
								gameover = true;
							czydalrade = false;

						}
						zz++;
					}
					zz = 0;
					w += 30;
				}
				else
				{
					while (zz < i)
					{
						if (x + w == ixy[zz] && y == iy[zz])
						{
							gameover = true;

						}
						zz++;
					}
					zz = 0;
					w += 30;
				}
			}
		}
		else
		{
			while (w != h)
			{
				if (x == xx && y+w == yy)
					isEaten = true;
				w += 30;
			}
			w = 0;
			while (w != h)
			{
				if (bomba == true)
				{
					while (zz < i - 1)
					{
						if (x == ixy[zz] && y+w == iy[zz])
						{
							if (czydalrade == false)
								gameover = true;
							czydalrade = false;

						}
						zz++;
					}
					zz = 0;
					w += 30;
				}
				else
				{
					while (zz < i)
					{
						if (x == ixy[zz] && y+w == iy[zz])
						{
							gameover = true;

						}
						zz++;
					}
					zz = 0;
					w += 30;
				}
			}
		}
		if (l == 0 || h == 0)
		{
			l = 30;
			h = 30;
		}
		Powierzchnia surf = Powierzchnia(l, h);
		gfx.DrawSprite(xx, yy, p);
		Sleep(z);
		if (turned == true)
		{

		}
		
		if (gameover == true)
		{
			hardmode = false;
			ggg.Play();
			zmienna1 = 0;
			gfx.DrawSprite(0, 0, gg, 3);
			gameover = false;
			if (turned == false)
				l = 0;
			else
				h = 0;
			isEaten = true;
			x = 60;
			y = 60;
			z = 370;
			zz = 0;
			i = -1;
			ixy.clear();
			iy.clear();
			bomba = false;
			kierunek = -1;
			turned = false;
			if (hs > chs)
				chs = hs;
			else;
		}
		gfx.DrawSprite(x, y, surf);
			if(i==0)
			gfx.DrawSprite(0, 30, l0, 3);
			else if (i == 1)
			{
				hs = 1;
				
				gfx.DrawSprite(0, 30, l1, 3);
			}
			else if (i == 2)
			{
				hs = 2;
				Powierzchnia  l2 = Powierzchnia("2.bmp");
				gfx.DrawSprite(0, 30, l2, 3);
			}
			else if (i == 3)
			{
				hs = 3;
				Powierzchnia  l3 = Powierzchnia("3.bmp");
				gfx.DrawSprite(0, 30, l3, 3);
			}
			else if (i == 4) {
				hs = 4;
				Powierzchnia  l4 = Powierzchnia("4.bmp");
				gfx.DrawSprite(0, 30, l4, 3);
			}
			else if (i == 5)
			{
				hs = 5;
				Powierzchnia  l5 = Powierzchnia("5.bmp");
				gfx.DrawSprite(0, 30, l5, 3);
			}
			else if (i == 6) {
				hs = 6;
				Powierzchnia  l6 = Powierzchnia("6.bmp");
				gfx.DrawSprite(0, 30, l6, 3);
			}
			else if (i == 7)
			{
				hs = 7;
				Powierzchnia  l7 = Powierzchnia("7.bmp");
				gfx.DrawSprite(0, 30, l7, 3);
			}
			else if (i == 8)
			{
				hs = 8;
				Powierzchnia  l8 = Powierzchnia("8.bmp");
				gfx.DrawSprite(0, 30, l8, 3);
			}
			else if (i == 9)
			{
				hs = 9;
				Powierzchnia  l9 = Powierzchnia("9.bmp");
				gfx.DrawSprite(0, 30, l9, 3);
			}
			else if (i == 10)
			{
				hs = 10;
				gfx.DrawSprite(0, 30, l1, 3);
				gfx.DrawSprite(30, 30, l0, 3);
			}
			else if (i == 11)
			{
				hs = 11;
				gfx.DrawSprite(0, 30, l1, 3);
				gfx.DrawSprite(30, 30, l1, 3);
			}
			else if (i == 12)
			{
				hs = 12;
				Powierzchnia  l2 = Powierzchnia("2.bmp");
				gfx.DrawSprite(0, 30, l1, 3);
				gfx.DrawSprite(30, 30, l2, 3);
			}
			else if (i == 13)
			{
				hs = 13;
				Powierzchnia  l3 = Powierzchnia("3.bmp");
				gfx.DrawSprite(0, 30, l1, 3);
				gfx.DrawSprite(30, 30, l3, 3);
			}
			else if (i == 14)
			{
				hs = 14;
				Powierzchnia  l4 = Powierzchnia("4.bmp");
				gfx.DrawSprite(0, 30, l1, 3);
				gfx.DrawSprite(30, 30, l4, 3);
			}
			else if (i == 15)
			{
				hs = 15;
				Powierzchnia  l5 = Powierzchnia("5.bmp");
				gfx.DrawSprite(0, 30, l1, 3);
				gfx.DrawSprite(30, 30, l5, 3);
			}
			else if (i == 16)
			{
				hs = 16;
				Powierzchnia  l6 = Powierzchnia("6.bmp");
				gfx.DrawSprite(0, 30, l1, 3);
				gfx.DrawSprite(30, 30, l6, 3);
			}
			else if (i == 17)
			{
			hs = 17;
				Powierzchnia  l7 = Powierzchnia("7.bmp");
				gfx.DrawSprite(0, 30, l1, 3);
				gfx.DrawSprite(0, 30, l7, 3);
			}
			
			gfx.DrawSprite(0, 0, hss, 3);
			if (chs == 0)
				gfx.DrawSprite(120, 2, l0, 3);
			else if (chs == 1)
			{
				

				gfx.DrawSprite(120, 2, l1, 3);
			}
			else if (chs == 2)
			{
				
				Powierzchnia  l2 = Powierzchnia("2.bmp");
				gfx.DrawSprite(120, 2, l2, 3);
			}
			else if (chs == 3)
			{
			
				Powierzchnia  l3 = Powierzchnia("3.bmp");
				gfx.DrawSprite(120, 2, l3, 3);
			}
			else if (chs == 4) {
				
				Powierzchnia  l4 = Powierzchnia("4.bmp");
				gfx.DrawSprite(120, 2, l4, 3);
			}
			else if (chs == 5)
			{
				
				Powierzchnia  l5 = Powierzchnia("5.bmp");
				gfx.DrawSprite(120, 2, l5, 3);
			}
			else if (chs == 6) {
				
				Powierzchnia  l6 = Powierzchnia("6.bmp");
				gfx.DrawSprite(120,2, l6, 3);
			}
			else if (chs == 7)
			{
				
				Powierzchnia  l7 = Powierzchnia("7.bmp");
				gfx.DrawSprite(120, 2, l7, 3);
			}
			else if (chs == 8)
			{
			
				Powierzchnia  l8 = Powierzchnia("8.bmp");
				gfx.DrawSprite(120, 2, l8, 3);
			}
			else if (chs == 9)
			{
				
				Powierzchnia  l9 = Powierzchnia("9.bmp");
				gfx.DrawSprite(120,2, l9, 3);
			}
			else if (chs == 10)
			{
				
				gfx.DrawSprite(120, 2, l1, 3);
				gfx.DrawSprite(150, 2, l0, 3);
			}
			else if (chs == 11)
			{
				
				gfx.DrawSprite(120, 2, l1, 3);
				gfx.DrawSprite(150, 2, l1, 3);
			}
			else if (chs == 12)
			{
			
				Powierzchnia  l2 = Powierzchnia("2.bmp");
				gfx.DrawSprite(120, 2, l1, 3);
				gfx.DrawSprite(150, 2, l2, 3);
			}
			else if (chs == 13)
			{
				
				Powierzchnia  l3 = Powierzchnia("3.bmp");
				gfx.DrawSprite(120, 2, l1, 3);
				gfx.DrawSprite(150,2, l3, 3);
			}
			else if (chs == 14)
			{
				
				Powierzchnia  l4 = Powierzchnia("4.bmp");
				gfx.DrawSprite(120, 2, l1, 3);
				gfx.DrawSprite(150, 2, l4, 3);
			}
			else if (chs == 15)
			{
			
				Powierzchnia  l5 = Powierzchnia("5.bmp");
				gfx.DrawSprite(120, 2, l1, 3);
				gfx.DrawSprite(150, 2, l5, 3);
			}
			else if (chs == 16)
			{
				
				Powierzchnia  l6 = Powierzchnia("6.bmp");
				gfx.DrawSprite(120, 2, l1, 3);
				gfx.DrawSprite(150, 2, l6, 3);
			}
			else if (chs == 17)
			{
				
				Powierzchnia  l7 = Powierzchnia("7.bmp");
				gfx.DrawSprite(120, 2, l1, 3);
				gfx.DrawSprite(150, 2, l7, 3);
			}

}
