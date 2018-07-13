#include <iostream>
#include <cstdlib>
#include <conio.h>

#include "gameui.hpp"

#define ENTER_KEY 13

using namespace std;

GameUI::GameUI() {
    this->gi = 0;
    userInput = 42;
}

void GameUI::run() {
    intro();
    mainMenu();
    exitGame();
}

void GameUI::intro() {
    displayWelcome();
    while(userInput != ENTER_KEY)
        userInput = _getch();
}

void GameUI::displayWelcome() {
    system("cls");
    cout<<"\n\n\n\n"<<"          Welcome to\n\n     Escape From Dungeon";
    cout<<"\n\n\n\n\n"<<"Press ENTER to continue...";
}

void GameUI::mainMenu() {
    while(this->userInput != '3') {
        displayMenu();
        userInput = _getch();
        if(userInput == '1')
            runGame();
        else if(userInput == '2')
            help();
    }
}

void GameUI::displayMenu() {
    system("cls");
    cout<<"\n"<<"     Escape From Dungeon"<<"\n\n"<<"1. Play"<<"\n"<<"2. Help"<<"\n"<<"3. Exit";
}

void GameUI::runGame() {
    this->gi = new GameInstance;
    gi->run();
    delete gi;
    this->gi = 0;
}

void GameUI::help() {
    displayHelp();
    while(userInput != ENTER_KEY)
        userInput = _getch();
}

void GameUI::displayHelp(){
    system("cls");
    cout<<"  HELP"<<"\n\n";
    cout<<"You have to get out from maze. First you should find the (K)ey."<<"\n";
    cout<<"When you find it, you can go to (E)xit."<<"\n\n\n\n";
    cout<<"CONTROL KEYS"<<"\n\n";
    cout<<" w - up"<<"\n";
    cout<<" s - down"<<"\n";
    cout<<" a - left"<<"\n";
    cout<<" d - right"<<"\n";
    cout<<" ESC - quit"<<"\n\n";

    cout<<" Press ENTER to continue...";
}

void GameUI::exitGame(){
    displayFarewell();
    while(userInput != ENTER_KEY)
        userInput = _getch();
}

void GameUI::displayFarewell(){
    system("cls");
    cout<<"\n\n"<<"     Thank You for playing \n      Escape From Dungeon";
    cout<<"\n\n\n"<<"        Created by Ender\n             2018";
    cout<<"\n\n\n\n\n"<<"Press ENTER to continue...";
}
