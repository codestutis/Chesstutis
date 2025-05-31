#include "GameState.hpp"

GameState::GameState() {
  whiteToMove = true;
  castlingRights = 0xf;
  numMoves = 0;
}

void GameState::initialize(string fen) {
  bitboard.initialize(fen);
}

/*
* valid move just checks if the input string is valid not that the actual move is legal
*/
bool validMove(string m) {
  //TODO handle promotions
  return true;
  //if (m.length() != 4) return false;

  //TODO check that each square is a valid square
}

/*
* given a valid move, this checks if its a legal move for current game state
*/
bool legalMove(string m) {
  return true;
}

bool GameState::makeMove(string m) {
  // check valid move 
  // return false if not
  if (!validMove(m)) {

    return false;
  }

  if (!legalMove(m)) {
    return false;
  }

  // separate into starting and ending square
  string start = m.substr(0, 2);
  string end = m.substr(2, 4);

  // get row and column
  // get piece type
  int startRow = start[1] - '1' + 1;
  int startCol = start[0] - 'a' + 1;

  int endRow = end[1] - '1' + 1;
  int endCol = end[0] - 'a' + 1;

  char piece = bitboard.getSquare(startRow, startCol);

  if (piece == '.') return false;

  //TODO set start square to empty and end square to the square 
  bitboard.clearSquare(startRow, startCol);

  // convert piece to the enum
  for (const auto &mapping : bitboards) {
    if (mapping.piece == piece) {
      bitboard.setSquare(mapping.pt, endRow, endCol);
    }
  }

  cout << piece << endl;

  return true;
}

bool undoMove(string m) {
  return true;
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
