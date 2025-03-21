#include "BoardRepresentation.hpp"

#include <iostream>

using namespace std;

/* array implentation of chess board
Board is represented as a one dimensional array of size 64
index 0 in the array is the top left corner of the board or a8

 BOARD REPRESENTATION

 8. 56 57 58 59 60 61 62 63
 7. 48 49 50 51 52 53 54 55
 6. 40 41 42 43 44 45 46 47
 5. 32 33 34 35 36 37 38 39
 4. 24 25 26 27 28 29 30 31
 3. 16 17 18 19 20 21 22 23
 2. 08 09 10 11 12 13 14 15
 1. 00 01 02 03 04 05 06 07 
    A |B |C |D |E |F |G |H
    1  2  3  4  5  6  7  8
*/
class ArrayBoard : public BoardRepresentation {
  public:
    char board[64];

    /* Initialize the board to the position given by the FEN string
    Defaults to starting position*/
    void initialize(string fen ="rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR") override {
      /* first line starts at index 56 
      range based for loop through the fen string
      set var for index of which square is being set
      if char is a number, add that many .'s to the board
      if char is a /, -15 from index (moves to next line)
      if its a piece add the piece to the board at index
      */

      //TODO handle invalid input

      //TODO handle extended fen strings (includes castling rights, whos move, etc...)

      int index = 56;
      for (char c: fen) {
        if (isdigit(c)) {
          int bruh = c - '0';
          for (int i = 0; i < bruh; i++) { // - '0' converts it to the char to its int value somehow
            board[index++] = '.';
          }
        } else if (c == '/') {
          index -= 16;
        } else {
          board[index++] = c;
        }
      }
    }

    /* Return a string representation of the board for debugging and testing*/
    string displayBoard() override {
      string ret = "";
      for (int i = 56; i >= 0; i -= 8) {
        for (int j = i; j < i + 8; j++) {
          ret += board[j];
          ret += ' ';
        }
        ret += '\n';
      }
      return ret;
    }

    /* returns an array of strings that contain all legal moves
    Moves are in format e2e4 e7e5 etc...*/
    vector<string> getMoves() override {
      vector<string> bruh;
      return bruh;
    }

    /* apply the move given as an argument on the board
    Moves are given in the format e2e5 c7c5 etc...*/
    void makeMove(string move) override {

    }

    /* returns a string of the FEN representation fo the current state of the board*/
    string getFEN() override {
      return "";
    }

    /* returns true of the game is over */
    bool gameOver() override {
      return false;
    }
};

int main() {
  ArrayBoard board;
  board.initialize();
  cout << board.displayBoard();
  board.initialize("rnbqkbnr/pp1ppppp/8/2p5/4P3/5N2/PPPP1PPP/RNBQKB1R");
  cout << board.displayBoard();
}
