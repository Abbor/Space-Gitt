#pragma once

class Spillobjekt{
private:
int lengde;
int bredde;
int posx;
int posy;

public:
    Spillobjekt(int lengde, int bredde, int posx, int posy);
    int getPosx() const;
    int getPosy() const;
};