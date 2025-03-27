#pragma once
#include "spillobjekt.h"

class Skyter : public Spillobjekt{
    public:
    int fartx;
    
    private:
    Skyter(int lengde, int bredde, int posx, int posy, int fartx);
    int get_shooter_pos();
    void skyt();
};