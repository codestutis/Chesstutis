#include "MoveGen.hpp"


void slidingMoves(vector<Move>& moves) {

}

void diagonalMoves(vector<Move>& moves) {

}

void knightMoves(vector<Move>& moves) {

}

void pawnMoves(vector<Move>& moves) {

}

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


