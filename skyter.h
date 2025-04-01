#pragma once
#include "spillobjekt.h"

class Skyter : public Spillobjekt{
    protected:
    int fartx;
    
    public:
    Skyter(int lengde, int bredde, int posx, int posy, int fartx);
    int get_shooter_posx();
    void skyt();
};