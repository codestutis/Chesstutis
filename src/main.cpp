//#include "UCI.hpp"
#include "GameState.hpp"

int main() {
  GameState game;
  game.initialize();

  while (true) {
    cout << game.toString() << endl;

    string move;
    cout << "Enter your move: ";
    cin >> move;

    game.makeMove(move);
  }

  cout << "Game over!" << endl;
  return 0;

}
