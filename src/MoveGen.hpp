

#ifndef MOVEGEN_HPP
#define MOVEGEN_HPP

#include "GameState.hpp"
#include <vector>

namespace MoveGen {
  vector<Move> generateLegalMoves(const Board& board);
  vector<Move> generatePseudoLegalMoves(const Board& board);
}

#endif
