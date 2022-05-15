#ifndef SNAKE_H
#define SNAKE_H
#include "Point.h"
#include "Direction.h"
#include <iostream>
#include <vector>
#include <ncurses.h>
using namespace std;

    /**
        * Fruit
        *
        * Class of the Snake object in game
        * Holds the snake vector that holds the position of the snake segments, along with its direction (from the direction class)
    */
class Snake{

   private:

    Direction direction; //Stores the direction of the snakes movement
    vector<Point> snakevec; //Coordinate of Snake segments stored as points (x,y)coordinates
    
    public:
    
    
    /**
        * Snake
        *
        * Constructor
        * input initial size of snake
    */
    Snake(int size);
    
    /**
        * onCOllide()
        *
        * Updates the x and y coords of the snake head of snake collides, interacting with other game elements in world
    */
    void onCollide();   
    
    /**
        * onMove(Direction offset)
        *
        * Given a direction, it will update the coordinates of the snake vector
    */
    void onMove(Direction offset);
    
    /**
        * getSize()
        *
        * Returns the size of the array
    */
    int getSize();      
    
    /**
        * vector_pop_back()
        *
        * deletes the last element of the snake vector
    */
    void vector_pop_back(); 
    
    /**
        * vector_pop_back()
        *
        * Returns coordinate position of head of Snake
    */
    Point get_head();   
    
    /**
        * vector_pop_back()
        *
        * Returns point from snake vector
    */
    Point get_snake_part(int i);   
    
    /**
        * get_tail()
        *
        * Returns the coords of the last element of the snake vector
    */
    Point get_tail(); 
    
    /**
        * setDirection(Direction direction)
        *
        * Sets the direction of the users last input
    */
    void setDirection(Direction direction); 
    
    /**
        * Direction getDirection()
        *
        * Returns the direction of the users last input.
    */
    Direction getDirection(); 
};




#endif