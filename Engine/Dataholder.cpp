#include "Dataholder.h"

 void Dataholder::setPozx(int x) {

    Pozycja_x=x=x;
}

 void Dataholder::setPozy(int x)
{
     Pozycja_y=x;
}

 void Dataholder::setdlugosc(int x)
{
     dlugosc=x;
}
void Dataholder::setPozycjaOwocekx(int x)
{
     Pozycja_Owocek_x=x;
}
 void Dataholder::setPozycjaOwoceky(int x)
{
      Pozycja_Owocek_y=x;
}
 void Dataholder::setczas(int x) {
      Czas=x;
} void Dataholder::seti(int x) {
     i=x;
} void Dataholder::setPozMina_x(int x) {
     Pozycja_Mina_x=x;
} void Dataholder::setPozMinay(int x) {
     Pozycja_Mina_y=x;
} void Dataholder::setkierunek(int x) {
     kierunek=x;
} void Dataholder::setwysokosc(int x) {
     wysokosc=x;
} void Dataholder::sethighscore(int x) {
     highscore=x;
} void Dataholder::setcurrenthighscore(int x) {
     Current_highscore=x;
} void Dataholder::setHardmodeborder(int x) {
     Hardmode_border=x;
} void Dataholder::setIsEaten(bool x) {
     isEaten=x;
} void Dataholder::setgameover(bool x) {
     gameover=x;
} void Dataholder::setbomba(bool x) {
     bomba=x;
} void Dataholder::setturned(bool x) {
     turned=x;
} void Dataholder::sethardmode(bool x) {
     hardmode=x;
}

int Dataholder::getPozx() {

    return Pozycja_x;
}

int Dataholder::getPozy()
{
    return Pozycja_y;
}

int Dataholder::getdlugosc()
{
    return dlugosc;
}
int Dataholder::getPozycjaOwocekx()
{
    return Pozycja_Owocek_x;
}
int Dataholder::getPozycjaOwoceky()
{
    return Pozycja_Owocek_y;
}
int Dataholder::getczas() {
    return Czas;
} int Dataholder::geti() {
    return i;
} int Dataholder::getPozMina_x() {
    return Pozycja_Mina_x;
} int Dataholder::getPozMinay() {
    return Pozycja_Mina_y;
} int Dataholder::getkierunek() {
    return kierunek;
} int Dataholder::getwysokosc() {
    return wysokosc;
} int Dataholder::gethighscore() {
    return highscore;
} int Dataholder::getcurrenthighscore() {
    return Current_highscore;
} int Dataholder::getHardmodeborder() {
    return Hardmode_border;
} bool Dataholder::getIsEaten() {
    return isEaten;
} bool Dataholder::getgameover() {
    return gameover;
} bool Dataholder::getbomba() {
    return bomba;
} bool Dataholder::getturned() {
    return turned;
} bool Dataholder::gethardmode() {
    return hardmode;
}


