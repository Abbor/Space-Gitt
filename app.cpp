#include "app.h"

int WIDTH = 700;
int HEIGHT = 1000;



App::App(){
    int spiller_liv = 3;
    int spiller_bredde = 30; int spiller_lengde = 30; int spiller_posx = WIDTH/2; int spiller_posy = HEIGHT - HEIGHT/8; int spiller_fartx = 5;

    Spiller spiller = Spiller(spiller_bredde, spiller_lengde, spiller_posx, spiller_posy, spiller_fartx);
    spillere.push_back(spiller);

    opprett_aliens();
    opprett_skjold();
}

void App::opprett_skjold(){
    int bredde = 30;
    int lengde = 10;
    int y = HEIGHT*(3/4);
    
    for(int x = 50; x < WIDTH;x +=60){ //litt forvirrende siden vectoren heter skjold, derfor skjoldo
        Skjold skjoldo = Skjold(bredde, lengde, x,y);
        skjold.push_back(skjoldo);
    }
}


void App::opprett_aliens(){
    int bredde = 20;
    int lengde = 20;
    int fartx = 1;
    int farty = 6;
    for(int x = 1;x<7;x++){
        int bredde = (WIDTH/8)*x;
        for(int y = 1; y<4;y++){
            int hoyde = (HEIGHT/12) * y;
            Alien alien = Alien(bredde, lengde, x,y,fartx,farty);
            aliens.push_back(alien);
        }
    }
    
}

void App::spiller_skyt(){
    int posx = spillere.at(0).get_shooter_posx();
    int posy = spillere.at(0).get_shooter_posy();

    Spiller_kule kule = Spiller_kule(kule_lengde, kule_bredde, posx, posy,kule_farty*-1);
    spillerkuler.push_back(kule);

}

void App::alien_skyt(){
    for(int i = 0;i<aliens.size();i++){
        std::random_device rd;
		std::default_random_engine generator(rd());
		std::uniform_int_distribution<int> distribution(1, 100);
		int terningkast = distribution(generator);
        if(terningkast == 6){
            int posx = aliens.at(i).get_shooter_posx();
            int posy = aliens.at(i).get_shooter_posy();
            
            Alien_kule kule = Alien_kule(kule_lengde, kule_bredde, posx, posy, kule_farty);
            alienkuler.push_back(kule);

        }
    }
}

void App::update(){
    bool alien_out_of_bounds = false;

    for (int i = 0; i < spillere.size(); i++){
        spillere.at(i).update();
    }

    for (int i = 0; i < aliens.size(); i++){
        Alien alien = aliens.at(i);
        alien.update();
        if(alien.getPosx() <= 0 || alien.getPosx() + alien.getBredde() > WIDTH){
            alien_out_of_bounds = true;
        }

        if(alien_out_of_bounds == true){
            for(int i = 0; i<aliens.size();i++){
                aliens.at(i).bytt_reting_x();
                aliens.at(i).move_down();
            }
        }
    }

    for (int i = 0; i < alienkuler.size(); i++){
        alienkuler.at(i).update();
    }

    for (int i = 0; i < spillerkuler.size(); i++){
        spillerkuler.at(i).update();
    }
}


void App::check_out_of_bounds(){
    //Fjerner kuler som beveger seg utenfor banen
    for (auto it = alienkuler.begin(); it != alienkuler.end();) {
        if (it->getPosy() >= HEIGHT) {
            it = alienkuler.erase(it);  
        } else {
            ++it;
        }
    }

    for (auto it = spillerkuler.begin(); it != spillerkuler.end();) {
        if (it->getPosy() <= HEIGHT) {
            it = spillerkuler.erase(it);  
        } else {
            ++it;
        }
    }
}

bool App::check_collition(Spillobjekt spillobjekt1, Spillobjekt spillobjekt2){
    return spillobjekt1.getPosx() < spillobjekt2.getPosx() + spillobjekt2.getBredde() &&
           spillobjekt1.getPosx() + spillobjekt1.getBredde() > spillobjekt2.getPosx() &&
           spillobjekt1.getPosy() < spillobjekt2.getPosy() + spillobjekt2.getLengde() &&
           spillobjekt1.getPosy() + spillobjekt1.getLengde() > spillobjekt2.getPosy();

}

void App::group_collide_spiller_alienkuler(){
    for (auto it_spiller = spillere.begin(); it_spiller != spillere.end();){
        for (auto it_kule = alienkuler.begin(); it_kule != alienkuler.end();){
            if(check_collition(*it_kule, *it_spiller)){
                alienkuler.erase(it_kule);
                spiller_liv--;
            }
        }
    }
}

void App::group_collide_aliens_spillerkuler(){
    for (auto it_alien = aliens.begin(); it_alien!= aliens.end();){
        for (auto it_kule = spillerkuler.begin(); it_kule != spillerkuler.end();){
            if(check_collition(*it_kule, *it_alien)){
                spillerkuler.erase(it_kule);
                aliens.erase(it_alien);
            }
        }
    }
}

void App::group_collide_skjold_alienkuler(){
    for (auto it_skjold = skjold.begin(); it_skjold != skjold.end();){
        for (auto it_kule = alienkuler.begin(); it_kule != alienkuler.end();){
            if(check_collition(*it_kule, *it_skjold)){
                alienkuler.erase(it_kule);
                skjold.erase(it_skjold);
            }
        }
    }
}

void App::group_collide_skjold_spillerkuler(){
    for (auto it_skjold = skjold.begin(); it_skjold!= skjold.end();){
        for (auto it_kule = spillerkuler.begin(); it_kule != spillerkuler.end();){
            if(check_collition(*it_kule, *it_skjold)){
                spillerkuler.erase(it_kule);
                skjold.erase(it_skjold);
            }
        }
    }
}

void App::run(){
    while (gameover == false){
        //Klokke.tick()



    } 
}