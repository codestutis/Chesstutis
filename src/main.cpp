#include "Board.hpp"

int main() {
  Board board;

  board.loadFEN("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR");

  cout << board.toString() << endl;
  board.setSquare(Bitboard::whiteKing, 4, 4);

  cout << board.toString() << endl;
}
