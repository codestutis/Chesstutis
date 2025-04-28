#include "Bitboard.hpp"

int main() {
  Bitboard board;

  board.initialize();

  cout << board.toString() << endl;
  board.setSquare(Bitboard::whiteKing, 44);
  cout << "Set Piece" << endl;
  cout << board.toString() << endl;
}
