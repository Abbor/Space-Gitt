#pragma once
#include "skyter.h"

class Alien : public Skyter {
    private:
    int farty;
    public:
    Alien(int lengde, int bredde, int posx, int posy, int fartx, int farty);
    void bytt_reting_x();
    void move_down();
    void update();
};