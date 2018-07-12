#include "dungeon.hpp"

#include <cstdlib>
#include <ctime>

Dungeon::Dungeon(){

    maze = {
        201,205,205,205,205,205,205,205,205,205,205,187, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32,201,205,205,205,205,205,205,205,205,205,205,205,205,187, // 0
        186,176,176,176,176,176,176,176,176,176,176,186, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32,186,176,176,176,176,176,176,176,176,176,176,176,176,186, // 1
        186,176,176,176,176,176,176,176,176,176,176,200,205,205,205,205,205,205,205,205,205,205,205,205,188,176,201,205,205,205,205,205,205,205,205,187,176,186, // 2
        186,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,186, 32,201,205,205,205,205,205,205,188,176,186, // 3
        186,176,176,176,176,176,176,176,176,176,176,201,205,205,205,205,205,187,176,201,205,205,205,205,205,205,188, 32,186,176,176,176,176,176,176,176,176,186, // 4
        186,176,176,176,176,176,176,176,176,176,176,186, 32, 32, 32, 32, 32,186,176,186, 32, 32,201,205,205,205,205,205,188,176,201,205,205,205,205,205,205,188, // 5
        186,176,176,176,176,176,176,176,176,176,176,186, 32, 32, 32, 32, 32,186,176,186, 32, 32,186,176,176,176,176,176,176,176,200,205,205,205,205,205,205,205, // 6
        200,205,205,205,205,205,205,205,187,176,201,188, 32, 32, 32, 32, 32,186,176,186, 32, 32,200,205,205,205,205,187,176,176,176,176,176,176,176,176,176, 69, // 7
         32, 32, 32, 32, 32, 32, 32, 32,186,176,186, 32, 32,201,205,205,205,188,176,200,205,205,205,205,205,205,205,202,203,205,187,176,201,205,205,205,205,205, // 8
         32, 32, 32, 32, 32, 32, 32, 32,186,176,186, 32, 32,186,176,176,176,176,176,176,176,176,176,176,176,176,176,176,186, 32,186,176,200,205,205,205,205,187, // 9
         32, 32,201,205,205,205,205,205,188,176,186, 32, 32,186,176,201,205,205,205,205,187,176,201,205,205,205,187,176,186, 32,186,176,176,176,176,176,176,186, //10
         32, 32,186,176,176,176,176,176,176,176,186, 32, 32,186,176,186, 32,201,205,205,188,176,186, 32, 32, 32,186,176,200,205,206,205,205,205,205,187,176,186, //11
         32, 32,186,176,201,205,205,205,187,176,200,205,205,188,176,186, 32,186,176,176,176,176,186, 32, 32, 32,186,176,176,176,186, 32, 32, 32, 32,186,176,186, //12
         32, 32,186,176,186, 32, 32, 32,186,176,176,176,176,176,176,186, 32,186,176,201,205,205,188, 32, 32, 32,200,205,187,176,186, 32, 32, 32, 32,186,176,186, //13
         32, 32,186,176,186, 32, 32, 32,200,205,205,205,205,205,205,188, 32,186,176,186, 32,201,205,205,205,205,187, 32,186,176,200,205,205,205,205,188,176,186, //14
         32, 32,186,176,186, 32,201,205,205,205,205,205,205,205,205,187, 32,186,176,186, 32,186,176,176,176,176,186, 32,186,176,176,176,176,176,176,176,176,186, //15
         32, 32,186,176,186, 32,186,176,176,176,176,176,176,176,176,186, 32,186,176,186, 32,200,205,205,187,176,186, 32,200,205,205,205,205,205,187,176,176,186, //16
         32, 32,186,176,200,205,188,176,176,176,176,176,176,176,176,186, 32,186,176,200,205,205,205,205,188,176,200,205,205,205,205,205,205,205,188,176,176,186, //17
         32, 32,186,176,176,176,176,176,176,176,176,176,176,176,176,186, 32,186,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,186, //18
         32, 32,200,205,205,205,205,205,205,205,205,205,205,205,205,188, 32,200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188, //19
        };

        generateKey(maze);
}

void Dungeon::generateKey(std::vector <unsigned char> &d){
    srand(time(NULL));
    bool keyGen = false;
    while(!keyGen){
        int keyPosition = rand() % (38*20 - 1);
        if(d[keyPosition] == 176){
            d[keyPosition] = 75;
            keyGen = true;
        }
    }

}

std::vector <unsigned char> Dungeon::getDungeon(){
    return this->maze;
}

void Dungeon::clearKey(int pos){
    this->maze[pos] = 176;
}