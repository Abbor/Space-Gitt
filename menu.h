#pragma once
#include "std_lib_facilities.h"
#include "AnimationWindow.h"
#include "widgets/Button.h"
#include "widgets/TextInput.h"

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

    void newGameBtnCB();
    void loadGameBtnCB();
    void saveGameCB();
    void quitBtnCB();

    public:
    // konstruktør
    Menu(TDT4102::Point position, int width, int height, std::string title);
    ~Menu();

    int level;
    std::string playerName;
};
