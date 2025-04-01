#include "alien.h"
#include "app.h"

Alien::Alien(int lengde, int bredde, int posx, int posy, int fartx, int farty) : Skyter(lengde, bredde, posx, posy, fartx), farty(farty){}

void Alien::bytt_reting_x(){
    fartx = fartx*-1;
}

void Alien::move_down(){
    posy += farty;
}

void Alien::update(){
    posx += fartx;
}