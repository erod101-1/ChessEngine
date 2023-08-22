#include "..\Headers\sliders.hpp"

U64 QueenAttacks::get_queen_attacks(int square, U64 occupancy)
{
	U64 result = 0ULL;

	U64 rook_occupancy = occupancy;
	U64 bishop_occupancy = occupancy;


	//bishop attacks
	bishop_occupancy &= BishopAttacks::bishop_masks[square];
	bishop_occupancy *= PieceMagicNumbers::bishop_magic_numbers[square];
	bishop_occupancy >>= 64 - NumMovesLookUp::bishop_relevant_bits[square];

	result = BishopAttacks::bishop_attacks[square][bishop_occupancy];

	//rook attacks
	rook_occupancy &= RookAttacks::rook_masks[square];
	rook_occupancy *= PieceMagicNumbers::rook_magic_numbers[square];
	rook_occupancy >>= 64 - NumMovesLookUp::rook_relevant_bits[square];

	result |= RookAttacks::rook_attacks[square][rook_occupancy];
	
	return result; //queen attack table
}
void Sliders::init_slider_attacks(int bishop)
{
	for (int square = 0; square < 64; square++)
	{
		// init attack masks for rook and bishop
		BishopAttacks::bishop_masks[square] = BishopAttacks::mask_bishop_attacks(square);
		RookAttacks::rook_masks[square] = RookAttacks::mask_rook_attacks(square);

		// sets ourr current mask
		U64 attack_mask = bishop ? BishopAttacks::bishop_masks[square] : RookAttacks::rook_masks[square];

		// init bit count

		int relevant_bits_count = BitboardFuncs::count_bits(attack_mask);

		// init occupancy indicies
		int occupancy_indicies = (1 << relevant_bits_count); 

		for (int index = 0; index < occupancy_indicies; index++)
		{
			if (bishop)
			{
				U64 occupancy = BitboardFuncs::setOccupied(index, relevant_bits_count, attack_mask);
				int magic_index = (occupancy * PieceMagicNumbers::bishop_magic_numbers[square]) >> (64 - NumMovesLookUp::bishop_relevant_bits[square]);
				BishopAttacks::bishop_attacks[square][magic_index] = BishopAttacks::generate_bishop_attacks(square, occupancy);
			}
			else
			{
				U64 occupancy = BitboardFuncs::setOccupied(index, relevant_bits_count, attack_mask);
				int magic_index = (occupancy * PieceMagicNumbers::rook_magic_numbers[square]) >> (64 - NumMovesLookUp::rook_relevant_bits[square]);
				RookAttacks::rook_attacks[square][magic_index] = RookAttacks::generate_rook_attacks(square, occupancy);
			}

		}
	}
}

U64 Sliders::get_bishop_attacks(int square, U64 occupancy)
{
	// get the bishop attacks from current board
	occupancy &= BishopAttacks::bishop_masks[square];
	occupancy *= PieceMagicNumbers::bishop_magic_numbers[square];
	occupancy >>= 64 - NumMovesLookUp::bishop_relevant_bits[square];

	return BishopAttacks::bishop_attacks[square][occupancy];
}


U64 Sliders::get_rook_attacks(int square, U64 occupancy)
{
	// get the bishop attacks from current board
	occupancy &= RookAttacks::rook_masks[square];
	occupancy *= PieceMagicNumbers::rook_magic_numbers[square];
	occupancy >>= 64 - NumMovesLookUp::rook_relevant_bits[square];

	return RookAttacks::rook_attacks[square][occupancy];
}