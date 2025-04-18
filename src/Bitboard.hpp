
#ifndef BITBOARD_HPP
#define BITBOARD_HPP
#include <iostream>
#include <bitset>
#include <string>
#include <cstdint>

using namespace std;

class Bitboard
{
private:
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

public:
  Bitboard();
  void initialize(string fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR");
  string toString();
  string getFEN();
  void setSquare(uint64_t &board, int square);
  char getSquare(int square);
};

#endif // BITBOARD_HPP