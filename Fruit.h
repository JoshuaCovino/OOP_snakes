#ifndef FRUIT_H
#define FRUIT_H
#include <iostream>
#include "Point.h"
#include <vector>
using namespace std;

    /**
        * Fruit
        *
        * Class for the game "Fruit"
        * Fruit have the Position coordinates, the ASCII that represents it
    */
class Fruit {

    protected:
        //location of the fruit
        int xCoordinate;
        int yCoordinate;
        char fruit_char;
        vector<Point> fruitVec;

    public:
    /**
        * Fruit
        *
        * Constructor
        * Unused
    */
        Fruit();
        
    /**
        * Fruit
        *
        * Constructor
        * Fruit constructor that takes in the coords of the first fruit location that is printed on the board
    */    
        Fruit(int xCoord, int yCoord); 
        
    /**
        * setXcoord(int value)
        *
        * Takes in a given int for the first x coord of the fruit
    */
        void setXcoord(int value); //Change the x coord of the fruit
    
    /**
        * setYcoord(int value)
        *
        * Takes in a given int for the first y coord of the fruit
    */
        void setYcoord(int value); //Change the y corrd of the fruit
        
    /**
        * getXcoord()
        *
        * Get the x coord of the fruit
    */
        int getXcoord(); 
        
    /**
        * getYcoord()
        *
        * Get the y coord of the fruit
    */
        int getYcoord(); 
        
    /**
        * get_food_char()
        *
        * Get the food character. Passed to world so world can print it to the board
    */
        char get_food_char(); 
        
    /**
        * food_changes()
        *
        * Pure virtual function that checks if a special fruit has been eaten
    */
        virtual bool food_changes() = 0;
    
    /**
        * getSize()
        *
        * Get the size of the fruitVec 
    */
        int getSize(); 
        
    /**
        * get_fruit_location(int i)
        *
        * Return the location of the bombs
    */
        Point get_fruit_location(int i); 
    
    /**
        * add_new_bomb()
        *
        * Add a new bomb for the Fruit vector, for the Chilli "bomb"
    */    
        void add_new_bomb();
};

#endif