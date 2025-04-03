#pragma once
#include "std_lib_facilities.h"
#include "AnimationWindow.h"
#include "widgets/Button.h"
#include "widgets/TextInput.h"
#include "widgets/TextBox.h"


class Menu : public TDT4102::AnimationWindow
{
    private:
    // Diverse konstanter for plassering av knapper på skjermen
    static constexpr int dist = 40;
    static constexpr int btnW = 100;
    static constexpr int btnH = 20;
    static constexpr int txtW = 300;

    TDT4102::Button quitBtn;
    TDT4102::Button newGameBtn;
    TDT4102::Button loadGameBtn;
    TDT4102::TextInput playerNameInput;
    TDT4102::Button saveGameBtn;

    void newGameBtnCB();    // Destruerer menyen når 
    void loadGameBtnCB();
    void saveGameCB();
    void quitBtnCB();


    public:
    // konstruktør
    Menu() : Menu({10, 10}, 600, 400, "Default Menu") {}
    Menu(TDT4102::Point position, int width, int height, std::string title);
    ~Menu();

    void hideMenu();
    void showMenu();

    int level;
    std::string playerName;
    int highscore;


    void createScoreboard();

};
