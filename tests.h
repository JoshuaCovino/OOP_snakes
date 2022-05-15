#ifndef _TESTS_H
#define _TESTS_H

#include "World.h"
#include <assert.h>

class tests {

  public:
  
  
        tests();
        //tests for functions in the Board header
        void test_get_board_height();
        void test_get_board_width();
        //tests for functions in the Fruit header
        void test_fruit_setXcoord();
        void test_fruit_setYcoord();
        void test_fruit_get_food_char();
        void test_fruit_getSize();
        //tests for functions in the Snake header
        void test_snake_onMove();
        void test_snake_getSize();
        void test_snake_setDirection();



};

#endif