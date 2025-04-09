
#ifndef BITBOARD_HPP
#define BITBOARD_HPP
#include <iostream>
#include <bitset>
#include <vector>
#include <string>

using namespace std;

class Bitboard {
  public:
    uint64_t whitePawns;
    uint64_t whiteKnights;
    uint64_t whiteBishops;
    uint64_t whiteRooks;
    uint64_t whiteQueens;
    uint64_t whiteKing;

    uint64_t blackPawns;
    uint64_t blackKnights;
    uint64_t blackBishops;
    uint64_t blackRooks;
    uint64_t blackQueens;
    uint64_t blackKing;

    Bitboard();
    void initialize(string fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR");
    string toString();
    vector<string> getMoves();
    void makeMove(string move);
    string getFEN();
    bool gameOver();
};

#endif // BITBOARD_HPP