#include <iostream>
#include <vector>
#include <cstdlib>
#include <conio.h>
#include "gameInstance.hpp"


#define ESC_KEY 27
using namespace std;

GameInstance::GameInstance() {
    p = {3, 3, false};
    win = false;
    key = false;
    score = 1000;

    for(int i = 0; i < 20; i++){
        vector<unsigned char> row;
        for(int j = 0; j < 38; j++)
            row.push_back(32);
        actualScreen.push_back(row);
    }
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

        if(this->c == ESC_KEY)
            break;
        else if(this->c == 'w')
            movePlayerOnScreen(0, -1);
        else if(this->c == 's')
            movePlayerOnScreen(0, 1);
        else if(this->c == 'a')
            movePlayerOnScreen(-1, 0);
        else if(this->c == 'd')
            movePlayerOnScreen(1, 0);


        if(this->key && !p.key){
            this->dungeon.clearKey(this->p.x, this->p.y);
            this->p.key = true;
            cout<<"\n"<<"You found a key!";
        }

        if(this->dungeon.getDungeon()[this->p.y][this->p.x] == 'E' && this->key){
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

void GameInstance::movePlayerOnScreen(int x, int y){
    moveIfPossible(this->p, this->actualScreen, this->key, x, y);
    updateScreen(this->p, this->actualScreen, this->dungeon.getDungeon());
    system("cls");
    displayActualScreen(this->actualScreen);
}

void GameInstance::moveIfPossible(Player &p, vector<vector<unsigned char>> &d, bool &k, int x, int y){
    if(d[p.y + y][p.x + x] == 176 || d[p.y + y][p.x + x] == 'E'){
        p.x += x;
        p.y += y;
    }else if(d[p.y + y][p.x + x] == 75){
        d[p.y + y][p.x + x] = 176;
        p.x += x;
        p.y += y;
        k = true;
    }
}

void GameInstance::updateScreen(Player p, vector<vector<unsigned char>> &as, vector<vector<unsigned char>> d){
    for(int y = 0; y < 20; y++){
            for(int x = 0; x < 38; x++)
                as[y][x] = 32;
    }

    for(int y = (p.y - 2); y < (p.y +3); y++) {
        if(y >= 0 && y < 20) {
            for(int x = (p.x - 2); x < (p.x +3); x++){
                if(x >= 0 && x < 38)
                    as[y][x] = d[y][x];
            }
        }
    }
    as[p.y][p.x] = 80;
}

void GameInstance::displayActualScreen(vector<vector<unsigned char>> d) {
    for(int i = 0; i < 20; i++){
            for(int j = 0; j < 38; j++)
                cout<<d[i][j];
            cout<<"\n";
    }
}

