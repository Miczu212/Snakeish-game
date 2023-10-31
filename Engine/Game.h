/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
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
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Powierzchnia.h"
#include<vector>
#include"Sound.h"
class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
	int Pozycja_x = 60, Pozycja_y = 60, dlugosc = 0, Pozycja_Owocek_x = 0, Pozycja_Owocek_y = 0, Czas = 370, i = -1, Pozycja_Mina_x = 0, Pozycja_Mina_y = 0, kierunek=-1, wysokosc = 30, highscore =0, Current_highscore =0;
	std::vector<int> Tabela_Min_x;
	std::vector<int> Tabela_Min_y;
	bool isEaten = true, gameover = false, bomba = false, turned = false, hardmode = false;
	void zapauza();
	void Draw_highscore();
	void Draw_Borders();

private:
	void ComposeFrame();
	void UpdateModel();
	/********************************/
	/*  User Functions              */
	/********************************/
private:
	int Hardmode_border =0;
	MainWindow& wnd;
	Graphics gfx;
	Powierzchnia gameoverimage = Powierzchnia("gameover.bmp");
	Powierzchnia mina = Powierzchnia("mina.bmp");
	Powierzchnia pauza = Powierzchnia("pausa.bmp");
	Powierzchnia owocek = Powierzchnia(30, 30);
	Powierzchnia  cyfra1= Powierzchnia("0.bmp");
	Powierzchnia  cyfra2 = Powierzchnia("1.bmp");
	Powierzchnia hss = Powierzchnia("hs.bmp");
	Powierzchnia anim = Powierzchnia("anim.bmp");
	Sound gameoversound;
	/********************************/
	/*  User Variables              */
	/********************************/
};