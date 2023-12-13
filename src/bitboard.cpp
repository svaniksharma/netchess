#include "bitboard.h"
#include <bitset>
#include <cassert>

BitBoard::BitBoard() {
  for (Piece piece = WHITE_PAWN; piece <= BLACK_KING; piece++)
    _piece_boards[piece] = 0;
  _piece_boards[NONE] = 0xFFFFFFFFFFFFFFFFUL;
}

Piece BitBoard::at(const Square pos) const {
  assert(pos >= 0 && pos < NUM_SQUARES);
  const uint64_t mask = 1UL << pos;
  for (Piece piece = WHITE_PAWN; piece <= BLACK_KING; piece++) {
    if (_piece_boards[piece] & mask) {
      return piece;
    }
  }
  return NONE;
}

void BitBoard::set(const Square pos, const Piece piece) {
  assert(pos >= 0 && pos < NUM_SQUARES);
  assert(piece >= WHITE_PAWN && piece <= BLACK_KING);
  _piece_boards[piece] |= (1UL << pos);
  _piece_boards[NONE] &= ~(1UL << pos);
}

PieceBoard BitBoard::getAll(const Piece piece) const {
  assert(piece >= WHITE_PAWN && piece <= NONE);
  return _piece_boards[piece];
}

void BitBoard::setAll(const Piece piece, const PieceBoard board) {
  assert(piece >= 0 && piece < NUM_SQUARES);
  _piece_boards[piece] = board;
  _piece_boards[NONE] &= ~board;
}