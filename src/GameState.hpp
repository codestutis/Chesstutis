#include "Board.hpp"

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

class GameState {
    private:
    Board bitboard;
    bool whiteToMove;
    char castlingRights;
    int numMoves;

    public:
    GameState();
    bool whiteKingCastle() const;
    bool whiteQueenCastle() const;
    bool blackKingCastle() const;
    bool blackQueenCastle() const;

    int getNumMoves() const;

    bool makeMove(string m);
    bool undoMove(string m);

    string toString();
    void initialize(string fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR");



    struct BoardMapping
  {
    PieceType pt;
    char piece;
  };
  
  BoardMapping bitboards[12] = {
    {whitePawn, 'P'}, 
    {whiteKnight, 'N'},
    {whiteBishop, 'B'}, 
    {whiteRook, 'R'}, 
    {whiteQueen, 'Q'}, 
    {whiteKing, 'K'}, 
    {blackPawn, 'p'}, 
    {blackKnight, 'n'}, 
    {blackBishop, 'b'}, 
    {blackRook, 'r'}, 
    {blackQueen, 'q'}, 
    {blackKing, 'k'}
  };
};