#pragma once

#include <vector>

using namespace std;

class Dungeon{

    vector<vector<unsigned char>> maze;

    void generateKey(vector<vector<unsigned char>> &d);

    public:
        Dungeon();
        vector<vector<unsigned char>> getDungeon();
        void clearKey(int x, int y);
};
