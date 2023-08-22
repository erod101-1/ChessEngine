#pragma once
#include "rook_attacks.hpp"
#include "bishop_attacks.hpp"
#include "magic.hpp"
#include "bitboard.hpp"


struct QueenAttacks // combo of rook and bishop attacks
{
	static U64 get_queen_attacks(int square, U64 occupancy);
};

struct Sliders
{
	static void init_slider_attacks(int bishop);
	static U64 get_bishop_attacks(int square, U64 occupancy);
	static U64 get_rook_attacks(int square, U64 occupancy);
};