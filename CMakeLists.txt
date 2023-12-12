cmake_minimum_required(VERSION 3.5)
project(netchess VERSION 0.1.0 LANGUAGES C CXX)

add_executable(netchess main.cpp src/board.cpp src/engine.cpp src/eval.cpp src/fen.cpp src/move_gen.cpp src/move.cpp src/uci.cpp)
target_include_directories(netchess PUBLIC src)