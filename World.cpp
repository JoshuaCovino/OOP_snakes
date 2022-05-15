#include "World.h"
#include "Snake.h"
#include "Point.h"
#include "Board.h"
#include "Fruit.h"
#include "ChilliFruit.h"
#include "Grow_fruit.h"
#include <iostream>
#include <vector>
#include <ncurses.h>
#include <cstdlib>
#include <ctime>
#include <assert.h>
#include <unistd.h>

using namespace std;

World::World(int size){
    //creating objects
    snake = new Snake(3);
    board = new Board(size);
    fruit = new Grow_fruit(30,15);
    bomb = new ChilliFruit(5,5);
    snakechar = 'o';
    game_over = false;
    got_fruit = false;
    points = 0;
    valid_fruit = fruit->food_changes();
    valid_bomb = bomb->food_changes();
    current_movement = Direction::invalid; //This line is telling the complier to wait for an input before moving for the first time.
    keypad(board->getWindow(),true);       //ncurses function that lets users use the keyboard.
    noecho();                              //ncurses doesn't draw directly to the screen
    curs_set(FALSE);                       //Stops the flashing curser
    nodelay(board->getWindow(), true);
    wtimeout(board->getWindow(),250);      //This controls the speed of the game


    while(!isOver())       //Creating a while loop so the game runs

    {
        game_input();      //Take in input and process it.
        state_update();    //Update the game
        redraw();          //Redraw the window so the thing moves

        if (game_over == true){
            //delete snake;
            //delete board;
            //delete fruit;
            //delete bomb;
            clear();
            points = points*13;
            mvprintw(5,5,"Congratulations, your total score was %d", points);
            mvprintw(10,5, "Game Over, press any key to quit!");
            getch();
        }
    }
}

void World:: game_input(){
   Direction temp_direction = get_direction_input(); //We're capturing the input from the user
   snake->setDirection(temp_direction); //passing it to the snake class so it can update vector
}



void World:: state_update(){

    print_food(fruit);
    print_food(bomb);

    for(int i = 0; i < bomb->getSize(); i++){
        Point fruit_location = bomb->get_fruit_location(i);
        board->addAt(fruit_location.y,fruit_location.x,bomb->get_food_char());
    }

    move(); //move the snake

    for(int i = 0; i < snake->getSize(); i++){          //drawing the snake onto the screen
         Point snakebody = snake->get_snake_part(i);
         board->addAt(snakebody.y,snakebody.x,snakechar);
    }
    collision();
}

void World:: redraw(){
    board->refresh();
}

bool World:: isOver(){
    return game_over;
}

void World :: delete_tail(){
    Point snaketail = snake->get_tail();
    char blank_space = ' ';
    board->addAt(snaketail.y,snaketail.x,blank_space);
    snake->vector_pop_back();
}

Direction World::get_direction_input(){
  int choice = board->getInput();

    switch(choice){
        case KEY_UP:
            if(current_movement != Direction::down){
                current_movement = Direction::up;
            }
            return current_movement;

        case KEY_DOWN:
            if(current_movement != Direction::up){
                current_movement = Direction::down;
            }
            return current_movement;

        case KEY_LEFT:
            if(current_movement != Direction::right){
                current_movement = Direction::left;
            }
            return current_movement;

        case KEY_RIGHT:
            if(current_movement != Direction::left){
                current_movement = Direction::right;
            }
            return current_movement;

        default:
            return current_movement;
    }
}

void World :: move(){

    if(snake->getDirection() != Direction::invalid){ //Checking if the direction has changed
    current_movement = snake->getDirection();
    }
    snake->onMove(current_movement);
    if(got_fruit == false){
       delete_tail();

    }
}

void World:: collision(){

    Point snakehead = snake->get_head();

     //This is going to check if the snake has hit the side of the box or some food
    if(snakehead.x < 1 || snakehead.x > board->get_board_width()-2 || snakehead.y < 1 || snakehead.y > board->get_board_height()-2 ){
        game_over = true;
    }

    //This is going to check to see if the snake has hit itself
    for(int i = 3; i < snake->getSize(); i++){
        Point snakebody = snake->get_snake_part(i);
        if (snakehead.y == snakebody.y && snakehead.x == snakebody.x){
            game_over = true;
        }
    }

    //Next we have to check if the snake's head has hit the food.
    if(snakehead.y == fruit->getYcoord() && snakehead.x == fruit->getXcoord()){
        if(valid_fruit == false){
            game_over = true;
        }
        got_fruit = true;
        points++;
        if(points % 3 == 0){
            generate_new_food_location(bomb);
            bomb->add_new_bomb();
        }
        generate_new_food_location(fruit);
    }
    else{
        got_fruit = false;
    }

        //check if the bomb has been hit
    for(int i = 0; i < bomb->getSize(); i++){
        Point bomb_coord = bomb->get_fruit_location(i);
        if(snakehead.y == bomb_coord.y && snakehead.x == bomb_coord.x){
            if(valid_bomb == false){
            game_over = true;
            }
        }
    }
}

void World :: generate_new_food_location(Fruit *check){

    //while(true) is an infinite loop
        while(true){
        int temp_height = rand()%board->get_board_height()+1;
        int temp_width = rand()%board->get_board_width()+1;

        //We don't want the food to be generated on the snake or the border so we're going to do two checks.
        //The continue means that its going to go back to the start of the while loop and gen new food.
        for(int i = 0; i < snake->getSize(); i++){
        Point snakebody = snake->get_snake_part(i);
            if(snakebody.y == temp_height && snakebody.x == temp_width)  //This checks that the food isn't generated on the snake body. If it is, restart while loop
            continue;
        }
        //This is going to check if the food is on the boarder
        if (temp_height >= board->get_board_height()-2 || temp_width >= board->get_board_width()-2){
        continue;
        }

        //hence if it clears both checks, draw to the screen at x, y and then refresh.
        check-> setYcoord(temp_height);
        check-> setXcoord(temp_width);
        break;
    }
}


void World:: print_food(Fruit *check){
        board->addAt(check->getYcoord(),check->getXcoord(),check->get_food_char());
}


