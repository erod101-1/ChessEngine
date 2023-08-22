
#include "..\Headers\rook_attacks.hpp"

U64 RookAttacks::mask_rook_attacks(int square)
{
	U64 attackBitboard = 0ULL;

	int rank, file;
	int target_rank = square / 8, target_file = square % 8;

	//rook attack directions exluding edge file and ranks
	for (rank = target_rank + 1; rank <= 6; rank++)
	{
		attackBitboard |= (1ULL << rank * 8 + target_file);
	}
	for (rank = target_rank - 1; rank >= 1; rank--)
	{
		attackBitboard |= (1ULL << rank * 8 + target_file);
	}

	for (file = target_file + 1; file <= 6; file++)
	{
		attackBitboard |= (1ULL <<  target_rank* 8 + file);
	}

	for (file = target_file - 1; file >= 1; file--)
	{
		attackBitboard |= (1ULL << target_rank * 8 + file);
	}
	return attackBitboard;
}


U64 RookAttacks::generate_rook_attacks(int square,U64 blocks)
{
	U64 attackBitboard = 0ULL;
	int rank, file;
	int target_rank = square / 8, target_file = square % 8;

	//rook attacks with file edges and blocker
	for (rank = target_rank + 1; rank <= 7; rank++)
	{
		attackBitboard |= (1ULL << rank * 8 + target_file);

		if ((1ULL << rank * 8 + target_file) & blocks)
		{
			break;
		}

	}
	for (rank = target_rank - 1; rank >= 0; rank--)
	{
		attackBitboard |= (1ULL << rank * 8 + target_file);
		
		if ((1ULL << rank * 8 + target_file) & blocks)
		{
			break;
		}
	}

	for (file = target_file + 1; file <= 7; file++)
	{
		attackBitboard |= (1ULL << target_rank * 8 + file);
		
		if ((1ULL << target_rank * 8 + file) & blocks)
		{
			break;
		}
	}

	for (file = target_file - 1; file >= 0; file--)
	{
		attackBitboard |= (1ULL << target_rank * 8 + file);

		if ((1ULL << target_rank * 8 + file) & blocks)
		{
			break;
		}
	}
	return attackBitboard;
}