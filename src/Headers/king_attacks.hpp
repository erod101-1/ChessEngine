#pragma once
#include "bitboard.hpp"

struct KingAttacks
{
	static U64 mask_king_attacks(int square);
	static void init_king_attacks();
	inline static U64 king_attacks[64]; // king attack table
};

