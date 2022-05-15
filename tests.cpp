#include "tests.h"
#include "World.h"
#include "ChilliFruit.h"
#include <assert.h>
#include "Direction.h"
#include <ncurses.h>
#include <vector>
#include "Point.h"


tests:: tests() {

}

// Board tests
//
//
//

void tests:: test_get_board_height() {

    Board testBoard(10);

    assert(testBoard.get_board_height()==10);

}

void tests:: test_get_board_width() {

    Board testBoard(10);

    assert(testBoard.get_board_width()==25);

}


//  Fruit tests
//
//
//


void tests:: test_fruit_setXcoord() {

    ChilliFruit fruitTest(10,10);

    fruitTest.setXcoord(5);

    assert(fruitTest.getXcoord() == 5);

}

void tests:: test_fruit_setYcoord() {

    ChilliFruit fruitTest(10,10);

    fruitTest.setYcoord(5);

    assert(fruitTest.getYcoord() == 5);

}

void tests:: test_fruit_get_food_char() {

    ChilliFruit fruitTest(10,20);

    assert(fruitTest.get_food_char()=='#');

}

void tests:: test_fruit_getSize() {

    ChilliFruit fruitTest(10,20);



    assert(fruitTest.getSize()==5); /////////

}


//Snake tests
//
//
//




void tests:: test_snake_onMove() {

    Snake testSnake(3);

    Point testPoint=testSnake.get_head();
    testSnake.onMove(Direction::up);
    Point movePoint=testSnake.get_head();

    assert(movePoint.y==testPoint.y-1);


}

void tests:: test_snake_getSize() {

    Snake testSnake(5);

    assert(testSnake.getSize()==5);

}


void tests:: test_snake_setDirection() {

    Snake testSnake(3);
    testSnake.setDirection(Direction::up);

    assert(testSnake.getDirection()==Direction::up);

}


