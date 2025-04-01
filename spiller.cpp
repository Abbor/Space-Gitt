#include "spiller.h"

Spiller::Spiller(int lengde, int bredde, int posx, int posy, int fartx) : Skyter(lengde, bredde, posx, posy, fartx){}

void Spiller::update(){
    posx += fartx;
}