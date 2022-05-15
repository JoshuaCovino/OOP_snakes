#ifndef CHILLIFRUIT_H
#define CHILLIFRUIT_H
#include <iostream>
#include "Fruit.h"
#include "Point.h"
using namespace std;

    /**
        * ChilliFruit
        *
        * Class, inherits from Fruit
        * Used as a negative user interact element
        * Game over on impact with snake
    */
class ChilliFruit: public Fruit {
    private:

    public:
    
    /**
        * ChilliFruit
        *
        * Constructor of ChilliFruit object
    */
        ChilliFruit();
        
    /**
        * ChilliFruit
        *
        * Constructor of ChilliFruit object
        * Object takes in the coordinates of its spawn location
    */ 
        ChilliFruit(int xCoord, int yCoord);
        
        
    /**
        * food_changes
        *
        * Boolean function, returns false when run to show fruit has changed position
    */
        virtual bool food_changes() override;
};

#endif