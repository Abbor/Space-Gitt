#include "kule.h"

Kule::Kule(int lengde, int bredde, int posx, int posy, int farty) : Spillobjekt(lengde, bredde, posx, posy), farty(farty){}

void Kule::update(){
    posy += farty;
}
