#ifndef TYPES_H
#define TYPES_H

#include <cstdint>

#define NUM_SQUARES 64
#define NUM_TYPE_OF_PIECES 12 // two of each color

#define WHITE_PAWN 0
#define WHITE_BISHOP 1
#define WHITE_KNIGHT 2
#define WHITE_ROOK 3
#define WHITE_QUEEN 4
#define WHITE_KING 5
#define BLACK_PAWN 6
#define BLACK_BISHOP 7
#define BLACK_KNIGHT 8
#define BLACK_ROOK 9
#define BLACK_QUEEN 10
#define BLACK_KING 11
#define NONE 12

typedef uint8_t Square;
typedef uint8_t Piece;
typedef uint64_t PieceBoard;

#endif