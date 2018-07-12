#pragma once

#include <iostream>
#include <vector>

#include "dungeon.hpp"
#include "player.hpp"

using namespace std;

class GameInstance {

private:
    Player p;
    Dungeon dungeon;

    char c;
    int check;
    int score;
    bool win;
    bool key;

    vector <unsigned char> actualScreen;

    void play();
    void victory();
    void defeat();
    void updateScreen(Player p, vector <unsigned char> &as, vector <unsigned char> d);
    void displayActualScreen(vector <unsigned char> d);
    void moveIfPossible(Player &p, vector <unsigned char> &d, bool &k, int n);
    void movePlayerOnScreen(int valueToCheck);

public:
    GameInstance();
    void run();

};
