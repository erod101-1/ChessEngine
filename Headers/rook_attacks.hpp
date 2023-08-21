#pragma once
#include "bitboard.hpp"

struct RookAttacks
{
	static U64 mask_rook_attacks(int square);
	static U64 generate_rook_attacks(int square,U64 blocks);
	inline static U64 rook_masks[64];
	inline static U64 rook_attacks[64][512]; // rook attack table [square][occupanies] 512 possible ways a piece can block a rook
};