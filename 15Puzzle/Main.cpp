#include "Tile.h"
#include "Board.h"
#include "Direction.h"

/*
* CLASS BOARD
* Display the game board
* Randomize starting state
* Slide tiles
* Determine if win condition is reached
* 
* CLASS TILE
* Display an individual tile
* 
* NAMESPACE USERINPUT
* Get commands from user
* Handle invalid input
* 
* FUNCTION MAIN
* Main game logic loop
* Allow user to quit before winning
* 
* HELPER CLASSES
* 1. CLASS POINT
* Indexing the game board tiles (x-axis and y-axis coordinatees)
* 
* 2. CLASS DIRECTION
* Make working with directional commmands easier and more intuitive (enum direction)
*/

int main()
{
    Board board{};
    std::cout << board;
    [[maybe_unused]] char command = BoardInteraction::userCommand();

    return 0;
}