#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <ncurses.h>
using namespace std;

//This function is going to draw the board onto the screen.

class Board{

private:

    int height;
    int width;
    int xBoarder;
    int yBoarder;
    WINDOW *board_window;

public:

    Board(); //Default constructor. Doesn't get used by the game currently
    Board(int size); //Constructor that gets used by the game. Takes in an integer size that changes the dimensions of the board
    
  
    
     /**
        * refresh
        *
        * Ncurses function that refreshes memory and redraws to the screen
    */
    void refresh();
    
    /**
        * initialise
        *
        * initialises a new board at the start of the game
    */
    void initialise();
    
    /**
        * addAt
        *
        * adds a characher to the board given a y and x position inputed into the function 
    */
    void addAt(int y, int x, chtype ch);
   
      /**
        * getInput
        *
        * Returns the keystroke made by the user 
        * For the game this returns the arrow keystrokes by the player
    */
    chtype getInput(); 
    
    /**
        * getWindows
        *
        * returns the board as a pointer to other classes in the programacher to the board given a y and x position inputed into the function 
    */
    WINDOW *getWindow(); //returns the board as a pointer to other classes in the program
    
    /**
        * get_board_height
        *
        * returns the value of the border height
    */    
    int get_board_height(); 
    
    /**
        * get_board_width
        *
        * returns the value of the border width
    */    
    int get_board_width(); 
    
    /**
        * add_
        *
        * returns the value of the border width
    */ 
    void add_border();


};
#endif


/**
 * Sum numbers in a vector.
 *
 * This sum is the arithmetic sum, not some other kind of sum that only
 * mathematicians have heard of.
 *
 * @param values Container whose values are summed.
 * @return sum of `values`, or 0.0 if `values` is empty.
 */
