#ifndef DIRECTION_H
#define DIRECTION_H

/**
    * Direction
    *
    * Class for the direction of the snake
    * Each corresponding Direction has a enum value
*/    
enum class Direction{ //enum class that allows us to avoid magic numbers. Each direction the user can travel is given a number.
    up    = 1,
    down  = 2,
    left  = 3,
    right = 4,
    invalid =-1,

};

#endif