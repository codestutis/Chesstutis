#include "Bitboard.hpp"
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

Bitboard::Bitboard()
{
    for (int i = 0; i < 12; i++)
    {
        board[i] = 0ULL;
    }
}

void Bitboard::initialize(string fen)
{
    int boardIndex = 56;
    for (char c : fen)
    {
        if (isdigit(c))
        {
            int emptySquares = c - '0';
            boardIndex += emptySquares;
        }
        else if (c == '/')
        {
            boardIndex -= 16;
        }
        else
        {
            switch (c)
            {
            case 'p':
                board[blackPawns] |= (1ULL << boardIndex);
                break;
            case 'n':
                board[blackKnights] |= (1ULL << boardIndex);
                break;
            case 'b':
                board[blackBishops] |= (1ULL << boardIndex);
                break;
            case 'r':
                board[blackRooks] |= (1ULL << boardIndex);
                break;
            case 'q':
                board[blackQueens] |= (1ULL << boardIndex);
                break;
            case 'k':
                board[blackKing] |= (1ULL << boardIndex);
                break;
            case 'P':
                board[whitePawns] |= (1ULL << boardIndex);
                break;
            case 'N':
                board[whiteKnights] |= (1ULL << boardIndex);
                break;
            case 'B':
                board[whiteBishops] |= (1ULL << boardIndex);
                break;
            case 'R':
                board[whiteRooks] |= (1ULL << boardIndex);
                break;
            case 'Q':
                board[whiteQueens] |= (1ULL << boardIndex);
                break;
            case 'K':
                board[whiteKing] |= (1ULL << boardIndex);
                break;
            default:
                break;
            }
            boardIndex++;
        }
    }
}

string Bitboard::toString()
{
    // Array of bitboards and their corresponding piece characters
    struct BitboardMapping
    {
        uint64_t *bitboard;
        char piece;
    };

    BitboardMapping bitboards[] = {
        {&board[whitePawns], 'P'}, 
        {&board[whiteKnights], 'N'},
        {&board[whiteBishops], 'B'}, 
        {&board[whiteRooks], 'R'}, 
        {&board[whiteQueens], 'Q'}, 
        {&board[whiteKing], 'K'}, 
        {&board[blackPawns], 'p'}, 
        {&board[blackKnights], 'n'}, 
        {&board[blackBishops], 'b'}, 
        {&board[blackRooks], 'r'}, 
        {&board[blackQueens], 'q'}, 
        {&board[blackKing], 'k'}
    };
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
            if (bitboard & (1ULL << (63 - i)))
            { // Check if the bit is set
                boardArray[i] = mapping.piece;
            }
        }
    }

    // Convert the board array to a string for display
    string ret = "";
    for (int i = 0; i <= 63; i += 8)
    { // Loop through rows from top to bottom
        for (int j = i; j < i + 8; j++)
        {
            ret += boardArray[j];
            ret += ' ';
        }
        ret += '\n';
    }
    return ret;
}

/* returns a string of the FEN representation fo the current state of the board*/
string Bitboard::getFEN()
{
    return "";
}

void Bitboard::setSquare(PieceType pt, int square)
{
    board[pt] |= (1ULL << square);
}

char Bitboard::getSquare(int square)
{
    return 'x';
}
