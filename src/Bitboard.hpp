
#ifndef BITBOARD_HPP
#define BITBOARD_HPP
#include <iostream>
#include <bitset>
#include <string>
#include <cstdint>

using namespace std;

class Bitboard
{
public:
  enum PieceType
  {
    whitePawns,
    whiteKnights,
    whiteBishops,
    whiteRooks,
    whiteQueens,
    whiteKing,
    blackPawns,
    blackKnights,
    blackBishops,
    blackRooks,
    blackQueens,
    blackKing,
  };

  uint64_t board[12];

    // Array of bitboards and their corresponding piece characters
    // each element is a BitboardMapping struct
    struct BitboardMapping
    {
        uint64_t *bitboard;
        char piece;
    };

    BitboardMapping bitboards[12] = {
        {&board[whitePawns], 'P'}, 
        {&board[whiteKnights], 'N'},
        {&board[whiteBishops], 'B'}, 
        {&board[whiteRooks], 'R'}, 
        {&board[whiteQueens], 'Q'}, 
        {&board[whiteKing], 'K'}, 
        {&board[blackPawns], 'p'}, 
        {&board[blackKnights], 'n'}, 
        {&board[blackBishops], 'b'}, 
        {&board[blackRooks], 'r'}, 
        {&board[blackQueens], 'q'}, 
        {&board[blackKing], 'k'}
    };

  /*
   * initialize each bitboard to 0
   */
  Bitboard();

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
  void setSquare(PieceType pt, int square);

  /*
   * returns the char of the piece at a certain square
   * square should be validated before hand
   */
  char getSquare(int square);
};

#endif // BITBOARD_HPP
