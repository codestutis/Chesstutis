#include "Board.hpp"
#include <cstdint>
#include <iostream>
#include <bitset>

using namespace std;
/*

Bitboard representation
separate 64 bit integer for each piece type

LSB is a1
MSB is h8

  56 57 58 59 60 61 62 63
  48 49 50 51 52 53 54 55
  40 41 42 43 44 45 46 47 
  32 33 34 35 36 37 38 39
  24 25 26 27 28 29 30 31
  16 17 18 19 20 21 22 23
  08 09 10 11 12 13 14 15
  00 01 02 03 04 05 06 07
*/

Board::Board()
{
    for (int i = 0; i < 12; i++)
    {
        board[i] = 0ULL;
    }
}

void Board::initialize(string fen) {
    int boardIndex = 56; // Start at the top-left corner of the board (a8)

    for (char c : fen) {
        if (isdigit(c)) {
            boardIndex += c - '0'; // Skip empty squares
        } else if (c == '/') {
            boardIndex -= 16; // Move to the next row
        } else {
            // Map FEN characters to the corresponding bitboards
            switch (c) {
                case 'p': board[blackPawn] |= (1ULL << boardIndex); break;
                case 'n': board[blackKnight] |= (1ULL << boardIndex); break;
                case 'b': board[blackBishop] |= (1ULL << boardIndex); break;
                case 'r': board[blackRook] |= (1ULL << boardIndex); break;
                case 'q': board[blackQueen] |= (1ULL << boardIndex); break;
                case 'k': board[blackKing] |= (1ULL << boardIndex); break;
                case 'P': board[whitePawn] |= (1ULL << boardIndex); break;
                case 'N': board[whiteKnight] |= (1ULL << boardIndex); break;
                case 'B': board[whiteBishop] |= (1ULL << boardIndex); break;
                case 'R': board[whiteRook] |= (1ULL << boardIndex); break;
                case 'Q': board[whiteQueen] |= (1ULL << boardIndex); break;
                case 'K': board[whiteKing] |= (1ULL << boardIndex); break;
                default: break;
            }
            boardIndex++; // Move to the next square
        }
    }
}

string Board::toString()
{
    // Initialize an empty board
    char boardArray[64];
    for (int i = 0; i < 64; i++)
    {
        boardArray[i] = '.'; // Empty square
    }

    // Populate the board array using the bitboards
    for (const auto &mapping : bitboards)
    {
        uint64_t bitboard = *mapping.bitboard;
        for (int i = 0; i < 64; i++)
        {
            if (bitboard & (1ULL << i))
            { // Check if the bit is set
                boardArray[i] = mapping.piece;
            }
        }
    }

    // Convert the board array to a string for display
    string ret = "";
    for (int rank = 7; rank >= 0; --rank) {
      for (int file = 0; file < 8; ++file) {
        ret += boardArray[rank * 8 + file];
        ret += " ";
      }
      ret += "\n";
    }
    return ret;
}

/* returns a string of the FEN representation fo the current state of the board*/
string Board::getFEN()
{
    return "";
}

void Board::setSquare(PieceType pt, int row, int col)
{
    board[pt] |= (1ULL << (((row - 1) * 8) + (col - 1)));
}

void Board::clearSquare(int row, int col) {
  for (uint64_t &b: board) {
    b &= ~(1ULL << (((row -1) * 8) + (col - 1)));
  }
}

char Board::getSquare(int row, int col)
{
  for (const auto &mapping: bitboards) {
    if (*mapping.bitboard & (1ULL << (((row - 1) * 8) + (col - 1)))) {
      return mapping.piece;
    }
  }

  return '.';
}
