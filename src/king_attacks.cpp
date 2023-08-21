#include "Headers\king_attacks.hpp"

U64 KingAttacks::mask_king_attacks(int square)
{
	U64 attackBitboard = 0ULL;
	U64 pieceBitboard = 0ULL;
	BitboardFuncs::setBit(pieceBitboard, square);

	if ((pieceBitboard >> 8)) attackBitboard |= (pieceBitboard >> 8);

	if ((pieceBitboard >> 9) & NotFiles::not_H_file) attackBitboard |= (pieceBitboard >> 9);

	if ((pieceBitboard >> 7) & NotFiles::not_A_file) attackBitboard |= (pieceBitboard >> 7);

	if ((pieceBitboard >> 1) & NotFiles::not_H_file) attackBitboard |= (pieceBitboard >> 1);

	if ((pieceBitboard << 8)) attackBitboard |= (pieceBitboard << 8);

	if ((pieceBitboard << 9) & NotFiles::not_A_file) attackBitboard |= (pieceBitboard << 9);

	if ((pieceBitboard << 7) & NotFiles::not_H_file) attackBitboard |= (pieceBitboard << 7);

	if ((pieceBitboard << 1) & NotFiles::not_A_file) attackBitboard |= (pieceBitboard << 1);

	//king attack map
	return attackBitboard;
}

void KingAttacks::init_king_attacks()
{
	for (int square = 0; square < 64; square++)
	{
		king_attacks[square] = KingAttacks::mask_king_attacks(square);
	}
}
