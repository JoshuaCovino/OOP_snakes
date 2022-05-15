#include "ChilliFruit.h"
#include <iostream>
#include <ncurses.h>
using namespace std;


ChilliFruit::ChilliFruit(){
    xCoordinate = 0;
    yCoordinate = 0;
    fruit_char = 'X';
}

ChilliFruit::ChilliFruit(int xCoord, int yCoord){
    xCoordinate = xCoord;
    yCoordinate = yCoord;
    fruit_char = 'X';
    fruitVec.push_back(Point(yCoordinate,xCoordinate));
}

bool ChilliFruit::food_changes() {
    return false;
}


