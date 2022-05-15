#include "Grow_fruit.h"
#include <iostream>
#include <ncurses.h>
using namespace std;

Grow_fruit::Grow_fruit(int xCoord, int yCoord){
    xCoordinate = xCoord;
    yCoordinate = yCoord;
    fruit_char = '#';
}

bool Grow_fruit::food_changes () {
    return true;
}


