#pragma once
#include"Powierzchnia.h"
class Powierzchniaholder
{
public:
	Powierzchniaholder();
	Powierzchnia gameoverimage = Powierzchnia("gameover.bmp");
	Powierzchnia mina = Powierzchnia("mina.bmp");
	Powierzchnia pauza = Powierzchnia("pausa.bmp");
	Powierzchnia owocek = Powierzchnia(30, 30);
	Powierzchnia  cyfra1 = Powierzchnia("0.bmp");
	Powierzchnia  cyfra2 = Powierzchnia("1.bmp");
	Powierzchnia hss = Powierzchnia("hs.bmp");
	Powierzchnia anim = Powierzchnia("anim.bmp");
private:

};