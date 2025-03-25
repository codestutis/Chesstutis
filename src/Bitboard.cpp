#include "Bitboard.hpp"
#include <iostream>
#include <bitset>

using namespace std;
/*

Bitboard representation 
separate 64 bit integer for each piece type

MSB is a1
LSB is h8
*/

Bitboard::Bitboard() {
  whitePawns = whiteKnights = whiteBishops = whiteRooks = whiteQueens = whiteKing = 0;
  blackPawns = blackKnights = blackBishops = blackRooks = blackQueens = blackKing = 0;
}

void Bitboard::initialize(string fen) {
  int boardIndex = 56;
  for (char c : fen) {
    if (isdigit(c)) {
      int emptySquares = c - '0';
      boardIndex += emptySquares;
    } else if (c == '/') {
      boardIndex -= 16;
    } else {
      switch (c) {
        case 'p': whitePawns |= (1ULL << boardIndex); break;
        case 'n': whiteKnights |= (1ULL << boardIndex); break;
        case 'b': whiteBishops |= (1ULL << boardIndex); break;
        case 'r': whiteRooks |= (1ULL << boardIndex); break;
        case 'q': whiteQueens |= (1ULL << boardIndex); break;
        case 'k': whiteKing |= (1ULL << boardIndex); break;
        case 'P': blackPawns |= (1ULL << boardIndex); break;
        case 'N': blackKnights |= (1ULL << boardIndex); break;
        case 'B': blackBishops |= (1ULL << boardIndex); break;
        case 'R': blackRooks |= (1ULL << boardIndex); break;
        case 'Q': blackQueens |= (1ULL << boardIndex); break;
        case 'K': blackKing |= (1ULL << boardIndex); break;
        default: break;
      }
      boardIndex++;
    }
  }
}

string Bitboard::displayBoard() {
    // Array of bitboards and their corresponding piece characters
  struct BitboardMapping {
    uint64_t* bitboard;
    char piece;
  };

  BitboardMapping bitboards[] = {
    {&whitePawns, 'P'}, {&whiteKnights, 'N'}, {&whiteBishops, 'B'},
    {&whiteRooks, 'R'}, {&whiteQueens, 'Q'}, {&whiteKing, 'K'},
    {&blackPawns, 'p'}, {&blackKnights, 'n'}, {&blackBishops, 'b'},
    {&blackRooks, 'r'}, {&blackQueens, 'q'}, {&blackKing, 'k'}
  };
  // Initialize an empty board
  char board[64];
  for (int i = 0; i < 64; i++) {
      board[i] = '.'; // Empty square
  }

  // Populate the board array using the bitboards
  for (const auto& mapping : bitboards) {
      uint64_t bitboard = *mapping.bitboard;
      for (int i = 0; i < 64; i++) {
          if (bitboard & (1ULL << (63 - i))) { // Check if the bit is set
              board[i] = mapping.piece;
          }
      }
  }

  // Convert the board array to a string for display
  string ret = "";
  for (int i = 56; i >= 0; i -= 8) { // Loop through rows from top to bottom
      for (int j = i; j < i + 8; j++) {
          ret += board[j];
          ret += ' ';
      }
      ret += '\n';
  }
  return ret;
}
    /* returns an array of strings that contain all legal moves
Moves are in format e2e4 e7e5 etc...*/
vector<string> Bitboard::getMoves() {
  vector<string> bruh;
  return bruh;
}

/* apply the move given as an argument on the board
Moves are given in the format e2e5 c7c5 etc...*/
void Bitboard::makeMove(string move) {

}

/* returns a string of the FEN representation fo the current state of the board*/
string Bitboard::getFEN() {
  return "";
}

/* returns true of the game is over */
bool Bitboard::gameOver() {
  return false;
}