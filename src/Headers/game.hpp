#pragma once
#include "pawn_attacks.hpp"
#include "king_attacks.hpp"
#include "knight_attacks.hpp"
#include "bishop_attacks.hpp"
#include "rook_attacks.hpp"
#include "bitboard.hpp"
#include "sliders.hpp"


class Game
{
public:
	inline static U64 bitboards[12];
	inline static U64 occupancies[3];
	static void print_game_board();
	static void set_side(int side_set);
	static void set_enpassant(int sq);
	static void set_castle(int piece);
	static void init_all_attacks();
	inline static int is_square_attacked(int square, int side);
	static void print_attacked_square();
private:
	inline static int side_to_move = -1;
	inline static int en_passant = NOSQUARE;
	inline static uint8_t castle = 0b0000;
};

class FenReader
{
public:
	static void parse_fen(char* fen);

	inline static  char* empty_board = "8/8/8/8/8/8/8/8 w - - ";
	inline static  char* start_position = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1 ";
						
	// Testing Positions
	inline static char* tricky_position = "r3k2r/p1ppqpb1/bn2pnp1/3PN3/1p2P3/2N2Q1p/PPPBBPPP/R3K2R w KQkq - 0 1 ";
	inline static char* killer_position = "rnbqkb1r/pp1p1pPp/8/2p1pP2/1P1P4/3P3P/P1P1P3/RNBQKBNR w KQkq e6 0 1";
	inline static char* cmk_position = "r2q1rk1/ppp2ppp/2n1bn2/2b1p3/3pP3/3P1NPP/PPP1NPB1/R1BQ1RK1 b - - 0 9 ";

};
