#include "..\Headers\knight_attacks.hpp"

U64 KnightAttacks::mask_knight_attacks(int square)
{
	U64 attackBitboard = 0ULL;
	U64 pieceBitboard = 0ULL;
	BitboardFuncs::setBit(pieceBitboard, square);

	if ((pieceBitboard >> 17) & NotFiles::not_H_file) attackBitboard |= (pieceBitboard >> 17);
	
	if ((pieceBitboard >> 15) & NotFiles::not_A_file) attackBitboard |= (pieceBitboard >> 15);
	
	if ((pieceBitboard >> 10) & NotFiles::not_HG_file) attackBitboard |= (pieceBitboard >> 10);
	
	if ((pieceBitboard >> 6) & NotFiles::not_AB_file) attackBitboard |= (pieceBitboard >> 6);
	

	if ((pieceBitboard << 17) & NotFiles::not_A_file) attackBitboard |= (pieceBitboard << 17);

	if ((pieceBitboard << 15) & NotFiles::not_H_file) attackBitboard |= (pieceBitboard << 15);

	if ((pieceBitboard << 10) & NotFiles::not_AB_file) attackBitboard |= (pieceBitboard << 10);

	if ((pieceBitboard << 6) & NotFiles::not_HG_file) attackBitboard |= (pieceBitboard << 6);

	//knight attack map
	return attackBitboard;
}

void KnightAttacks::init_knight_attacks()
{
	for (int square = 0; square < 64; square++)
	{
		knight_attacks[square] = KnightAttacks::mask_knight_attacks(square);
	}
}