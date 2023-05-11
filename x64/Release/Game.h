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
	int x = 60, y = 60, l = 0, xx = 0, yy = 0, z = 370, i = -1, xxx = 0, yyy = 0, kierunek=-1, h = 30, hs=0,chs=0;
	std::vector<int> ixy;
	std::vector<int> iy;
	bool isEaten = true, gameover = false, bomba = false, turned = false, hardmode = false;
	void zapauza();
	void drawhs();
	void drawborders();

private:
	void ComposeFrame();
	void UpdateModel();
	/********************************/
	/*  User Functions              */
	/********************************/
private:
	int zmienna1=0;
	MainWindow& wnd;
	Graphics gfx;
	Powierzchnia gg = Powierzchnia("gameover.bmp");
	Powierzchnia mina = Powierzchnia("mina.bmp");
	Powierzchnia pauza = Powierzchnia("pausa.bmp");
	Powierzchnia p = Powierzchnia(30, 30);
	Powierzchnia  l0= Powierzchnia("0.bmp");
	Powierzchnia  l1 = Powierzchnia("1.bmp");
	Powierzchnia hss = Powierzchnia("hs.bmp");
	Powierzchnia anim = Powierzchnia("anim.bmp");
	Sound ggg;
	/********************************/
	/*  User Variables              */
	/********************************/
};