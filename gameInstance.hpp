#pragma once

#include <iostream>
#include <vector>

#include "dungeon.hpp"
#include "player.hpp"

using namespace std;

class GameInstance {

public:
    GameInstance();
    void run();

private:
    Player p;
    Dungeon dungeon;

    char c;
    int check;
    int score;
    bool win;
    bool key;

    vector<vector<unsigned char>> actualScreen;

    void play();
    void victory();
    void defeat();
    void updateScreen(Player p, vector<vector<unsigned char>> &as, vector<vector<unsigned char>> d);
    void moveIfPossible(Player &p, vector<vector<unsigned char>> &d, bool &k, int x, int y);
    void movePlayerOnScreen(int x, int y);
    void displayActualScreen(vector<vector<unsigned char>> d);
};
