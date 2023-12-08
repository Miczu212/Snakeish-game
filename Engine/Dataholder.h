#pragma once
class Dataholder
{
public:
	void setPozx(int x);
	void setPozy(int x);
	void setdlugosc(int x);
	void setPozycjaOwocekx(int x);
	void setPozycjaOwoceky(int x);
	void setczas(int x);
	void seti(int x);
	void setPozMina_x(int x);
	void setPozMinay(int x);
	void setkierunek(int x);
	void setwysokosc(int x);
	void sethighscore(int x);
	void setcurrenthighscore(int x);
	void setHardmodeborder(int x);
	void setIsEaten(bool x);
	void setgameover(bool x);
	void setbomba(bool x);
	void setturned(bool x);
	void sethardmode(bool x);
	int getPozx();
	int getPozy();
	int getdlugosc();
	int getPozycjaOwocekx();
	int getPozycjaOwoceky();
	int getczas();
	int geti();
	int getPozMina_x();
	int getPozMinay();
	int getkierunek();
	int getwysokosc();
	int gethighscore();
	int getcurrenthighscore();
	int getHardmodeborder();
	bool getIsEaten();
	bool getgameover();
	bool getbomba();
	bool getturned();
	bool gethardmode();


private:
	int Pozycja_x = 60, Pozycja_y = 60, dlugosc = 0, Pozycja_Owocek_x = 0, Pozycja_Owocek_y = 0, Czas = 370, i = -1, Pozycja_Mina_x = 0, Pozycja_Mina_y = 0, kierunek = -1, wysokosc = 30, highscore = 0, Current_highscore = 0;
	bool isEaten = true, gameover = false, bomba = false, turned = false, hardmode = false;
		int Hardmode_border = 0;

};