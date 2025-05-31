
#ifndef BITBOARD_HPP
#define BITBOARD_HPP
#include <iostream>
#include <bitset>
#include <string>
#include <cstdint>

using namespace std;

enum PieceType
{
  whitePawn,
  whiteKnight,
  whiteBishop,
  whiteRook,
  whiteQueen,
  whiteKing,
  blackPawn,
  blackKnight,
  blackBishop,
  blackRook,
  blackQueen,
  blackKing,
  allWhite,
  allBlack,
  all
};


class Board
{
  public:
  
  uint64_t board[15];
  
  // Array of bitboards and their corresponding piece characters
  // each element is a BitboardMapping struct
  struct BoardMapping
  {
    uint64_t *bitboard;
    char piece;
  };
  
  BoardMapping bitboards[12] = {
    {&board[whitePawn], 'P'}, 
    {&board[whiteKnight], 'N'},
    {&board[whiteBishop], 'B'}, 
    {&board[whiteRook], 'R'}, 
    {&board[whiteQueen], 'Q'}, 
    {&board[whiteKing], 'K'}, 
    {&board[blackPawn], 'p'}, 
    {&board[blackKnight], 'n'}, 
    {&board[blackBishop], 'b'}, 
    {&board[blackRook], 'r'}, 
    {&board[blackQueen], 'q'}, 
    {&board[blackKing], 'k'}
  };

  /*
   * initialize each bitboard to 0
   */
  Board();

  /*
   * initialize every bitboard based on the given fen string
   * default is starting position
   */
  void initialize(string fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR");

  /*
   * returns string representation of the board for testing and what not
   */
  string toString();

  /*
   * return the fen of the current board state
   */
  string getFEN();

  /*
   * sets a given piece type at a certain board location
   * moves should be validated before hand
   */
  void setSquare(PieceType pt, int row, int col);

  void clearSquare(int row, int col);

  /*
   * returns the char of the piece at a certain square
   * square should be validated before hand
   */
  char getSquare(int row, int col);
};

#endif // BITBOARD_HPP
