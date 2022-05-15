#ifndef POINT_H
#define POINT_H
#include <iostream>

    /**
        * Point
        *
        * Class for the coordinates of the snake segments
        * X and Y coordinates are then put into the snake vector
    */
class Point {

    public:

    int x, y;

    /**
        * Point
        *
        * Constructor
    */
    Point();
    
    /**
        * Point
        *
        * Constructor, input x and y coordinate for coresponding row,column 
    */
    Point(int col, int row);
};


#endif