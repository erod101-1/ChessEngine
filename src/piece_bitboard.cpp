#include "Headers\piece_bitboard.hpp"

void PieceBitboards::set_castle(int piece) {
	castle |= piece;
}
void PieceBitboards::set_enpassant(int sq)
{
	en_passant = sq;
}
void PieceBitboards::set_side(int side_set)
{
	if (!side_set)
	{
		side_to_move = 0;
	}
	else if (side_set)
	{
		side_to_move = 1;
	}
	else {
		side_to_move = -1;
	}
}
void PieceBitboards::print_game_board()
{
	std::cout << std::endl;
	for (int r = 0; r < 8; r++)
	{
		for (int f = 0; f < 8; f++)
		{
			int square = r * 8 + f;
			int piece = -1;

			//print ranks
			if (!f)
			{
				std::cout << " " << 8 - r << " ";
			}

			//loop over the pieces 
			for (int i = P; i <= k; i++)
			{
				if (BitboardFuncs::getBit(PieceBitboards::bitboards[i], square))
				{
					piece = i;
				}
			}
			std::cout << static_cast<char>((piece == -1) ? '.' : PieceEncoding::ascii_pieces[piece]) << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "   a b c d e f g h" << std::endl;
	std::cout << "Side to Move: " << static_cast<std::string>((!side_to_move && side_to_move != -1) ? "white" : "black") << std::endl;
	std::cout << "Enpassant: " << static_cast<std::string>(en_passant != NOSQUARE ? square_to_coord[en_passant] : "false") << std::endl;
	std::cout << "Castling: " << static_cast<char>((castle & WK) ? 'K' : '-') << static_cast<char>((castle & WQ)? 'Q' : '-') << static_cast<char>((castle & BK) ? 'k' : '-')
		<< static_cast<char>((castle & BQ) ? 'q' : '-');
																		
}