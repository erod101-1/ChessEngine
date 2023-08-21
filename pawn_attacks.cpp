#include "Headers\pawn_attacks.hpp"


U64 PawnAttacks::mask_pawn_attacks(int square, int side)
{
	U64 Peicebitboard = 0ULL; 
	U64 Attackbitboard = 0ULL;

	// set a piece on the board
	BitboardFuncs::setBit(Peicebitboard, square);
	
	if (!side) // white
	{
		if ((Peicebitboard >> (7)) & NotFiles::not_A_file) // right capture
		{
			Attackbitboard |= (Peicebitboard >> (7));  
		}
		if ((Peicebitboard >> (9)) & NotFiles::not_H_file) // left capture
		{
			Attackbitboard |= (Peicebitboard >> (9));
		}
	}
	else // black
	{
		if ((Peicebitboard << (7)) & NotFiles::not_H_file) // left capture
		{
			Attackbitboard |= (Peicebitboard << (7));
		}
		if ((Peicebitboard << (9)) & NotFiles::not_A_file) // right capture
		{
			Attackbitboard |= (Peicebitboard << (9));
		}
	}
	return Attackbitboard; //pawn attack map

}

void PawnAttacks::init_pawn_attacks()
{
	for (int sq = 0; sq < 64; sq++)
	{
		pawn_attacks[white][sq] = PawnAttacks::mask_pawn_attacks(sq, white);
		pawn_attacks[black][sq] = PawnAttacks::mask_pawn_attacks(sq, black);
	}
}