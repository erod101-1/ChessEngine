#include "Headers\game.hpp"

void Game::set_castle(int piece) {
	castle |= piece;
}
void Game::set_enpassant(int sq)
{
	en_passant = sq;
}
void Game::set_side(int side_set)
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
void Game::print_game_board()
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
				if (BitboardFuncs::getBit(Game::bitboards[i], square))
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

void Game::init_all_attacks()
{
	for (int sq = 0; sq < 64; sq++)
	{
		PawnAttacks::pawn_attacks[white][sq] = PawnAttacks::mask_pawn_attacks(sq, white);
		PawnAttacks::pawn_attacks[black][sq] = PawnAttacks::mask_pawn_attacks(sq, black);

		KnightAttacks::knight_attacks[sq] = KnightAttacks::mask_knight_attacks(sq);
		KingAttacks::king_attacks[sq] = KingAttacks::mask_king_attacks(sq);
	}
	Sliders::init_slider_attacks(bishop);
	Sliders::init_slider_attacks(rook);
}

void FenReader::parse_fen(char* fen)
{
	//reset bitboards
	std::memset(Game::bitboards, 0ULL, sizeof(Game::bitboards));
	std::memset(Game::occupancies, 0ULL, sizeof(Game::occupancies));
	//reset game positions
	Game::set_side(white);
	Game::set_enpassant(NOSQUARE);
	Game::set_castle(0);

	for (int rank = 0; rank < 8; rank++)
	{
		for (int file = 0; file < 8; file++)
		{
			int square = rank * 8 + file;
			//match peices in fen string
			if ((*fen >= 'a' && *fen <= 'z') || (*fen >= 'A' && *fen <= 'Z'))
			{
				//init piece type
				int piece = PieceEncoding::char_pieces.at(*fen);


				BitboardFuncs::setBit(Game::bitboards[piece], square);

				*fen++;
			}
			// match numbers in fen string
			if (*fen >= '0' && *fen <= '9')
			{
				int offset = *fen - '0'; // convert char 0 to int 0
				int piece = -1;
				//loop over bitboards (i)
				for (int i = P; i <= k; i++)
				{
					if (BitboardFuncs::getBit(Game::bitboards[i], square))
					{
						piece = i;
					}
				}
				//if no piece on curent square;
				if (piece == -1)
				{
					file--;
				}
				file += offset;

				*fen++;
			}
			//handle seperator
			if (*fen == '/')
			{
				*fen++;
			}

		}
	}
	*fen++; // skip empty space goto side to move
	
	(*fen == 'w') ? Game::set_side(white) : Game::set_side(black); //getting side from fen s
	
	*fen++; *fen++; // goto casteling rights
	
	while (*fen != ' ')
	{
		switch (*fen)
		{
		case 'K': Game::set_castle(WK); break;
		case 'Q': Game::set_castle(WQ); break;
		case 'k': Game::set_castle(BK); break;
		case 'q': Game::set_castle(BQ); break;
		case '.': break;
		}
		*fen++;
	}
	*fen++; // parse en passant square

	if (*fen != '-')
	{
		//parse file and rank
		int file = fen[0] - 'a';
		int rank = 8 - (fen[1] - '0');

		Game::set_enpassant(rank * 8 + file);
	}
	else // no en passent
	{
		Game::set_enpassant(NOSQUARE);
	}
	//white bitboards
	for (int piece = P; piece <= K; piece++)
	{
		Game::occupancies[white] |= Game::bitboards[piece];
	}
	
	for (int piece = p; piece <= k; piece++)
	{
		Game::occupancies[black] |= Game::bitboards[piece];
	}
	Game::occupancies[both] |= (Game::occupancies[white] | Game::occupancies[black]);

}

void Game::print_attacked_square()
{	
std::cout << std::endl;
	for (int rank = 0; rank < 8; rank++)
	{
		for (int file = 0; file < 8; file++)
		{
			int square = rank * 8 + file;
			if (!file)
			{
				std::cout << " " << 8 - rank << " ";
			}
		}
		std::cout << std::endl;
	}

	std::cout << "   a b c d e f g h" << std::endl;
}

int Game::is_square_attacked(int square, int side)
{
	
	return 0;
}