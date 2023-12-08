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
#include"Powierzchniaholder.h"
#include"Dataholder.h"
class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
public:
	void ComposeFrame();
	void UpdateModel();
	void zapauza();
	void Draw_highscore();
	void Draw_Borders();
	/********************************/
	/*  User Functions              */
	/********************************/
private:
	std::vector<int> Tabela_Min_x;
	std::vector<int> Tabela_Min_y;
	Dataholder Tablica_danych;
	MainWindow& wnd;
	Graphics gfx;
	Powierzchniaholder Tablica_Powierzchni;
	Sound gameoversound;
	/********************************/
	/*  User Variables              */
	/********************************/
};