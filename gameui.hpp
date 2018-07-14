#pragma once

#include "gameInstance.hpp"

/** \brief It serves as the starting point of the entire application.

    GameUI is responsible for main menu too.
*/

class GameUI{

public:
    GameUI();
    void run();

private:
    GameInstance * gi;
    char userInput;

    void intro();
    void displayWelcome();

    void mainMenu();
    void displayMenu();
    void runGame();
    void help();
    void displayHelp();

    void exitGame();
    void displayFarewell();

    void continueAfterEnterKey();
};
