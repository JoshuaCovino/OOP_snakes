#include "Snake.h"
#include "World.h"
#include "Point.h"
#include <iostream>
#include <vector>
#include <ncurses.h>
using namespace std;

Snake::Snake(int size){

    //This is creating the snake array with size body parts
    for(int i = 0; i < size; i++){
        snakevec.push_back(Point(20,10+i));
    }
}

int Snake::getSize(){
    return snakevec.size();
}

Point Snake:: get_head(){
    return snakevec[0];
}

Point Snake:: get_tail(){
    return snakevec[snakevec.size()-1];
}

void Snake:: vector_pop_back(){
    snakevec.pop_back();
}


Point Snake:: get_snake_part(int i){
    return snakevec[i];
}

void Snake :: setDirection(Direction direction){
    this->direction = direction;
}
Direction Snake :: getDirection(){
    return direction;
}

void Snake:: onMove(Direction choice){
    int deltaX = 0;
    int deltaY = 0;

    switch (choice) {

        case Direction::up:
        deltaX = 0;
        deltaY = -1;
        break;

        case Direction::down:
        deltaX = 0;
        deltaY = 1;
        break;

        case Direction::left:
        deltaX = -1;
        deltaY = 0;
        break;

        case Direction::right:
        deltaX = 1;
        deltaY = 0;
        break;

        case Direction::invalid:
        break;
    }

    snakevec.insert(snakevec.begin(),Point(snakevec[0].x+deltaX,snakevec[0].y+deltaY));

}

