#include "Bitboard.hpp"

int main() {
  Bitboard board;

  board.initialize();

  cout << board.displayBoard() << endl;
}