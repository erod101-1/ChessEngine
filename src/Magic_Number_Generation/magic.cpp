#include "..\Headers\magic.hpp"


U64 Magic::get_random_U64_number()
{
	U64 n1, n2, n3, n4;

	n1 = (U64)(Magic::get_random_U32_number() & 0xFFFF);
	n2 = (U64)(Magic::get_random_U32_number() & 0xFFFF);
	n3 = (U64)(Magic::get_random_U32_number() & 0xFFFF);
	n4 = (U64)(Magic::get_random_U32_number() & 0xFFFF);
	return  n1 | (n2 << 16) | (n3 << 32) | (n4 << 48);
}

U64 Magic::get_possible_magic_number()
{
	return (get_random_U64_number() & get_random_U64_number() & get_random_U64_number());
}

U64 Magic::find_magic_number(int square, int relevant_bits, int bishop)
{
 
    static std::vector<U64> occupancies(4096);
    static std::vector<U64> attacks(4096);
    static std::vector<U64> used_attacks(4096);

     U64 attack_mask = bishop ? BishopAttacks::mask_bishop_attacks(square) : RookAttacks::mask_rook_attacks(square);

 
    int occupancy_indicies = 1 << relevant_bits;

   
    for (int index = 0; index < occupancy_indicies; index++)
    {
    
        occupancies[index] = BitboardFuncs::setOccupied(index, relevant_bits, attack_mask);

       
        attacks[index] = bishop ? BishopAttacks::generate_bishop_attacks(square, occupancies[index]) :
            RookAttacks::generate_rook_attacks(square, occupancies[index]);
    }

  
    for (int random_count = 0; random_count < 100000000; random_count++)
    {

        U64 magic_number = Magic::get_possible_magic_number();

        if (BitboardFuncs::count_bits((attack_mask * magic_number) & 0xFF00000000000000) < 6) continue;
        std::memset(used_attacks.data(), 0ULL, used_attacks.size()*sizeof(U64));
        int index, fail;
        for (index = 0, fail = 0; !fail && index < occupancy_indicies; index++)
        {

            int magic_index = (int)((occupancies[index] * magic_number) >> (64 - relevant_bits));
            if (used_attacks[magic_index] == 0ULL)

                used_attacks[magic_index] = attacks[index];

            else if (used_attacks[magic_index] != attacks[index])

                fail = 1;
        }
        if (!fail)
            return magic_number;
    }
    printf("  Magic number fails!\n");
    return 0ULL;
}


void Magic::init_magic_numbers()
{
	/*for (int square = 0; square < 64; square++)
	{
		printf("0x%llxULL, \n",Magic::find_magic_number(square, NumMovesLookUp::rook_relevant_bits[square], rook));
	}

    std::cout << "Bishop " << std::endl;
    for (int square = 0; square < 64; square++)
    {
        printf("0x%llxULL, \n", Magic::find_magic_number(square, NumMovesLookUp::bishop_relevant_bits[square], bishop));
    }*/
}