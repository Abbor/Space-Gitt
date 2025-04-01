#pragma once
#include "skyter.h"
class Spiller : public Skyter{
    public:
    Spiller(int lengde, int bredde, int posx, int posy, int fartx);
    void update();
};