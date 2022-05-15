#include "Fruit.h"
#include <vector>
#include <iostream>
#include <ncurses.h>
using namespace std;

Fruit::Fruit(){
    xCoordinate = 0;
    yCoordinate = 0;
    fruit_char = '?';


}
Fruit::Fruit(int xCoord, int yCoord){
    xCoordinate = xCoord;
    yCoordinate = yCoord;
    fruit_char = '?';
    fruitVec.push_back(Point(yCoord,xCoord));
}
void Fruit::setXcoord(int value){
    xCoordinate = value;
}
void Fruit:: setYcoord(int value){
    yCoordinate = value;
}
int Fruit:: getXcoord(){
    return xCoordinate; 
}
int Fruit::getYcoord(){
    return yCoordinate;
}
char Fruit :: get_food_char(){
    return fruit_char;
}
bool Fruit::food_changes() {
    return true;
}

int Fruit::getSize(){
    return fruitVec.size();
}

Point Fruit:: get_fruit_location(int i){
    return fruitVec[i];
}

void Fruit::add_new_bomb(){
    fruitVec.push_back(Point(yCoordinate,xCoordinate));
}


