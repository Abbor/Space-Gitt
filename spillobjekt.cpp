#include "spillobjekt.h"

//Konstruktør
Spillobjekt::Spillobjekt(int lengde, int bredde, int posx, int posy) : lengde(lengde), bredde(bredde), posx(posx), posy(posy) {}

int Spillobjekt::getPosx() const{
    return posx; 
}

int Spillobjekt::getPosy() const{
    return posy; 
}

int Spillobjekt::getLengde() const{
    return lengde;
}

int Spillobjekt::getBredde() const{
    return bredde;
}