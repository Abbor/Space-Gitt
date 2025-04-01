#include "spiller.h"

Spiller::Spiller(int lengde, int bredde, int posx, int posy, int fartx) : Skyter(lengde, bredde, posx, posy, fartx){
    TDT4102::AnimationWindow::draw_circle(TDT4102::Point{posx, posy}, bredde/2, Color::firebrick);
}

void Spiller::update(){
    if (TDT4102::AnimationWindow::is_key_down(KeyboardKey::LEFT)) {
        posx -= fartx;
    } else if (TDT4102::AnimationWindow::is_key_down(KeyboardKey::RIGHT)) {
        posx += fartx;
    }
}