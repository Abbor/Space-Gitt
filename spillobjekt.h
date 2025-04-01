#pragma once
#include "AnimationWindow.h"
#include "menu.h"

class Spillobjekt : public Menu {
protected:
int lengde;
int bredde;
int posx;
int posy;

public:

    Spillobjekt(int lengde, int bredde, int posx, int posy) {}
    int getPosx() const;
    int getPosy() const;
    int getLengde() const;
    int getBredde() const;

};