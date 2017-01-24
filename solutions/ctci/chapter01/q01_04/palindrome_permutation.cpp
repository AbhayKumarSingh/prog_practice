#include "palindrome_permutation.h"

namespace ctci{
namespace{
int get_char_number(char c){
	if (c >= 'a' && c <= 'z'){
		return c - 'a';
	}
	else if (c >= 'A' && c <= 'Z'){
		return c - 'A';
	}
	return -1;
}

void build_count_table(const std::string &phrase, int counts[]){
	for (const char & c : phrase){
		int char_number = get_char_number(c);
		if ( char_number != -1){
			++counts[char_number];
		}
	}
}

template <int MAX>
bool atmost_one_odd(int (&counts)[MAX]){
	// traverse the new array verifying that all are even only atmost
	// one is seen odd number of times
	int odds_count = 0;
	for (auto count : counts){
		if (count % 2 != 0){
			odds_count++;
			if (odds_count > 1){
				return false;
			}
		}
	}
	return true;
}
} // namespace

bool is_permutation_of_palindrome(const std::string & phrase){
	int counts[26] = {};
	build_count_table(phrase, counts);
	return atmost_one_odd(counts);
}

bool is_permutation_of_palindrome_2(const std::string & phrase){
	int counts[26] = {};
	int number_of_odds = 0;

	for (const char & c : phrase){
		int char_number = get_char_number(c);
		if (char_number != -1){
			++counts[char_number];
			if (0 != counts[char_number] % 2){ // if odd
				++number_of_odds;
			}
			else{
				--number_of_odds;
			}
		}
	}
	return number_of_odds <= 1;
}

namespace{
void toggle(int &vector, int char_number){
	int mask = 1 << char_number;
	vector ^= mask;
}

bool atmost_one_bit_set(const int &vector){
	return 0 == vector || 0 == (vector & vector - 1);
}
} // namespace

bool is_permutation_of_palindrome_3(const std::string & phrase){
	int vector = 0;

	for (const char & c : phrase){
		int char_number = get_char_number(c);
		if (char_number != -1){
			toggle(vector, char_number);
		}
	}
	return atmost_one_bit_set(vector);
}
} // namespace ctci
