#include <iostream>
#include <vector>
#include <cstdlib>
#include <conio.h>
#include "gameInstance.hpp"

using namespace std;

GameInstance::GameInstance(){

    p = {(3*38) + 3, false};
    win = false;
    key = false;
    score = 1000;

    vector <unsigned char> temporaryScreen ((38*20), 32);
    actualScreen = temporaryScreen;

}

void GameInstance::run(){
    play();

    if(win){
        victory();
    } else {
        defeat();
    }
}

void GameInstance::play(){

    system("cls");
    updateScreen(this->p, this->actualScreen, this->dungeon.getDungeon());
    displayActualScreen(this->actualScreen);

    while(true){
        this->c = _getch();
        if(this->score > 0){
            this->score --;
        }

        if(this->c == 27)
            break;
        else if(this->c == 'w'){
            movePlayerOnScreen(-38);
        }else if(this->c == 's'){
            movePlayerOnScreen(38);
        }else if(this->c == 'a'){
            movePlayerOnScreen(-1);
        }else if(this->c == 'd'){
            movePlayerOnScreen(1);
        }

        if(this->key && !p.key){
            this->dungeon.clearKey(this->p.pos);
            this->p.key = true;
            cout<<"\n"<<"You found a key!";
        }

        if(this->dungeon.getDungeon()[this->p.pos] == 'E' && this->key){
            this->win = true;
            break;
        }

        if(this->score == 0){
            break;
        }
    }
}

void GameInstance::victory(){
    system("cls");
    unsigned char tmp [] = {
    '\n',
    '\n',
    '\n',
    32,32,32,32,32,32,32,32,32,32,'V','I','C','T','O','R','Y','!'
    };

    for(int i = 0; i < 21; i++){
        cout<<tmp[i];
    }

    cout<<"\n\n"<<"Your score: "<<this->score<<"\n\n";
    _getch();
}

void GameInstance::defeat(){
    system("cls");
    unsigned char tmp [] = {
    '\n',
    '\n',
    '\n',
    32,32,32,32,32,32,32,32,32,32,'Y','O','U',32,'L','O','O','S','E','!'
    };

    for(int i = 0; i < 23; i++){
        cout<<tmp[i];
    }
    _getch();
}

void GameInstance::movePlayerOnScreen(int valueToCheck){
    moveIfPossible(this->p, this->actualScreen, this->key, valueToCheck);
    updateScreen(this->p, this->actualScreen, this->dungeon.getDungeon());
    system("cls");
    displayActualScreen(this->actualScreen);
}

void GameInstance::moveIfPossible(Player &p, vector <unsigned char> &d, bool &k, int n){

    if(d[p.pos + n] == 176 || d[p.pos + n] == 'E'){
        p.pos += n;

    }else if(d[p.pos + n] == 75){
        d[p.pos + n] = 176;
        p.pos += n;
        k = true;
    }
}

void GameInstance::updateScreen(Player p, vector <unsigned char> &as, vector <unsigned char> d){
    for(int i = 0; i < 38*20; i++)
        as[i] = 32;

    as[p.pos] = 80;


    //  Check for 2 lines above player

    if(p.pos - 78 >= 0 && (p.pos - 78) % 38 < 36){
        as[p.pos - 78] = d[p.pos - 78];
    }
    if(p.pos - 77 >= 0 && (p.pos - 77) % 38 < 37){
        as[p.pos - 77] = d[p.pos - 77];
    }
    if(p.pos - 76 > 0){
        as[p.pos - 76] = d[p.pos - 76];
    }
    if(p.pos - 75 > 0 && (p.pos - 75) % 38 > 1){
        as[p.pos - 75] = d[p.pos - 75];
    }
    if(p.pos - 74 > 0 && (p.pos - 74) % 38 > 2){
        as[p.pos - 74] = d[p.pos - 74];
    }

    //  Check for 1 line above player

    if(p.pos - 40 >= 0 && (p.pos - 40) % 38 < 36){
        as[p.pos - 40] = d[p.pos - 40];
    }
    if(p.pos - 39 >= 0 && (p.pos - 39) % 38 < 37){
        as[p.pos - 39] = d[p.pos - 39];
    }
    if(p.pos - 38 > 0){
        as[p.pos - 38] = d[p.pos - 38];
    }
    if(p.pos - 37 > 0 && (p.pos - 37) % 38 > 1){
        as[p.pos - 37] = d[p.pos - 37];
    }
    if(p.pos - 36 > 0 && (p.pos - 36) % 38 > 2){
        as[p.pos - 36] = d[p.pos - 36];
    }

    // Check for player's line

    if((p.pos - 2) % 38 < 36){
        as[p.pos - 2] = d[p.pos - 2];
    }
    if((p.pos - 1) % 38 < 37){
        as[p.pos - 1] = d[p.pos - 1];
    }
    if((p.pos + 1) % 38 > 1){
        as[p.pos + 1] = d[p.pos + 1];
    }
    if((p.pos + 2) % 38 > 2){
        as[p.pos + 2] = d[p.pos + 2];
    }

    //  Check for 1 line below player

    if(p.pos + 36 < 38*20 && (p.pos + 36) % 38 < 36){
        as[p.pos + 36] = d[p.pos + 36];
    }
    if(p.pos + 37 < 38*20 && (p.pos + 37) % 38 < 37){
        as[p.pos + 37] = d[p.pos + 37];
    }
    if(p.pos + 38 < 38*20){
        as[p.pos + 38] = d[p.pos + 38];
    }
    if(p.pos + 39 < 38*20 && (p.pos + 39) % 38 > 1){
        as[p.pos + 39] = d[p.pos + 39];
    }
    if(p.pos + 40 < 38*20 && (p.pos + 40) % 38 > 2){
        as[p.pos + 40] = d[p.pos + 40];
    }

    //  Check for 2 lines below player

    if(p.pos + 74 < 38*20 && (p.pos + 74) % 38 < 36){
        as[p.pos + 74] = d[p.pos + 74];
    }
    if(p.pos + 75 < 38*20 && (p.pos + 75) % 38 < 37){
        as[p.pos + 75] = d[p.pos + 75];
    }
    if(p.pos + 76 < 38*20){
        as[p.pos + 76] = d[p.pos + 76];
    }
    if(p.pos + 77 < 38*20 && (p.pos + 77) % 38 > 1){
        as[p.pos + 77] = d[p.pos + 77];
    }
    if(p.pos + 78 < 38*20 && (p.pos + 78) % 38 > 2){
        as[p.pos + 78] = d[p.pos + 78];
    }

}

void GameInstance::displayActualScreen(vector <unsigned char> d){
    for(int i = 0; i < 20; i++){
            for(int j = 0; j < 38; j++)
                cout<< d[(i*38) + j];
            cout<<"\n";
    }
}

