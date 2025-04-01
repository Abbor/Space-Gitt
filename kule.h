#pragma once
#include "spillobjekt.h"

class Kule : public Spillobjekt{
    protected:
    int farty;

    public:
    Kule(int lengde, int bredde, int posx, int posy, int farty);
    void update();
};