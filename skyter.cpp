#include "skyter.h"
Skyter::Skyter(int lengde, int bredde, int posx, int posy, int fartx)
    : Spillobjekt(lengde, bredde, posx, posy), fartx(fartx) {
        TDT4102::AnimationWindow::draw_circle(TDT4102::Point{posx, posy}, bredde);
    }

int Skyter::get_shooter_posx(){
    return posx + bredde/2; //antar her at posx er hjørnet til objekter, og at gunneren er plassert i midten av objektet
}

int Skyter::get_shooter_posy(){
    return posy + lengde; //antar her at posx er hjørnet til objekter, og at gunneren er plassert i midten av objektet
}
