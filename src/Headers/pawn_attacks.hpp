#pragma once
#include "bitboard.hpp"

struct PawnAttacks
{
	static U64 mask_pawn_attacks(int square, int side);
	static void init_pawn_attacks();
	inline static U64 pawn_attacks[2][64]; //pawn attack table
};