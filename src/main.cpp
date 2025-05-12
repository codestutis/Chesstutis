#include "Bitboard.hpp"

int main() {
  Bitboard board;

  board.initialize();

  cout << board.toString() << endl;
  board.setSquare(Bitboard::whiteKing, 44);
  cout << "Set Piece" << endl;
  cout << board.toString() << endl;

  cout << "get square: " << board.getSquare(44) << endl;
  cout << "get square: " << board.getSquare(36) << endl;
  cout << "get square: " << board.getSquare(62) << endl;
  cout << "get square: " << board.getSquare(55) << endl;
}
