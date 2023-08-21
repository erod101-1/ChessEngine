
#include "Headers\bishop_attacks.hpp"

U64 BishopAttacks::mask_bishop_attacks(int square)
{
	U64 attackBitboard = 0ULL;

	int rank, file;
	int target_rank = square/8, target_file  = square % 8;

	//bishop attack directions exluding edge file and ranks

	for (rank = target_rank + 1, file = target_file + 1; rank <= 6 && file <= 6; rank++, file++)
	{
		attackBitboard |= (1ULL << (rank * 8 + file));
	}
	for (rank = target_rank - 1, file = target_file + 1; rank >= 1 && file <= 6; rank--, file++)
	{
		attackBitboard |= (1ULL << (rank * 8 + file));
	}
	for (rank = target_rank + 1, file = target_file - 1; rank <= 6 && file >= 1; rank++, file--)
	{
		attackBitboard |= (1ULL << (rank * 8 + file));
	}
	for (rank = target_rank - 1, file = target_file - 1; rank >= 1 && file >= 1; rank--, file--)
	{
		attackBitboard |= (1ULL << (rank * 8 + file));
	}
	return attackBitboard;
}


U64 BishopAttacks::generate_bishop_attacks(int square,U64 blocks)
{
	U64 attackBitboard = 0ULL;

	int rank, file;
	int target_rank = square / 8, target_file = square % 8;

	//bishop attacks with edges and piece not on square

	for (rank = target_rank + 1, file = target_file + 1; rank <= 7 && file <= 7; rank++, file++)
	{
		attackBitboard |= (1ULL << (rank * 8 + file));
		if ((1ULL << (rank * 8 + file) & blocks))
		{
			break;
		}
	}
	for (rank = target_rank - 1, file = target_file + 1; rank >= 0 && file <= 7; rank--, file++)
	{
		attackBitboard |= (1ULL << (rank * 8 + file));
		if ((1ULL << (rank * 8 + file) & blocks))
		{
			break;
		}
	}
	for (rank = target_rank + 1, file = target_file - 1; rank <= 7 && file >= 0; rank++, file--)
	{
		attackBitboard |= (1ULL << (rank * 8 + file));
		if ((1ULL << (rank * 8 + file) & blocks))
		{
			break;
		}
	}
	for (rank = target_rank - 1, file = target_file - 1; rank >= 0 && file >= 0; rank--, file--)
	{
		attackBitboard |= (1ULL << (rank * 8 + file));
		if ((1ULL << (rank * 8 + file) & blocks))
		{
			break;
		}
	}
	return attackBitboard;
}

