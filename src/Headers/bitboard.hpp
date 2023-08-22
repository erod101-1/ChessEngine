#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>
#define U64 unsigned long long //Bitboard date type

enum side {white , black, both};
enum rb {rook,bishop};
enum castling { WK = 1, WQ = 2, BK = 4, BQ = 8};
enum pieces { P = 0, N, B, R, Q, K, p, n, b, r, q, k };

/* Castling Rules
*	0001 White King castle King Side
*	0010 WK c QS
*	0100 BK c KS
*	1000 BK c QS
*/

struct PieceEncoding {
	inline static const std::string ascii_pieces =  "PNBRQKpnbrqk";
	inline static const std::map<char, int> char_pieces = {
		{'P', P},
		{'N', N},
		{'B', B},
		{'R', R},
		{'Q', Q},
		{'K' ,K},
		{'p', p},
		{'n', n},
		{'b', b},
		{'r', r},
		{'q', q},
		{'k' ,k},
	};
		
};


enum BoardSquares
{
	a8, b8, c8, d8, e8, f8, g8, h8,
	a7, b7, c7, d7, e7, f7, g7, h7,
	a6, b6, c6, d6, e6, f6, g6, h6,
	a5, b5, c5, d5, e5, f5, g5, h5,
	a4, b4, c4, d4, e4, f4, g4, h4,
	a3, b3, c3, d3, e3, f3, g3, h3,
	a2, b2, c2, d2, e2, f2, g2, h2,
	a1, b1, c1, d1, e1, f1, g1, h1, NOSQUARE
};


const std::string square_to_coord[] =
{
	"a8", "b8", "c8", "d8", "e8", "f8", "g8", "h8",
	"a7", "b7", "c7", "d7", "e7", "f7", "g7", "h7",
	"a6", "b6", "c6", "d6", "e6", "f6", "g6", "h6",
	"a5", "b5", "c5", "d5", "e5", "f5", "g5", "h5",
	"a4", "b4", "c4", "d4", "e4", "f4", "g4", "h4",
	"a3", "b3", "c3", "d3", "e3", "f3", "g3", "h3",
	"a2", "b2", "c2", "d2", "e2", "f2", "g2", "h2",
	"a1", "b1", "c1", "d1", "e1", "f1", "g1", "h1"
};	

namespace BitboardFuncs
{ 
	inline bool getBit(U64& bitBoard, int square) { // Checks if there is bit at a place on board
		return (bitBoard & (1ULL << square)) ? 1 : 0;
	}
	inline void setBit(U64& bitboard, int square) // Sets bit on square
	{
		bitboard |= 1ULL << square;
	}
	inline void popBit(U64& bitBoard, int square) // remove bit from board
	{
		getBit(bitBoard, square) ? (bitBoard ^= 1ULL << square) : 0;
	}

	void print_bit_board(U64 bitBoard);

	static int count_bits(U64 bitboard) {
		int count = 0;
		while (bitboard)
		{
			count++;

			//reset lsb
			bitboard &= bitboard - 1;
		}
		return count;
	}
	
	static int get_ls1b_index(U64 bitboard) {
		if (bitboard)
		{
			return BitboardFuncs::count_bits(((bitboard & -bitboard) - 1)); //index of LS1B
		}
		else
		{
			return -1; //invalid index
		}
	}
	U64 setOccupied(int index, int bits_in_mask, U64 attack_mask);
};

struct NotFiles { // Gives acess to our not files
	static const U64 not_A_file = 18374403900871474942ULL; // Every bit high except A file
	static const U64 not_H_file = 9187201950435737471ULL; // Every bit high except H file
	static const U64 not_HG_file = 4557430888798830399ULL; // Every bit high except HG file
	static const U64 not_AB_file = 18229723555195321596ULL; // ect.
};

struct NumMovesLookUp { 
	static constexpr int bishop_relevant_bits[64] =
	{
		6, 5, 5, 5, 5, 5, 5, 6,
		5, 5, 5, 5, 5, 5, 5, 5,
		5, 5, 7, 7, 7, 7, 5, 5,
		5, 5, 7, 9, 9, 7, 5, 5,
		5, 5, 7, 9, 9, 7, 5, 5,
		5, 5, 7, 7, 7, 7, 5, 5,
		5, 5, 5, 5, 5, 5, 5, 5,
		6, 5, 5, 5, 5, 5, 5, 6
	};
	static constexpr int rook_relevant_bits[64] =
	{
		12, 11, 11, 11, 11, 11, 11, 12,
		11, 10, 10, 10, 10, 10, 10, 11,
		11, 10, 10, 10, 10, 10, 10, 11,
		11, 10, 10, 10, 10, 10, 10, 11,
		11, 10, 10, 10, 10, 10, 10, 11,
		11, 10, 10, 10, 10, 10, 10, 11,
		11, 10, 10, 10, 10, 10, 10, 11,
		12, 11, 11, 11, 11, 11, 11, 12
	};
};

