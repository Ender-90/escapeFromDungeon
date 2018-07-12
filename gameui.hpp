#pragma once

#include "gameInstance.hpp"

class GameUI{

private:

    GameInstance * gi;
    char c;

    void intro();
    void mainMenu();
    void help();
    void exitGame();

public:

    GameUI();
    void run();

};
