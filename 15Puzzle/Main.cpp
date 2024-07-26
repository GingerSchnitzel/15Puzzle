#include "Tile.h"
#include "Board.h"
#include "Direction.h"
#include "Point.h"


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
    board.randomize(BoardConstants::shuffler);
    std::cout << board;

    while (!board.playerWon())
    {
        char command = BoardInteraction::userCommand();
        if (command == 'q')
        {
            return 0;
        }
        board.moveTile(BoardInteraction::charToDirection(command));
        std::cout << board;

    }
    std::cout << "\n\nYou won!\n\n";
    return 0;
}