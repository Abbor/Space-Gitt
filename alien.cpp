#include "alien.h"

Alien::Alien(int lengde, int bredde, int posx, int posy, int fartx, int farty) : Skyter(lengde, bredde, posx, posy, fartx), farty(farty){}

void Alien::update(){
    posx += fartx;
    posy += farty;
}