#include "Point.h"
#include <iostream>


Point::Point(){
    
    // Set to 0,0
    x = 0;
    y = 0;
}

Point::Point(int col, int row){
    x = col;
    y = row;
}