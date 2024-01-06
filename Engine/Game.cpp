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
	gameoversound(L"gameover.mp3")
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
	gfx.DrawSprite(0, 0, Tablica_Powierzchni.pauza, 3);
}
void Game::Draw_Borders()
{
	for (int op = 0; op < 1080 - Tablica_danych.getHardmodeborder(); op++)
	{
		gfx.PutPixel(op, 779 - Tablica_danych.getHardmodeborder(), Colors::Red);
	}
	for (int po = 0; po < 780 - Tablica_danych.getHardmodeborder(); po++)
	{
		gfx.PutPixel(1079 - Tablica_danych.getHardmodeborder(), po, Colors::Red);
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
void Game::GetDirection()
{
	if (GetAsyncKeyState(0x48))
	{
		Tablica_danych.sethardmode(true);
	}
	else if (GetAsyncKeyState(VK_UP))
	{
		Tablica_danych.setkierunek(1);
	}

	else if (GetAsyncKeyState(VK_DOWN))
	{
		Tablica_danych.setkierunek(2);
	}

	else if (GetAsyncKeyState(VK_LEFT))
	{
		Tablica_danych.setkierunek(3);

	}

	else if (GetAsyncKeyState(VK_RIGHT))
	{
		Tablica_danych.setkierunek(4);

	}
}
void Game::Draw_highscore()
{
	gfx.DrawSprite(0, 0, Tablica_Powierzchni.hss, 3);
	if (Tablica_danych.geti() == 0)
		gfx.DrawSprite(0, 30, Tablica_Powierzchni.cyfra1, 3);
	else if (Tablica_danych.geti() == 1)
	{
		Tablica_danych.sethighscore(1);

		gfx.DrawSprite(0, 30, Tablica_Powierzchni.cyfra2, 3);
	}
	else if (Tablica_danych.geti() == 2)
	{
		Tablica_danych.sethighscore(  2);
		Powierzchnia  l2 = Powierzchnia("2.bmp");
		gfx.DrawSprite(0, 30, l2, 3);
	}
	else if (Tablica_danych.geti() == 3)
	{
		Tablica_danych.sethighscore(  3);
		Powierzchnia  l3 = Powierzchnia("3.bmp");
		gfx.DrawSprite(0, 30, l3, 3);
	}
	else if (Tablica_danych.geti() == 4) {
		Tablica_danych.sethighscore(  4);
		Powierzchnia  l4 = Powierzchnia("4.bmp");
		gfx.DrawSprite(0, 30, l4, 3);
	}
	else if (Tablica_danych.geti() == 5)
	{
		Tablica_danych.sethighscore(  5);
		Powierzchnia  l5 = Powierzchnia("5.bmp");
		gfx.DrawSprite(0, 30, l5, 3);
	}
	else if (Tablica_danych.geti() == 6) {
		Tablica_danych.sethighscore(  6);
		Powierzchnia  l6 = Powierzchnia("6.bmp");
		gfx.DrawSprite(0, 30, l6, 3);
	}
	else if (Tablica_danych.geti() == 7)
	{
		Tablica_danych.sethighscore(  7);
		Powierzchnia  l7 = Powierzchnia("7.bmp");
		gfx.DrawSprite(0, 30, l7, 3);
	}
	else if (Tablica_danych.geti() == 8)
	{
		Tablica_danych.sethighscore(  8);
		Powierzchnia  l8 = Powierzchnia("8.bmp");
		gfx.DrawSprite(0, 30, l8, 3);
	}
	else if (Tablica_danych.geti() == 9)
	{
		Tablica_danych.sethighscore(  9);
		Powierzchnia  l9 = Powierzchnia("9.bmp");
		gfx.DrawSprite(0, 30, l9, 3);
	}
	else if (Tablica_danych.geti() == 10)
	{
		Tablica_danych.sethighscore(  10);
		gfx.DrawSprite(0, 30, Tablica_Powierzchni.cyfra2, 3);
		gfx.DrawSprite(30, 30, Tablica_Powierzchni.cyfra1, 3);
	}
	else if (Tablica_danych.geti() == 11)
	{
		Tablica_danych.sethighscore(  11);
		gfx.DrawSprite(0, 30, Tablica_Powierzchni.cyfra2, 3);
		gfx.DrawSprite(30, 30, Tablica_Powierzchni.cyfra2, 3);
	}
	else if (Tablica_danych.geti() == 12)
	{
		Tablica_danych.sethighscore(  12);
		Powierzchnia  l2 = Powierzchnia("2.bmp");
		gfx.DrawSprite(0, 30, Tablica_Powierzchni.cyfra2, 3);
		gfx.DrawSprite(30, 30, l2, 3);
	}
	else if (Tablica_danych.geti() == 13)
	{
		Tablica_danych.sethighscore(  13);
		Powierzchnia  l3 = Powierzchnia("3.bmp");
		gfx.DrawSprite(0, 30, Tablica_Powierzchni.cyfra2, 3);
		gfx.DrawSprite(30, 30, l3, 3);
	}
	else if (Tablica_danych.geti() == 14)
	{
		Tablica_danych.sethighscore(  14);
		Powierzchnia  l4 = Powierzchnia("4.bmp");
		gfx.DrawSprite(0, 30, Tablica_Powierzchni.cyfra2, 3);
		gfx.DrawSprite(30, 30, l4, 3);
	}
	else if (Tablica_danych.geti() == 15)
	{
		Tablica_danych.sethighscore(  15);
		Powierzchnia  l5 = Powierzchnia("5.bmp");
		gfx.DrawSprite(0, 30, Tablica_Powierzchni.cyfra2, 3);
		gfx.DrawSprite(30, 30, l5, 3);
	}
	else if (Tablica_danych.geti() == 16)
	{
		Tablica_danych.sethighscore(  16);
		Powierzchnia  l6 = Powierzchnia("6.bmp");
		gfx.DrawSprite(0, 30, Tablica_Powierzchni.cyfra2, 3);
		gfx.DrawSprite(30, 30, l6, 3);
	}
	else if (Tablica_danych.geti() == 17)
	{
		Tablica_danych.sethighscore(  17);
		Powierzchnia  l7 = Powierzchnia("7.bmp");
		gfx.DrawSprite(0, 30, Tablica_Powierzchni.cyfra2, 3);
		gfx.DrawSprite(0, 30, l7, 3);
	}

	gfx.DrawSprite(0, 0, Tablica_Powierzchni.hss, 3);
	if (Tablica_danych.getcurrenthighscore( ) == 0)
		gfx.DrawSprite(120, 2, Tablica_Powierzchni.cyfra1, 3);
	else if (Tablica_danych.getcurrenthighscore( ) == 1)
	{


		gfx.DrawSprite(120, 2, Tablica_Powierzchni.cyfra2, 3);
	}
	else if (Tablica_danych.getcurrenthighscore( ) == 2)
	{

		Powierzchnia  l2 = Powierzchnia("2.bmp");
		gfx.DrawSprite(120, 2, l2, 3);
	}
	else if (Tablica_danych.getcurrenthighscore( ) == 3)
	{

		Powierzchnia  l3 = Powierzchnia("3.bmp");
		gfx.DrawSprite(120, 2, l3, 3);
	}
	else if (Tablica_danych.getcurrenthighscore( ) == 4) {

		Powierzchnia  l4 = Powierzchnia("4.bmp");
		gfx.DrawSprite(120, 2, l4, 3);
	}
	else if (Tablica_danych.getcurrenthighscore( ) == 5)
	{

		Powierzchnia  l5 = Powierzchnia("5.bmp");
		gfx.DrawSprite(120, 2, l5, 3);
	}
	else if (Tablica_danych.getcurrenthighscore( ) == 6) {

		Powierzchnia  l6 = Powierzchnia("6.bmp");
		gfx.DrawSprite(120, 2, l6, 3);
	}
	else if (Tablica_danych.getcurrenthighscore( ) == 7)
	{

		Powierzchnia  l7 = Powierzchnia("7.bmp");
		gfx.DrawSprite(120, 2, l7, 3);
	}
	else if (Tablica_danych.getcurrenthighscore( ) == 8)
	{

		Powierzchnia  l8 = Powierzchnia("8.bmp");
		gfx.DrawSprite(120, 2, l8, 3);
	}
	else if (Tablica_danych.getcurrenthighscore( ) == 9)
	{

		Powierzchnia  l9 = Powierzchnia("9.bmp");
		gfx.DrawSprite(120, 2, l9, 3);
	}
	else if (Tablica_danych.getcurrenthighscore( ) == 10)
	{

		gfx.DrawSprite(120, 2, Tablica_Powierzchni.cyfra2, 3);
		gfx.DrawSprite(150, 2, Tablica_Powierzchni.cyfra1, 3);
	}
	else if (Tablica_danych.getcurrenthighscore( ) == 11)
	{

		gfx.DrawSprite(120, 2, Tablica_Powierzchni.cyfra2, 3);
		gfx.DrawSprite(150, 2, Tablica_Powierzchni.cyfra2, 3);
	}
	else if (Tablica_danych.getcurrenthighscore( ) == 12)
	{

		Powierzchnia  l2 = Powierzchnia("2.bmp");
		gfx.DrawSprite(120, 2, Tablica_Powierzchni.cyfra2, 3);
		gfx.DrawSprite(150, 2, l2, 3);
	}
	else if (Tablica_danych.getcurrenthighscore( ) == 13)
	{

		Powierzchnia  l3 = Powierzchnia("3.bmp");
		gfx.DrawSprite(120, 2, Tablica_Powierzchni.cyfra2, 3);
		gfx.DrawSprite(150, 2, l3, 3);
	}
	else if (Tablica_danych.getcurrenthighscore( ) == 14)
	{

		Powierzchnia  l4 = Powierzchnia("4.bmp");
		gfx.DrawSprite(120, 2, Tablica_Powierzchni.cyfra2, 3);
		gfx.DrawSprite(150, 2, l4, 3);
	}
	else if (Tablica_danych.getcurrenthighscore( ) == 15)
	{

		Powierzchnia  l5 = Powierzchnia("5.bmp");
		gfx.DrawSprite(120, 2, Tablica_Powierzchni.cyfra2, 3);
		gfx.DrawSprite(150, 2, l5, 3);
	}
	else if (Tablica_danych.getcurrenthighscore( ) == 16)
	{

		Powierzchnia  l6 = Powierzchnia("6.bmp");
		gfx.DrawSprite(120, 2, Tablica_Powierzchni.cyfra2, 3);
		gfx.DrawSprite(150, 2, l6, 3);
	}
	else if (Tablica_danych.getcurrenthighscore( ) == 17)
	{

		Powierzchnia  l7 = Powierzchnia("7.bmp");
		gfx.DrawSprite(120, 2, Tablica_Powierzchni.cyfra2, 3);
		gfx.DrawSprite(150, 2, l7, 3);
	}
}
void Game::Turn()
{
	if (GetAsyncKeyState(0x45))
	{
		Tablica_danych.setturned(!Tablica_danych.getturned());
		int temp;
		temp = Tablica_danych.getdlugosc();
		Tablica_danych.setdlugosc(Tablica_danych.getwysokosc());
		Tablica_danych.setwysokosc(temp);
		if (Tablica_danych.getPozy() + Tablica_danych.getwysokosc() > 770)
		{
			Tablica_danych.setgameover(true);
		}
		else if (Tablica_danych.getPozx() + Tablica_danych.getdlugosc() > 1060)
		{
			Tablica_danych.setgameover(true);
		}

	}
	else if (GetAsyncKeyState(0x51))
	{
		Tablica_danych.setturned(!Tablica_danych.getturned());
		int temp;
		temp = Tablica_danych.getdlugosc();
		Tablica_danych.setdlugosc(Tablica_danych.getwysokosc());
		Tablica_danych.setwysokosc(temp);
		if (Tablica_danych.getPozy() + Tablica_danych.getwysokosc() > 770)
		{
			Tablica_danych.setgameover(true);
		}
		else if (Tablica_danych.getPozx() + Tablica_danych.getdlugosc() > 1060)
		{
			Tablica_danych.setgameover(true);
		}
	}
}
void Game::IsitGameover()
{
	int p = Tablica_danych.getPozy() - 30;
	if (Tablica_danych.getkierunek() == 1 && p < 0)
	{
		Tablica_danych.setgameover(true);
	}
	if (Tablica_danych.getkierunek() == 1 && (p < 60 && Tablica_danych.getPozx() < 180)) // sa inty zamiast zmiennych poniewaz sprawdza element gorny
	{
		Tablica_danych.setgameover(true);
	}
	if (Tablica_danych.getturned() == true)
	{
		p = Tablica_danych.getPozy() + Tablica_danych.getwysokosc();
	}
	else {

		p = Tablica_danych.getPozy() + 30;
	}
	if (p > 770 - Tablica_danych.getHardmodeborder() && Tablica_danych.getkierunek() == 2)
	{
		Tablica_danych.setgameover(true);
	}
	p = Tablica_danych.getPozx() - 30;
	if (Tablica_danych.getkierunek() == 3 && p < 0)
	{
		Tablica_danych.setgameover(true);
	}
	if (Tablica_danych.getkierunek() == 3 && p < 180 && Tablica_danych.getPozy() < 60) // sa inty zamiast zmiennych poniewaz sprawdza element gorny
	{
		Tablica_danych.setgameover(true);
	}
	p = Tablica_danych.getdlugosc() + Tablica_danych.getPozx() + 30;
	if (Tablica_danych.getkierunek() == 4 && p >= gfx.ScreenWidth - Tablica_danych.getHardmodeborder())

	{
		Tablica_danych.setgameover(true);
	}
}

void Game::RandomizeOwocekLocation()
{
	if (Tablica_danych.getIsEaten() == true)
	{
		if (Tablica_danych.geti() == -1)
		{
		}
		if (Tablica_danych.getturned() == false)
			Tablica_danych.setdlugosc(Tablica_danych.getdlugosc() + 30);
		else
			Tablica_danych.setwysokosc(Tablica_danych.getwysokosc() + 30);
		Tablica_danych.setczas(Tablica_danych.getczas() - 20);  // z kazdym zjedzonym owockiem zmienna Tablica_danych.getczas() siê zmniejsza, skutkuj¹c przyœpieszeniem rozgrywki
		Tablica_danych.setPozycjaOwocekx((rand() % ((gfx.ScreenWidth - 30 - Tablica_danych.getHardmodeborder()) / 30)) * 30);
		Tablica_danych.setPozycjaOwoceky((rand() % ((gfx.ScreenHeight - 30 - Tablica_danych.getHardmodeborder()) / 30)) * 30);
		if (Tablica_danych.geti() == -1)
		{
			Tablica_danych.setPozycjaOwocekx((rand() % 10) * 30);
			Tablica_danych.setPozycjaOwoceky((rand() % 10) * 30);
		}
		while (Tablica_danych.getPozycjaOwoceky() < 60)
		{
			if (Tablica_danych.getPozycjaOwocekx() < 180) {

				srand(time(NULL));
				Tablica_danych.setPozycjaOwoceky((rand() % 26) * 30);
				if (Tablica_danych.geti() == -1)
				{
					Tablica_danych.setPozycjaOwoceky((rand() % 10) * 30);
				}
			}
			else
				break;
		}
		if (Tablica_danych.gethardmode() == true)	//sprawdza czy jest odpalony tryb hardmode zeby pomniejszac granice z zjedzeniem owocka
		{
			Tablica_danych.setHardmodeborder(Tablica_danych.getHardmodeborder() + 15);
		}
		Tablica_danych.seti(Tablica_danych.geti() + 1);
		Tablica_danych.setIsEaten(false);
		Tablica_danych.setbomba(true);
		Tabela_Min_x.clear();
		Tabela_Min_y.clear();
	}
}
void Game::Draw_Mines()
{
	while (iterator1 < Tablica_danych.geti())	//rysowanie min
	{
		gfx.DrawSprite(Tabela_Min_x[iterator1], Tabela_Min_y[iterator1], Tablica_Powierzchni.mina, 3);
		iterator1++;
	}
	iterator1 = 0;
}
void Game::RandomizeMineLocation()
{
	if (Tablica_danych.getbomba() == true)
	{
		int iterator2 = 0;
		Tablica_danych.setbomba(false);
		while (iterator1 < Tablica_danych.geti())
		{
			Tablica_danych.setPozMina_x((rand() % 35) * 30);
			Tablica_danych.setPozMinay((rand() % 25) * 30);
			int iterator3 = 0;
			while (																				//Upewnienie siê ¿e mina nie pojawi sie w:
				(Tablica_danych.getPozMina_x() == Tablica_danych.getPozycjaOwocekx() && Tablica_danych.getPozMinay() == Tablica_danych.getPozycjaOwoceky()) ||		//W owocku
				(Tablica_danych.getPozMina_x() == Tablica_danych.getPozx() && Tablica_danych.getPozMinay() == Tablica_danych.getPozy()) ||						//-nas
				(Tablica_danych.getPozMina_x() == Tablica_danych.getPozx() - 30 && Tablica_danych.getPozMinay() == Tablica_danych.getPozy()) ||				//na lewo od nas
				(Tablica_danych.getPozMina_x() == Tablica_danych.getPozx() && Tablica_danych.getPozMinay() == Tablica_danych.getPozy() - 30) ||				//nad nami
				(Tablica_danych.getPozMina_x() == Tablica_danych.getPozx() && Tablica_danych.getPozMinay() == Tablica_danych.getPozy() + 30 + Tablica_danych.getwysokosc()) ||		//pod nami
				(Tablica_danych.getPozMina_x() == Tablica_danych.getPozx() + 30 + Tablica_danych.getdlugosc() && Tablica_danych.getPozMinay() == Tablica_danych.getPozy()))		//na prawo od nas
			{


				srand(time(NULL));
				Tablica_danych.setPozMina_x((rand() % 35) * 30);
				Tablica_danych.setPozMinay((rand() % 25) * 30);

			}


			Tabela_Min_x.push_back(Tablica_danych.getPozMina_x());
			Tabela_Min_y.push_back(Tablica_danych.getPozMinay());
			if (Tablica_danych.getturned() == false)
			{
				while (iterator2 != Tablica_danych.getdlugosc())
				{
					if (Tablica_danych.getPozMina_x() == Tablica_danych.getPozx() + iterator2 && Tablica_danych.getPozMinay() == Tablica_danych.getPozy())
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
				while (iterator2 != Tablica_danych.getwysokosc())
				{
					if (Tablica_danych.getPozMina_x() == Tablica_danych.getPozx() && Tablica_danych.getPozMinay() == Tablica_danych.getPozy() + iterator2)
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

	if (Tablica_danych.getturned() == false)
	{
		while (iterator3 != Tablica_danych.getdlugosc())
		{
			if (iterator3 + Tablica_danych.getPozx() == Tablica_danych.getPozycjaOwocekx() && Tablica_danych.getPozy() == Tablica_danych.getPozycjaOwoceky())	//sprawdzanie czy w danej klatce zjedzono owocek
				Tablica_danych.setIsEaten(true);
			iterator3 += 30;
		}
		iterator3 = 0;
		while (iterator3 != Tablica_danych.getdlugosc())
		{
			if (Tablica_danych.getbomba() == true)
			{
				while (iterator1 < Tablica_danych.geti() - 1)
				{
					if (Tablica_danych.getPozx() + iterator3 == Tabela_Min_x[iterator1] && Tablica_danych.getPozy() == Tabela_Min_y[iterator1])
					{
						if (czydalrade == false)
							Tablica_danych.setgameover(true);
						czydalrade = false;

					}
					iterator1++;
				}
				iterator1 = 0;
				iterator3 += 30;
			}
			else
			{
				while (iterator1 < Tablica_danych.geti())
				{
					if (Tablica_danych.getPozx() + iterator3 == Tabela_Min_x[iterator1] && Tablica_danych.getPozy() == Tabela_Min_y[iterator1])
					{
						Tablica_danych.setgameover(true);

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
		while (iterator3 != Tablica_danych.getwysokosc())
		{
			if (Tablica_danych.getPozx() == Tablica_danych.getPozycjaOwocekx() && Tablica_danych.getPozy() + iterator3 == Tablica_danych.getPozycjaOwoceky())
				Tablica_danych.setIsEaten(true);
			iterator3 += 30;
		}
		iterator3 = 0;
		while (iterator3 != Tablica_danych.getwysokosc())
		{
			if (Tablica_danych.getbomba() == true)
			{
				while (iterator1 < Tablica_danych.geti() - 1)	//sprawdzanie czy gracz znalazl sie w jakiejs z min
				{
					if (Tablica_danych.getPozx() == Tabela_Min_x[iterator1] && Tablica_danych.getPozy() + iterator3 == Tabela_Min_y[iterator1])
					{
						if (czydalrade == false)
							Tablica_danych.setgameover(true);
						czydalrade = false;

					}
					iterator1++;
				}
				iterator1 = 0;
				iterator3 += 30;
			}
			else
			{
				while (iterator1 < Tablica_danych.geti())
				{
					if (Tablica_danych.getPozx() == Tabela_Min_x[iterator1] && Tablica_danych.getPozy() + iterator3 == Tabela_Min_y[iterator1])
					{
						Tablica_danych.setgameover(true);

					}
					iterator1++;
				}
				iterator1 = 0;
				iterator3 += 30;
			}
		}
	}
}
void Game::UpdateOnEaten()
{
	Draw_Mines();
	RandomizeOwocekLocation();
	RandomizeMineLocation();
	
}
void Game::OnGameover()
{
	if (Tablica_danych.getgameover() == true)
	{
		Tablica_danych.sethardmode(false);
		Tablica_danych.setHardmodeborder(0);
		Tablica_danych.setgameover(false);
		gameoversound.Play();
		gfx.DrawSprite(0, 0, Tablica_Powierzchni.gameoverimage, 3);
		if (Tablica_danych.getturned() == false)
			Tablica_danych.setdlugosc(0);
		else
			Tablica_danych.setwysokosc(0);
		Tablica_danych.setIsEaten(true);
		Tablica_danych.setPozx(60);
		Tablica_danych.setPozy(60);
		Tablica_danych.setczas(370);
		iterator1 = 0;
		Tablica_danych.seti(-1);
		Tabela_Min_x.clear();
		Tabela_Min_y.clear();
		Tablica_danych.setbomba(false);
		Tablica_danych.setkierunek(-1);
		Tablica_danych.setturned(false);
		if (Tablica_danych.gethighscore() > Tablica_danych.getcurrenthighscore())
			Tablica_danych.setcurrenthighscore(Tablica_danych.gethighscore());
		else;
	}
}
void Game::ComposeEndFrame()
{
	if (Tablica_danych.getdlugosc() == 0 || Tablica_danych.getwysokosc() == 0)
	{
		Tablica_danych.setdlugosc(30);
		Tablica_danych.setwysokosc(30);
	}
	Tablica_Powierzchni.gracz = Powierzchnia(Tablica_danych.getdlugosc(), Tablica_danych.getwysokosc());
	gfx.DrawSprite(Tablica_danych.getPozycjaOwocekx(), Tablica_danych.getPozycjaOwoceky(), Tablica_Powierzchni.owocek);	//rysowanie owocku
	Sleep(Tablica_danych.getczas());
	if (Tablica_danych.getturned() == true)
	{
	}
}
void Game::Move()
{
	if (Tablica_danych.getkierunek() == 1)
	{
		Tablica_danych.setPozy(Tablica_danych.getPozy() - 30);
	}

	else if (Tablica_danych.getkierunek() == 2)
	{
		Tablica_danych.setPozy(Tablica_danych.getPozy() + 30);
	}
	else if (Tablica_danych.getkierunek() == 4)
	{
		Tablica_danych.setPozx(Tablica_danych.getPozx() + 30);
	}
	else if (Tablica_danych.getkierunek() == 3)
	{
		Tablica_danych.setPozx(Tablica_danych.getPozx() - 30);
	}
}
void Game::UpdateModel()
{
	GetDirection();
	IsitGameover();
	Turn();


}
void Game::ComposeFrame() {
	
	srand(time(NULL));
	Move();												
	Draw_Borders();
	UpdateOnEaten();
	ComposeEndFrame();
	OnGameover();		
	gfx.DrawSprite(Tablica_danych.getPozx(), Tablica_danych.getPozy(), Tablica_Powierzchni.gracz);	//nasz gracz
	Draw_highscore();

			

}
