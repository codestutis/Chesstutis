#include "BoardRepresentation.hpp"


class Bitboard : public BoardRepresentation {
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

    Bitboard() {
      whitePawns = whiteKnights = whiteBishops = whiteRooks = whiteQueens = whiteKing = 0;
      blackPawns = blackKnights = blackBishops = blackRooks = blackQueens = blackKing = 0;
    }

    void initialize(string fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR") override {
      
    }

};