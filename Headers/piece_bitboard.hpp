#pragma once

#include "bishop_attacks.hpp"
#include "rook_attacks.hpp"
#include "bitboard.hpp"

struct PieceBitboards
{
	inline static U64 bitboards[12];
	inline static U64 occupancies[3];
	static void print_game_board();
	static void set_side(int side_set);
	static void set_enpassant(int sq);
	static void set_castle(int piece);
private:
	inline static int side_to_move = -1;
	inline static int en_passant = NOSQUARE;
	inline static uint8_t castle = 0b0000;
};