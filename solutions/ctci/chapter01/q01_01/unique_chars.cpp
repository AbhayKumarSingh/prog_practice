#include "unique_chars.h"

namespace ctci{
bool is_unique_chars(std::string str){
	if (str.length() > 128){
		return false;
	}

	bool char_set[128] = {};
	for (unsigned int i = 0; i < str.length(); i++){
		int val = str.at(i);
		if (char_set[val]){
			return false;
		}
		char_set[val] = true;
	}
	return true;
}

bool is_unique_chars_2(std::string str){
	int checker = 0;
	for (unsigned int i = 0; i < str.length(); i++){
		int val = str.at(i) - 'a';
		if ((checker & (1 << val)) > 0){
			return false;
		}
		checker |= (1 << val);
	}
	return true;
}
} // namespace ctci