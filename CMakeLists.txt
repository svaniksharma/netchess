cmake_minimum_required(VERSION 3.5)
project(netchess VERSION 0.1.0 LANGUAGES C CXX)

find_package(Catch2 3 REQUIRED)
add_executable(netchess-tests test/bitboard_test.cpp
        test/bitboard_test.cpp src/board.cpp src/engine.cpp src/eval.cpp src/fen.cpp src/move_gen.cpp src/move.cpp src/uci.cpp
        src/types.h
        src/bitboard.cpp)
target_include_directories(netchess-tests PUBLIC src)
target_link_libraries(netchess-tests PRIVATE Catch2::Catch2WithMain)

add_executable(netchess main.cpp src/board.cpp src/engine.cpp src/eval.cpp src/fen.cpp src/move_gen.cpp src/move.cpp src/uci.cpp
        src/types.h
        src/bitboard.cpp)
target_include_directories(netchess PUBLIC src)