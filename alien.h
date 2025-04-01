#include "skyter.h"
#pragma once

class Alien : public Skyter {
    private:
    int farty;
    public:
    Alien(int lengde, int bredde, int posx, int posy, int fartx, int farty);
    void update();
};
