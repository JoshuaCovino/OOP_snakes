#ifndef WORLD_H
#define WORLD_H
#include "Snake.h"
#include "Point.h"
#include "Board.h"
#include "Fruit.h"
#include "Direction.h"
#include <iostream>
#include <vector>
#include <ncurses.h>
using namespace std;

    /**
        * World
        *
        * Class, Everything exists within World (of the game)
    */

class World{

    private:
    Snake *snake; //This is going to be out snake object
    Fruit *fruit; //Food object
    Fruit *bomb; //Fruit that ends the game.
    Board *board;
    bool game_over; //Bool that checks if the game is over. The while loop is based on this bool
    bool got_fruit; //Bool that checks if the user has collided with the food.
    char snakechar; //This is going to be the charactor that represents the body of the snake.
    bool valid_fruit; //This is going to check if a fruit has been hit
    bool valid_bomb; //This is going to check if a spectial fruit has been hit
    Direction current_movement;
    int points; //Keeps track of the points of the user

    public:
    
    /**
        * World(int size)
        * 
        * constructor for the World, contains all elements of the game
        * input parameter is the size of the game border
    */    
    World(int size); 
    
    /**
        * game_input()
        *
        * Part of while loop that keeps the game running. Obtains user input
    */    
    void game_input(); // Part of while loop that keeps the game running. Obtains user input
    
    /**
        * state_update()
        *
        * Updates the game based on the users input in collaboration with the game_input() function
    */   
    void state_update(); // Part of while loop that keeps the game running. Updates the game based on game_input
    
    /**
        * redraw()
        *
        * Refreshes the board to update all variables, ensuring that the game is constantly moving
    */   
    void redraw(); // Part of while loop that keeps the game running. Refreshes the board so the user can see the refreshed game
    
    /**
        * isOver()
        *
        * Boolean function which checks whether the user has triggered something that should end the game, either hitting the boarder or another 
        * snake segment
    */   
    bool isOver(); //Boolean that checks if the user has triggered game over by hitting the boarder or hitting a snake segment
    
    /**
        * get_direction_input()
        *
        * Receives the input from the user which determines the direction in which the snake should move
    */   
    Direction get_direction_input(); //Takes in an input from the user
    
    /**
        * delete_tail()
        *
        * Deletes the last element of the snake vector (the tail of the snake), to ensure that the snake does not keep increasing in size each
        * game tick/snake movement
    */   
    void delete_tail(); //Deletes the last elemet of the snake vector in the case of not getting the food
    
    /**
        * move()
        *
        * Updates the first element of the snake vector
    */   
    void move(); //A function that updates the location of the first element of the vector
    
    /**
        * collision()
        *
        * Function which checks whether any collisions have been made between the snake and the border/fruit, if the snake has collided with the 
        * border or itself the game will end, if the snake has collided with a food object, the game will change in accordance to that object
    */   
    void collision(); //Function that checks if the snakes head has hit the boarder, food item or itself
    
    /**
        * generate_new_food_location(Fruit *check)
        *
        * Generates the location for the next fruit to be added, this is based on a random number generator bounded to the size of the board
        * itself
    */   
    void generate_new_food_location(Fruit *check); //Generates a new food location based on a random number within a set range based on the size of the board
    
    /**
        * print_food(Fruit *check)
        *
        * Prints the food onto the screen in the position defined in the generate_new_food_location() function
    */   
    void print_food(Fruit *check); //Prints the food onto the board.
    
};

#endif