#include "../src/bitboard.h"
#include <iostream>
#include <catch2/catch_test_macros.hpp>
#include <random>
#include <bitset>
#include <algorithm>
#include <iterator>

std::random_device rd;
std::mt19937_64 eng(rd());

static uint64_t generateRandomInteger(const uint64_t start, const uint64_t end) {
  std::uniform_int_distribution<uint64_t> udist(start, end);
  return udist(eng);
}

TEST_CASE("Set/get on bitboard", "[bitboard]") {
  BitBoard bb;
  Square sq = generateRandomInteger(0, 63);
  Piece piece = generateRandomInteger(WHITE_PAWN, BLACK_KING);
  bb.set(sq, piece);
  REQUIRE(bb.at(sq) == piece);
  REQUIRE((bb.getAll(NONE) & (1UL << sq)) == 0);
}

TEST_CASE("Set all/get all on bitboard", "[bitboard]") {
  BitBoard bb;
  PieceBoard all_bb = 0;
  for (Piece piece = WHITE_PAWN; piece <= BLACK_KING; piece++) {
    PieceBoard piece_bb =
        generateRandomInteger(1, std::llround(std::pow(2, 63)));
    bb.setAll(piece, piece_bb);
    REQUIRE(bb.getAll(piece) == piece_bb);
    all_bb |= piece_bb;
  }
  REQUIRE(bb.getAll(NONE) == ~all_bb);
}