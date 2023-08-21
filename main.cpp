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
#include "Headers\piece_bitboard.hpp"
#include <bitset> 
using namespace std;

void initAll()
{
	/*
	* 	//init slider piece
	Sliders::init_slider_attacks(bishop);
	Sliders::init_slider_attacks(rook);

	U64 occupancy_bitboard = 0ULL;
	BitboardFuncs::setBit(occupancy_bitboard, d3);
	BitboardFuncs::printBoard(occupancy_bitboard);

	//BitboardFuncs::printBoard(Sliders::get_bishop_attacks(d4, occupancy_bitboard));
	BitboardFuncs::printBoard(Sliders::get_rook_attacks(d4, occupancy_bitboard));
	*/
	// init leapers too
	Magic::init_magic_numbers();
}



int main()
{ 
	// White pawns
	BitboardFuncs::setBit(PieceBitboards::bitboards[P], a2);
	BitboardFuncs::setBit(PieceBitboards::bitboards[P], b2);
	BitboardFuncs::setBit(PieceBitboards::bitboards[P], c2);
	BitboardFuncs::setBit(PieceBitboards::bitboards[P], e2);
	BitboardFuncs::setBit(PieceBitboards::bitboards[P], d2);
	BitboardFuncs::setBit(PieceBitboards::bitboards[P], f2);
	BitboardFuncs::setBit(PieceBitboards::bitboards[P], g2);
	BitboardFuncs::setBit(PieceBitboards::bitboards[P], h2);

	// Black pawns
	BitboardFuncs::setBit(PieceBitboards::bitboards[p], a7);
	BitboardFuncs::setBit(PieceBitboards::bitboards[p], b7);
	BitboardFuncs::setBit(PieceBitboards::bitboards[p], c7);
	BitboardFuncs::setBit(PieceBitboards::bitboards[p], e7);
	BitboardFuncs::setBit(PieceBitboards::bitboards[p], d7);
	BitboardFuncs::setBit(PieceBitboards::bitboards[p], f7);
	BitboardFuncs::setBit(PieceBitboards::bitboards[p], g7);
	BitboardFuncs::setBit(PieceBitboards::bitboards[p], h7);

	// Black Pieces
	BitboardFuncs::setBit(PieceBitboards::bitboards[R], a1);
	BitboardFuncs::setBit(PieceBitboards::bitboards[N], b1);
	BitboardFuncs::setBit(PieceBitboards::bitboards[B], c1);
	BitboardFuncs::setBit(PieceBitboards::bitboards[Q], d1);
	BitboardFuncs::setBit(PieceBitboards::bitboards[K], e1);
	BitboardFuncs::setBit(PieceBitboards::bitboards[B], f1);
	BitboardFuncs::setBit(PieceBitboards::bitboards[N], g1);
	BitboardFuncs::setBit(PieceBitboards::bitboards[R], h1);
	
	// White Pieces
	BitboardFuncs::setBit(PieceBitboards::bitboards[r], a8);
	BitboardFuncs::setBit(PieceBitboards::bitboards[n], b8);
	BitboardFuncs::setBit(PieceBitboards::bitboards[b], c8);
	BitboardFuncs::setBit(PieceBitboards::bitboards[q], d8);
	BitboardFuncs::setBit(PieceBitboards::bitboards[k], e8);
	BitboardFuncs::setBit(PieceBitboards::bitboards[b], f8);
	BitboardFuncs::setBit(PieceBitboards::bitboards[n], g8);
	BitboardFuncs::setBit(PieceBitboards::bitboards[r], h8);
	
	
	PieceBitboards::set_side(0);
	PieceBitboards::set_enpassant(e3);
	PieceBitboards::set_castle(WK);
	PieceBitboards::set_castle(BQ);
	PieceBitboards::print_game_board();

	for (int piece = P; piece <= k; piece++)
	{
		BitboardFuncs::printBoard(PieceBitboards::bitboards[piece]);
	}

	return 0;
}
