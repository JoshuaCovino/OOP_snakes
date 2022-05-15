#include <iostream>
#include <curses.h>
#include <ncurses.h>
#include "Board.h"
using namespace std;

Board::Board(){

}

Board::Board(int size){

    height = size;       //We need the width to be larger as ncurses's sizing is based on a curser. (ie, it's longer than wide)
    width = size*2.5;

    board_window = newwin (height,width,0,0);
    add_border();
    initialise();

}

void Board::initialise(){
    clear();
    refresh();

}void Board::add_border(){
    box(board_window, 0, 0);
}


void Board::refresh(){
    //This refreshes the memory so that it will print on screen after we have made a bunch of changes.
    wrefresh(board_window);
}

    //This method will add a char onto the window with the supplied coords
void Board::addAt(int y, int x, chtype ch){
    mvwaddch(board_window,y,x,ch);
}

    //This contains a refresh so everytime that we get an input it will refresh. It's going to be used in the
    //main game loop.
chtype Board:: getInput(){
    return wgetch(board_window);
}

WINDOW * Board :: getWindow(){
    return board_window;
}

int Board :: get_board_height(){
    return height;
}

int Board:: get_board_width(){
    return width;
}
