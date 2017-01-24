#include "urlify.h"

namespace ctci{

void replace_spaces(char * str){
	// count the number of spaces and string length.
	unsigned int number_spaces = 0;
	unsigned int i = 0;
	for (; str[i]; i++){
		if (str[i] == ' '){
			number_spaces++;
		}
	}

	// take two pointers and start copying from behind
	for (int back = i, new_back = back + (2 * number_spaces)
			; back >= 0
			; back--, new_back--){
		if (str[back] == ' '){
			str[new_back] = '0';
			new_back--;
			str[new_back] = '2';
			new_back--;
			str[new_back] = '%';
		}
		else{
			str[new_back] = str[back];
		}
	}
}
} // namespace ctci