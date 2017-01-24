#include "check_permutation.h"
#include <algorithm>

namespace ctci{

bool permutation(std::string s, std::string t){
	if (s.size() != t.size()){
		return false;
	}
	std::sort(s.begin(), s.end());
	std::sort(t.begin(), t.end());

	return s == t;
}

bool permutation_2(std::string s, std::string t){
	if (s.size() != t.size()){
		return false;
	}
	int count[128] = {}; // Assumption
	for (const auto& c : s){
		count[c]++;
	}

	for (const auto& c : t){
		count[c]--;
		if (count[c] < 0){
			return false;
		}
	}

	return true;
}
} //namespace ctci