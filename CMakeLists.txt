# CMakeList.txt : CMake project for BitBoardChessEngine, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)
set(CMAKE_CXX_STANDARD 17)


include_directories(${CMAKE_SOURCE_DIR}/BitBoardChessEngine/Headers)

file(GLOB SOURCES "src/*.cpp")
#add_executable(BitBoardChessEngine ${SOURCES})


# Add source to this project's executable.
add_executable (BitBoardChessEngine "main.cpp"  "Headers/bitboard.hpp" "bitboard.cpp" "Headers/pawn_attacks.hpp" "pawn_attacks.cpp" "Headers/knight_attacks.hpp" "knight_attacks.cpp" "Headers/king_attacks.hpp" "king_attacks.cpp" "Headers/bishop_attacks.hpp" "bishop_attacks.cpp" "Headers/rook_attacks.hpp" "rook_attacks.cpp" "Headers/magic.hpp" "magic.cpp" "Headers/sliders.hpp" "sliders.cpp" "Headers/piece_bitboard.hpp" "piece_bitboard.cpp")

# TODO: Add tests and install targets if needed.
