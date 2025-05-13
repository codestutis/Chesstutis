
#include "Bitboard.hpp"
#include "Board.hpp"


Board::Board() {
  whiteToMove = true;
  castlingRights = 0xf;
  numMoves = 0;
}

void Board::loadFEN(string fen="rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR") {
  bitboard.initialize(fen);
}

string Board::toString() {
  return bitboard.toString();
}

string Board::getFEN() {
  return bitboard.getFEN();
}

bool Board::isWhiteToMove() const {
  return numMoves % 2 == 0;
}

const Bitboard& Board::getBitboard() {
  return bitboard;
}

void Board::setSquare(Bitboard::PieceType pt, int row, int col) {
  bitboard.setSquare(pt, ((row - 1) * 8) + (col - 1));
}

char Board::getSquare(int row, int col) {
  return bitboard.getSquare(((row - 1) * 8) + (col - 1));
}

int Board::getNumMoves() const {
  return numMoves;
}

// ---------------- GET CASTLING RIGHTS -------------
bool Board::whiteKingCastle() const {
  return castlingRights & WHITE_KINGSIDE;
}

bool Board::whiteQueenCastle() const {
  return castlingRights & WHITE_QUEENSIDE;
}

bool Board::blackKingCastle() const {
  return castlingRights & BLACK_KINGSIDE;
}

bool Board::blackQueenCastle() const {
  return castlingRights & BLACK_QUEENSIDE;
}
