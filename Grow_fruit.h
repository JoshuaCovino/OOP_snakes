#ifndef GROW_FRUIT_H
#define GROW_FRUIT_H
#include <iostream>
#include "Fruit.h"
using namespace std;

class Grow_fruit: public Fruit {
    private:

    public:
        Grow_fruit();
        Grow_fruit(int xCoord, int yCoord);
        virtual bool food_changes() override;
};

#endif