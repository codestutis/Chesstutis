
#ifndef BOARD_HPP
#define BOARD_HPP

#include "Bitboard.hpp"
#include <string>

using namespace std;

enum CastlingRights {
    WHITE_KINGSIDE  = 1 << 0, // 0001
    WHITE_QUEENSIDE = 1 << 1, // 0010
    BLACK_KINGSIDE  = 1 << 2, // 0100
    BLACK_QUEENSIDE = 1 << 3  // 1000
};


struct Move {
  int from;
  int to;
  int promotion = 0;
  bool isCapture = false;
  bool isEnPassant = false;
  bool isCastling = false;
};

class Board {
  public:
    /*
     * Constructor
     */
    Board();

    /*
     * load fen using function from Bitboard
     */
    void loadFEN(string fen);

    /*
     * returns fen string using bitboard function 
     */
    string getFEN();

    /*
     * returns true if its whites move 
     */
    bool isWhiteToMove() const;

    /*
     * returns reference to the current bitboard 
     */
    const Bitboard& getBitboard();

    void setSquare(Bitboard::PieceType pt, int row, int col);

    char getSquare(int row, int col);

    string toString();

    int getNumMoves() const;

    // ---------------- GET CASTLING RIGHTS -------------------
    
    bool whiteKingCastle() const;
    bool whiteQueenCastle() const;
    bool blackKingCastle() const;
    bool blackQueenCastle() const;

  private:
    Bitboard bitboard;
    bool whiteToMove;
    char castlingRights;
    int numMoves;

};

#endif
