#pragma once
#include "bitboard.hpp"

struct KnightAttacks
{
	static U64 mask_knight_attacks(int square);
	static void init_knight_attacks();
	inline static U64 knight_attacks[64]; // knight attack table
};
