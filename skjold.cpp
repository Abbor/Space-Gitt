#include "skjold.h"

Skjold::Skjold(int lengde, int bredde, int posx, int posy) : Spillobjekt(lengde, bredde, posx, posy) {
    TDT4102::AnimationWindow::draw_rectangle(TDT4102::Point{posx, posy}, bredde, lengde, Color::yellow_green);
}