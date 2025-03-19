#include <iostream>

using namespace std;

class BoardRepresentation {
public:

    /* Initialize the board to the position given by the FEN string
    Defaults to starting position*/
    virtual void initialize(string fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR") = 0;

    /* Return a string representation of the board for debugging and testing*/
    virtual string displayBoard() = 0;

    /* returns an array of strings that contain all legal moves
    Moves are in format e2e4 e7e5 etc...*/
    virtual vector<string> getMoves() = 0;

    /* apply the move given as an argument on the baord
    Moves are given in the format e2e5 c7c5 etc...*/
    virtual void makeMove(string move) = 0;

    /* returns a string of the FEN representation fo the current state of the board*/
    virtual string getFEN() = 0;

    /* returns true of the game is over*/
    virtual bool gameOver() = 0;


}