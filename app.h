#pragma once
#include "std_lib_facilities.h"
#include "spiller.h"
#include "alien.h"
#include "Alien_kule.h"
#include "Spiller_kule.h"
#include "skjold.h"

extern int WIDTH;
extern int HEIGHT;



class App{
    vector<Spiller> spillere; //Oppretter en vector for hver type objekt som er med i spillet
    vector<Alien> aliens;
    vector<Skjold> skjold;
    vector<Alien_kule> alienkuler; 
    vector<Spiller_kule> spillerkuler; 


    int kule_lengde = 8;
    int kule_bredde = 3;
    int kule_farty = 10;

    bool gameover = false;

    public:
    App(); //bredden og høyden til skjærmen
    
    void opprett_skjold(); //fulført
    void opprett_aliens(); //fulført

    void alien_skyt(); //fulført
    void spiller_skyt(); //fulført

    void handle_events(); 

    void update(); // delvis fulført

    void check_out_of_bounds(); //delvis fulført

    void draw();

    void next_level();

    void game_over();

    void run(); //delvis fulført




};
