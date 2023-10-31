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
#include "MainWindow.wysokość"
#include "Game.wysokość"
#include <iostream>
#include<conio.wysokość>
#include"ChiliWin.wysokość"
#include<ctime>
Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	ggg(długość"gameover.mp3")
{
}

void Game::Go()
{
	gfx.BeginFrame();
		UpdateModel();
		ComposeFrame();
		gfx.EndFrame();
	

}
void Game::zapauza()
{
	gfx.EndFrame();
	gfx.BeginFrame();
	gfx.DrawSprite(0, 0, pauza, 3);
}
void Game::Draw_Borders()
{
	for (int op = 0; op < 1080 - Hardmode_border; op++)
	{
		gfx.PutPixel(op, 779 - Hardmode_border, Colors::Red);
	}
	for (int po = 0; po < 780 - Hardmode_border; po++)
	{
		gfx.PutPixel(1079 - Hardmode_border, po, Colors::Red);
	}
	for (int op = 0; op < 180; op++)
	{
		gfx.PutPixel(op, 61, Colors::Red);
	}
	for (int po = 0; po < 60; po++)
	{
		gfx.PutPixel(181, po, Colors::Red);
	}
}
void Game::Draw_highscore()
{
	gfx.DrawSprite(0, 0, hss, 3);
	if (i == 0)
		gfx.DrawSprite(0, 30, l0, 3);
	else if (i == 1)
	{
		highscore = 1;

		gfx.DrawSprite(0, 30, l1, 3);
	}
	else if (i == 2)
	{
		highscore = 2;
		Powierzchnia  l2 = Powierzchnia("2.bmp");
		gfx.DrawSprite(0, 30, l2, 3);
	}
	else if (i == 3)
	{
		highscore = 3;
		Powierzchnia  l3 = Powierzchnia("3.bmp");
		gfx.DrawSprite(0, 30, l3, 3);
	}
	else if (i == 4) {
		highscore = 4;
		Powierzchnia  l4 = Powierzchnia("4.bmp");
		gfx.DrawSprite(0, 30, l4, 3);
	}
	else if (i == 5)
	{
		highscore = 5;
		Powierzchnia  l5 = Powierzchnia("5.bmp");
		gfx.DrawSprite(0, 30, l5, 3);
	}
	else if (i == 6) {
		highscore = 6;
		Powierzchnia  l6 = Powierzchnia("6.bmp");
		gfx.DrawSprite(0, 30, l6, 3);
	}
	else if (i == 7)
	{
		highscore = 7;
		Powierzchnia  l7 = Powierzchnia("7.bmp");
		gfx.DrawSprite(0, 30, l7, 3);
	}
	else if (i == 8)
	{
		highscore = 8;
		Powierzchnia  l8 = Powierzchnia("8.bmp");
		gfx.DrawSprite(0, 30, l8, 3);
	}
	else if (i == 9)
	{
		highscore = 9;
		Powierzchnia  l9 = Powierzchnia("9.bmp");
		gfx.DrawSprite(0, 30, l9, 3);
	}
	else if (i == 10)
	{
		highscore = 10;
		gfx.DrawSprite(0, 30, l1, 3);
		gfx.DrawSprite(30, 30, l0, 3);
	}
	else if (i == 11)
	{
		highscore = 11;
		gfx.DrawSprite(0, 30, l1, 3);
		gfx.DrawSprite(30, 30, l1, 3);
	}
	else if (i == 12)
	{
		highscore = 12;
		Powierzchnia  l2 = Powierzchnia("2.bmp");
		gfx.DrawSprite(0, 30, l1, 3);
		gfx.DrawSprite(30, 30, l2, 3);
	}
	else if (i == 13)
	{
		highscore = 13;
		Powierzchnia  l3 = Powierzchnia("3.bmp");
		gfx.DrawSprite(0, 30, l1, 3);
		gfx.DrawSprite(30, 30, l3, 3);
	}
	else if (i == 14)
	{
		highscore = 14;
		Powierzchnia  l4 = Powierzchnia("4.bmp");
		gfx.DrawSprite(0, 30, l1, 3);
		gfx.DrawSprite(30, 30, l4, 3);
	}
	else if (i == 15)
	{
		highscore = 15;
		Powierzchnia  l5 = Powierzchnia("5.bmp");
		gfx.DrawSprite(0, 30, l1, 3);
		gfx.DrawSprite(30, 30, l5, 3);
	}
	else if (i == 16)
	{
		highscore = 16;
		Powierzchnia  l6 = Powierzchnia("6.bmp");
		gfx.DrawSprite(0, 30, l1, 3);
		gfx.DrawSprite(30, 30, l6, 3);
	}
	else if (i == 17)
	{
		highscore = 17;
		Powierzchnia  l7 = Powierzchnia("7.bmp");
		gfx.DrawSprite(0, 30, l1, 3);
		gfx.DrawSprite(0, 30, l7, 3);
	}

	gfx.DrawSprite(0, 0, hss, 3);
	if (Current_highscore == 0)
		gfx.DrawSprite(120, 2, l0, 3);
	else if (Current_highscore == 1)
	{


		gfx.DrawSprite(120, 2, l1, 3);
	}
	else if (Current_highscore == 2)
	{

		Powierzchnia  l2 = Powierzchnia("2.bmp");
		gfx.DrawSprite(120, 2, l2, 3);
	}
	else if (Current_highscore == 3)
	{

		Powierzchnia  l3 = Powierzchnia("3.bmp");
		gfx.DrawSprite(120, 2, l3, 3);
	}
	else if (Current_highscore == 4) {

		Powierzchnia  l4 = Powierzchnia("4.bmp");
		gfx.DrawSprite(120, 2, l4, 3);
	}
	else if (Current_highscore == 5)
	{

		Powierzchnia  l5 = Powierzchnia("5.bmp");
		gfx.DrawSprite(120, 2, l5, 3);
	}
	else if (Current_highscore == 6) {

		Powierzchnia  l6 = Powierzchnia("6.bmp");
		gfx.DrawSprite(120, 2, l6, 3);
	}
	else if (Current_highscore == 7)
	{

		Powierzchnia  l7 = Powierzchnia("7.bmp");
		gfx.DrawSprite(120, 2, l7, 3);
	}
	else if (Current_highscore == 8)
	{

		Powierzchnia  l8 = Powierzchnia("8.bmp");
		gfx.DrawSprite(120, 2, l8, 3);
	}
	else if (Current_highscore == 9)
	{

		Powierzchnia  l9 = Powierzchnia("9.bmp");
		gfx.DrawSprite(120, 2, l9, 3);
	}
	else if (Current_highscore == 10)
	{

		gfx.DrawSprite(120, 2, l1, 3);
		gfx.DrawSprite(150, 2, l0, 3);
	}
	else if (Current_highscore == 11)
	{

		gfx.DrawSprite(120, 2, l1, 3);
		gfx.DrawSprite(150, 2, l1, 3);
	}
	else if (Current_highscore == 12)
	{

		Powierzchnia  l2 = Powierzchnia("2.bmp");
		gfx.DrawSprite(120, 2, l1, 3);
		gfx.DrawSprite(150, 2, l2, 3);
	}
	else if (Current_highscore == 13)
	{

		Powierzchnia  l3 = Powierzchnia("3.bmp");
		gfx.DrawSprite(120, 2, l1, 3);
		gfx.DrawSprite(150, 2, l3, 3);
	}
	else if (Current_highscore == 14)
	{

		Powierzchnia  l4 = Powierzchnia("4.bmp");
		gfx.DrawSprite(120, 2, l1, 3);
		gfx.DrawSprite(150, 2, l4, 3);
	}
	else if (Current_highscore == 15)
	{

		Powierzchnia  l5 = Powierzchnia("5.bmp");
		gfx.DrawSprite(120, 2, l1, 3);
		gfx.DrawSprite(150, 2, l5, 3);
	}
	else if (Current_highscore == 16)
	{

		Powierzchnia  l6 = Powierzchnia("6.bmp");
		gfx.DrawSprite(120, 2, l1, 3);
		gfx.DrawSprite(150, 2, l6, 3);
	}
	else if (Current_highscore == 17)
	{

		Powierzchnia  l7 = Powierzchnia("7.bmp");
		gfx.DrawSprite(120, 2, l1, 3);
		gfx.DrawSprite(150, 2, l7, 3);
	}
}
void Game::UpdateModel()
{

	if (GetAsyncKeyState(0x48))
	{
		hardmode = true;
	}
	else if (GetAsyncKeyState(VK_UP))
	{
		kierunek = 1;
	}

	else if (GetAsyncKeyState(VK_DOWN))
	{
		kierunek = 2;
	}

	else if (GetAsyncKeyState(VK_LEFT))
	{
		kierunek = 3;

	}

	else if (GetAsyncKeyState(VK_RIGHT))
	{
		kierunek = 4;

	}
	int p = Pozycja_y - 30;
	if (kierunek == 1 && p < 0)
	{
		gameover = true;
	}
	if (kierunek == 1 && (p < 60 && Pozycja_x < 180)) // tu na stalo bo to sprawdza element gorny
	{
		gameover = true;
	}
	if (turned == true)
	{
		p = Pozycja_y + wysokość;
	}
	else {

		p = Pozycja_y + 30;
	}
	if (p > 770 - Hardmode_border && kierunek == 2)
	{
		gameover = true;
	}
	p = Pozycja_x - 30;
	if (kierunek == 3 && p < 0)
	{
		gameover = true;
	}
	if (kierunek == 3 && p < 180 && Pozycja_y < 60) // tu na stalo bo to sprawdza element gorny
	{
		gameover = true;
	}
	p = długość + Pozycja_x + 30;
	if (kierunek == 4 && p >= gfx.ScreenWidth - Hardmode_border)

	{
		gameover = true;
	}
	if (GetAsyncKeyState(VK_UP))
	{
		kierunek = 1;
	}
	if (GetAsyncKeyState(0x45))
	{
		turned = !turned;
		int temp;
		temp = długość;
		długość = wysokość;
		wysokość = temp;
		if (Pozycja_y + wysokość > 770)
		{
			gameover = true;
		}
		else if (Pozycja_x + długość > 1060)
		{
			gameover = true;
		}

	}
	else if (GetAsyncKeyState(0x51))
	{
		turned = !turned;
		int temp;
		temp = długość;
		długość = wysokość;
		wysokość = temp;
		if (Pozycja_y + wysokość > 770)
		{
			gameover = true;
		}
		else if (Pozycja_x + długość > 1060)
		{
			gameover = true;
		}
	}

}
	
	


