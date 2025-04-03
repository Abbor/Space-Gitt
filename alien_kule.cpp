#include "alien_kule.h"

Alien_kule::Alien_kule(int lengde, int bredde, int posx, int posy, int farty) : Kule(lengde, bredde, posx, posy, farty){
    TDT4102::AnimationWindow::draw_rectangle(TDT4102::Point{posx, posy}, bredde, lengde, Color::dark_red);
}