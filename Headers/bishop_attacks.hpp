#pragma once
#include "bitboard.hpp"

struct BishopAttacks
{
	static U64 mask_bishop_attacks(int square);
	static U64 generate_bishop_attacks(int square, U64 blocks);
	inline static U64 bishop_masks[64]; //bishop attack mask
	inline static U64 bishop_attacks[64][512]; //bishop attack table [square][occupanies]
};