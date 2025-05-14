
#include "GameState.hpp"




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