#pragma once
#include <vector>

class Dungeon{

    std::vector <unsigned char> maze;

    void generateKey(std::vector <unsigned char> &d);

    public:
        Dungeon();
        std::vector <unsigned char> getDungeon();
        void clearKey(int pos);
};