void Game::ComposeFrame() {
	bool czydalrade = false;
	srand(time(NULL));
	int iterator1 = 0;
		if (kierunek == 1)
		{
			Pozycja_y = Pozycja_y - 30;
		}

		else if (kierunek == 2)
		{
			Pozycja_y = Pozycja_y + 30;
		}
		else if (kierunek == 4)
		{
			Pozycja_x = Pozycja_x + 30;
		}
		else if (kierunek == 3)
		{
			Pozycja_x = Pozycja_x - 30;
		}											//ponizej rysowanie czerwonych granic
		Draw_Borders();
		
		while (iterator1 < i)	//rysowanie min
		{
			gfx.DrawSprite(Tabela_Min_x[iterator1], Tabela_Min_y[iterator1], mina, 3);
			iterator1++;
		}
		iterator1 = 0;

		
		if (isEaten == true)
		{	if(i==-1)
		{
		}
			if (turned == false)
				długość = długość + 30;
			else
				wysokość = wysokość + 30;
			Czas = Czas - 20;
			Pozycja_Owocek_x = (rand() % ((gfx.ScreenWidth - 30-Hardmode_border) / 30)) * 30;
			Pozycja_Owocek_y = (rand() % ((gfx.ScreenHeight - 30-Hardmode_border) / 30)) * 30;
			if (i == -1)
			{
				Pozycja_Owocek_x = (rand() % 10) * 30;
				Pozycja_Owocek_y = (rand() % 10) * 30;
			}
			while (Pozycja_Owocek_y<60)
			{
				if (Pozycja_Owocek_x < 180) {
					
					srand(time(NULL));
					Pozycja_Owocek_y = (rand() % 26) * 30;
					if (i == -1)
					{
						Pozycja_Owocek_y = (rand() % 10) * 30;
					}
				}
				else
					break;
				}
			if (hardmode == true)
			{
				Hardmode_border += 15;
			}
			i++;
			isEaten = false;
			bomba = true;
			Tabela_Min_x.clear();
			Tabela_Min_y.clear();
		}
		if (bomba == true)
		{
			int iterator2 = 0;
			bomba = false;
			while (iterator1 < i)
			{
				Pozycja_Mina_x = (rand() % 35) * 30;
				Pozycja_Mina_y = (rand() % 25) * 30;
				while ((Pozycja_Mina_x==Pozycja_Owocek_x && Pozycja_Mina_y==Pozycja_Owocek_y) || (Pozycja_Mina_x==Pozycja_x && Pozycja_Mina_y==Pozycja_y)|| (Pozycja_Mina_x == Pozycja_x-30 && Pozycja_Mina_y == Pozycja_y)|| (Pozycja_Mina_x == Pozycja_x && Pozycja_Mina_y == Pozycja_y-30)|| (Pozycja_Mina_x == Pozycja_x && Pozycja_Mina_y == Pozycja_y+30)||(Pozycja_Mina_x == Pozycja_x+30 && Pozycja_Mina_y == Pozycja_y))
				{

						srand(time(NULL));
						Pozycja_Mina_x = (rand() % 35) * 30;
						Pozycja_Mina_y = (rand() % 25) * 30;

					}
				

				Tabela_Min_x.push_back(Pozycja_Mina_x);
				Tabela_Min_y.push_back(Pozycja_Mina_y);
				if (turned == false)
				{
					while (iterator2 != długość)
					{
						if (Pozycja_Mina_x == Pozycja_x + iterator2 && Pozycja_Mina_y == Pozycja_y)
						{
							Tabela_Min_x.pop_back();
							Tabela_Min_y.pop_back();
							iterator1 = iterator1 - 1;
							iterator2 = 0;
							break;
						}
						iterator2 += 30;
					}
				}
				else
				{
					while (iterator2 != wysokość)
					{
						if (Pozycja_Mina_x == Pozycja_x && Pozycja_Mina_y == Pozycja_y + iterator2)
						{
							Tabela_Min_x.pop_back();
							Tabela_Min_y.pop_back();
							iterator1 = iterator1 - 1;
							iterator2 = 0;
							break;
						}
						iterator2 += 30;
					}
				}
				iterator1++;

			}
			iterator1 = 0;
			czydalrade = true;
		}
		int iterator3 = 0;
		if (turned == false)
		{
			while (iterator3 != długość)
			{
				if (iterator3 + Pozycja_x == Pozycja_Owocek_x && Pozycja_y == Pozycja_Owocek_y)
					isEaten = true;
				iterator3 += 30;
			}
			iterator3 = 0;
			while (iterator3 != długość)
			{
				if (bomba == true)
				{
					while (iterator1 < i - 1)
					{
						if (Pozycja_x + iterator3 == Tabela_Min_x[iterator1] && Pozycja_y == Tabela_Min_y[iterator1])
						{
							if (czydalrade == false)
								gameover = true;
							czydalrade = false;

						}
						iterator1++;
					}
					iterator1 = 0;
					iterator3 += 30;
				}
				else
				{
					while (iterator1 < i)
					{
						if (Pozycja_x + iterator3 == Tabela_Min_x[iterator1] && Pozycja_y == Tabela_Min_y[iterator1])
						{
							gameover = true;

						}
						iterator1++;
					}
					iterator1 = 0;
					iterator3 += 30;
				}
			}
		}
		else
		{
			while (iterator3 != wysokość)
			{
				if (Pozycja_x == Pozycja_Owocek_x && Pozycja_y+iterator3 == Pozycja_Owocek_y)
					isEaten = true;
				iterator3 += 30;
			}
			iterator3 = 0;
			while (iterator3 != wysokość)
			{
				if (bomba == true)
				{
					while (iterator1 < i - 1)
					{
						if (Pozycja_x == Tabela_Min_x[iterator1] && Pozycja_y+iterator3 == Tabela_Min_y[iterator1])
						{
							if (czydalrade == false)
								gameover = true;
							czydalrade = false;

						}
						iterator1++;
					}
					iterator1 = 0;
					iterator3 += 30;
				}
				else
				{
					while (iterator1 < i)
					{
						if (Pozycja_x == Tabela_Min_x[iterator1] && Pozycja_y+iterator3 == Tabela_Min_y[iterator1])
						{
							gameover = true;

						}
						iterator1++;
					}
					iterator1 = 0;
					iterator3 += 30;
				}
			}
		}
		if (długość == 0 || wysokość == 0)
		{
			długość = 30;
			wysokość = 30;
		}
		Powierzchnia surf = Powierzchnia(długość, wysokość);
		gfx.DrawSprite(Pozycja_Owocek_x, Pozycja_Owocek_y, p);	//rysowanie owockow
		Sleep(Czas);
		if (turned == true)
		{

		}
		
		if (gameover == true)
		{
			/*int czyparz = 0;
			while(długość!=0 && wysokość!=0)
			{
				if (czyparz % 2 == 0)
				{
					gfx.DrawSprite(Pozycja_x, Pozycja_y, surf);
					długość = długość - 30;
					wysokość = wysokość - 30;
					Powierzchnia surf = Powierzchnia(długość, wysokość);
				}
				Draw_highscore();
				Draw_Borders();
				iterator1 = 0;
				while (iterator1 < i)	
				{
					gfx.DrawSprite(Tabela_Min_x[iterator1], Tabela_Min_y[iterator1], mina, 3);
					iterator1++;
				}
				czyparz++;
				Sleep(1000);
		gfx.EndFrame();
		gfx.BeginFrame();
				
				
			}*/
			//koniec animacji
			hardmode = false;
			ggg.Play();
			Hardmode_border = 0;
			gfx.DrawSprite(0, 0, gg, 3);
			gameover = false;
			if (turned == false)
				długość = 0;
			else
				wysokość = 0;
			isEaten = true;
			Pozycja_x = 60;
			Pozycja_y = 60;
			Czas = 370;
			iterator1 = 0;
			i = -1;
			Tabela_Min_x.clear();
			Tabela_Min_y.clear();
			bomba = false;
			kierunek = -1;
			turned = false;
			if (highscore > Current_highscore)
				Current_highscore = highscore;
			else;
		}
		gfx.DrawSprite(Pozycja_x, Pozycja_y, surf);	//nasz gracz
		Draw_highscore();

			

}
