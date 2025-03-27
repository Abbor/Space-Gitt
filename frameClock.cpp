#pragma once
#include "menu.h"

void frameClock() {
    int waitMs = 1000/25;       // venter i så mange millisekunder for å få ca 24fps. 
                                //Antar at programmet bruker noe tid, så deler på 25 i stedet for 24.
    auto start = std::chrono::high_resolution_clock::now();
    while (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - start).count() < waitMs) {
        // Her ventes det. ikke noe som trengs å fylles ut her.
    }
}