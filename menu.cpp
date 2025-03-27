#include "menu.h"

Menu::Menu(TDT4102::Point position, int width, int height, std::string title):
    TDT4102::AnimationWindow{position.x, position.y, width, height, title},
    newGameBtn(TDT4102::Point{dist, dist}, btnW, btnH, "New Game"),
    loadGameBtn(TDT4102::Point{dist, 2 * dist + btnH}, btnW, btnH, "Load Game"),
    quitBtn(TDT4102::Point{width - dist - btnW, dist}, btnW, btnH, "Quit"),
    playerNameInput(TDT4102::Point{dist, 3*dist + 2 * btnH}, txtW, btnH, "PlayerName"),
    saveGameBtn(TDT4102::Point{width - dist - btnW, dist * 2 + btnH}, btnW, btnH, "Save game")
{
    add(newGameBtn);
    add(loadGameBtn);
    add(quitBtn);
    add(playerNameInput);
    add(saveGameBtn);

    quitBtn.setCallback(std::bind(&Menu::quitBtnCB, this));
    loadGameBtn.setCallback(std::bind(&Menu::loadGameBtnCB, this));
    newGameBtn.setCallback(std::bind(&Menu::newGameBtnCB, this));
    saveGameBtn.setCallback(std::bind(&Menu::saveGameCB, this));
}


Menu::~Menu() {
    delete &newGameBtn;
    delete &loadGameBtn;
    delete &playerNameInput;
    delete &quitBtn;
    delete &saveGameBtn;
}


void Menu::hideMenu() {
    newGameBtn.setVisible(false);
    loadGameBtn.setVisible(false);
    playerNameInput.setSize(0, 0);

    newGameBtn.setCallback(nullptr);
    loadGameBtn.setCallback(nullptr);
}


void Menu::showMenu() {
    newGameBtn.setVisible(true);
    loadGameBtn.setVisible(true);
    playerNameInput.setSize(txtW, btnH);

    loadGameBtn.setCallback(std::bind(&Menu::loadGameBtnCB, this));
    newGameBtn.setCallback(std::bind(&Menu::newGameBtnCB, this));
}


// --------------------Callback-funksjoner--------------------------
// -----------------------------------------------------------------


void Menu::quitBtnCB() { 
    Menu::~Menu();
    close();
}


void Menu::newGameBtnCB() {
    playerName = playerNameInput.getText();
    // New game
    Menu::hideMenu();
}


void Menu::loadGameBtnCB() {
    if (!std::filesystem::exists("Saved_games")) {
        std::cerr << "Filen Saved_games finnes ikke. \n";
        return; 
    }
    std::ifstream ifs("Saved_games");
    if (ifs.is_open()) {
        std::string levelStr;
        std::getline(ifs, levelStr);
        std::getline(ifs, playerName);
        level = std::stoi(levelStr);
        // Legg til level og playername i en annen klasse
    }
    Menu::hideMenu();
}


void Menu::saveGameCB() {
    std::ofstream ofs("Saved_games");
    if (!ofs.is_open()) {
        std::cerr  << "Kunne ikke åpne filen " << "Saved_games" << ". \n";
    }
    // Hent verdier
    ofs << level << std::endl;
    ofs << playerName << std::endl;

    std::cout << "Spillet er lagret i " << "Saved_games" << std::endl;
}