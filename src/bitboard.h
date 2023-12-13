#ifndef BITBOARD_H
#define BITBOARD_H

#include "types.h"

class BitBoard {
private:
  // counting all unoccupied squares
  PieceBoard _piece_boards[NUM_TYPE_OF_PIECES + 1];

public:
  BitBoard();
  Piece at(const Square pos) const;
  void set(const Square pos, const Piece piece);
  PieceBoard getAll(const Piece piece) const;
  void setAll(const Piece piece, const PieceBoard board);
};

#endif