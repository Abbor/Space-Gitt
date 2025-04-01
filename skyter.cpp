#include "skyter.h"
Skyter::Skyter(int lengde, int bredde, int posx, int posy, int fartx)
    : Spillobjekt(lengde, bredde, posx, posy), fartx(fartx) {}

int Skyter::get_shooter_posx(){
    return posx + bredde/2; //antar her at posx er hjørnet til objekter, og at gunneren er plassert i midten av objektet
}

void Skyter::skyt(){
    //Kaller en eller annen funksjon som oppretter et kuleobjekt gitt med posisjonen til skyteren og posy
}