
#ifndef SEARCH_HPP 
#define SEARCH_HPP

#include "Board.hpp"

namespace Search {
  Move findBestMove(const Board& board, int depth, int timeout);
}

#endif // !SEARCH_HPP 
