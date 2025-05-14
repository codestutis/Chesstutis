#include "MoveGen.hpp"

vector<Move> MoveGen::generateLegalMoves(const Board& board) {
  Move test = {12, 28};
  vector<Move> moves = {test};
  return moves;
}

vector<Move> MoveGen::generatePseudoLegalMoves(const Board& board) {
  Move test = {13, 29};
  vector<Move> moves = {test};
  return moves;
}
