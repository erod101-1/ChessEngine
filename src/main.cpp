// BitBoardChessEngine.cpp : Defines the entry point for the application.
//

#include "Headers\bitboard.hpp"
#include "Headers\pawn_attacks.hpp"
#include "Headers\knight_attacks.hpp"
#include "Headers\king_attacks.hpp"
#include "Headers\bishop_attacks.hpp"
#include "Headers\rook_attacks.hpp"
#include "Headers\magic.hpp"
#include "Headers\sliders.hpp"
#include "Headers\game.hpp"
#include <bitset> 

using namespace std;


int main()
{ 
	Game::init_all_attacks();


	FenReader::parse_fen("8/8/8/3p/8/8/8/8 w - - ");

	Game::print_game_board();
	
	Game::print_attacked_square();
	return 0;
}
