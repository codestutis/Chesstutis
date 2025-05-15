#include "GameState.hpp"

GameState::GameState() {
  whiteToMove = true;
  castlingRights = 0xf;
  numMoves = 0;
}

void GameState::initialize(string fen) {
  bitboard.initialize(fen);
}

bool GameState::makeMove(string m) {
  // check valid move 
  // return false if not

  // get piece type

  // get row and column
}

bool undoMove(string m) {

}

string GameState::toString() {
  return bitboard.toString();
}

int GameState::getNumMoves() const {
  return numMoves;
}
// ---------------- GET CASTLING RIGHTS -------------
bool GameState::whiteKingCastle() const {
  return castlingRights & WHITE_KINGSIDE;
}

bool GameState::whiteQueenCastle() const {
  return castlingRights & WHITE_QUEENSIDE;
}

bool GameState::blackKingCastle() const {
  return castlingRights & BLACK_KINGSIDE;
}

bool GameState::blackQueenCastle() const {
  return castlingRights & BLACK_QUEENSIDE;
}