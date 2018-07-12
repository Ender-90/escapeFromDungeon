#include <iostream>
#include <cstdlib>
#include <conio.h>

#include "gameui.hpp"

using namespace std;

GameUI::GameUI(){

    this->gi = nullptr;
    c = 69;
}

void GameUI::intro(){

    system("cls");
    cout<<"\n\n\n\n"<<"          Welcome to\n\n     Escape From Dungeon";
    cout<<"\n\n\n\n\n"<<"Press ENTER to continue...";

    while(c != 13){
        c = _getch();
    }
}

void GameUI::exitGame(){

    system("cls");
    cout<<"\n\n"<<"     Thank You for playing \n      Escape From Dungeon";
    cout<<"\n\n\n"<<"        Created by Ender\n             2018";
    cout<<"\n\n\n\n\n"<<"Press ENTER to continue...";

    while(c != 13){
        c = _getch();
    }
}

void GameUI::mainMenu(){

    while(this-> c != '3'){

        system("cls");
        cout<<"\n"<<"     Escape From Dungeon"<<"\n\n"<<"1. Play"<<"\n"<<"2. Help"<<"\n"<<"3. Exit";
        c = _getch();

        if(c == '1'){
            this->gi = new GameInstance;
            gi->run();
            delete gi;
            this->gi = nullptr;
        }

        if(c == '2'){
            help();
        }
    }
}

void GameUI::help(){
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

    while(c != 13){
        c = _getch();
    }
}

void GameUI::run(){

    intro();
    mainMenu();
    exitGame();

}
