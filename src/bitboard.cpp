#include "Headers\bitboard.hpp"


void BitboardFuncs::print_bit_board(U64 bitBoard)
{
	for (int rank = 0; rank < 8; rank++)
	{
		for (int file = 0; file < 8; file++)
		{
			// convert the file and rank to square on board 1 - 64
			int square = rank * 8 + file; 
			// print files
			if (!file)
			{
				std::cout << " " << 8 - rank << " ";
			}
			std::cout << " " << BitboardFuncs::getBit(bitBoard,square);
		}
		std::cout << std::endl;
	}
	// print ranks
	std::cout << "    a b c d e f g h" << " " << std::endl;
	std::cout << "Bitboard: " << bitBoard << std::endl;
	
}

U64 BitboardFuncs::setOccupied(int index, int bits_in_mask, U64 attack_mask) // on a given square shows every variation of piece that could be blocking a path
{
	U64 occupied = 0ULL;

	for (int count = 0; count < bits_in_mask; count++) 
	{
		int square = BitboardFuncs::get_ls1b_index(attack_mask);
		BitboardFuncs::popBit(attack_mask, square);

		if (index & (1 << count))
		{
			occupied |= (1ULL << square);
		}
	}
	return occupied;
}
