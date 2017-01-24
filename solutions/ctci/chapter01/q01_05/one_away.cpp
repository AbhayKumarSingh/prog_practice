//#include <cstdlib>
#include "one_away.h"

namespace ctci{
namespace{
// assumption that first is smaller than second
bool one_insert_away(const std::string &init, const std::string &after){
	unsigned int different = 0;
	auto init_it = init.begin();
	auto after_it = after.begin();
	while (init_it != init.end() && after_it != after.end()){
		if (*init_it != *after_it){
			++different;
			if (different > 1){
				return false;
			}
			++after_it;
		}
		else{
			++init_it;
			++after_it;
		}
	}
	return true;
}

bool one_replace_away(const std::string &init, const std::string &after){
	unsigned int different = 0;
	auto init_it = init.begin();
	auto after_it = after.begin();
	while (init_it != init.end()){
		if (*init_it != *after_it){
			++different;
			if (different > 1){
				return false;
			}
		}
		++init_it;
		++after_it;
	}
	return true;
}
} // namespace

bool one_edit_away(const std::string &first, const std::string &second){
	if (first.length() == second.length()){
		return one_replace_away(first, second);
	}
	else if (first.length() + 1 == second.length()){
		return one_insert_away(first, second);
	}
	else if (first.length() - 1 == second.length()){
		return one_insert_away(second, first);
	}
	return false;
}

namespace{
size_t diff(size_t a, size_t b){
	return a > b ? a - b : b - a;
}
} // namespace

bool one_edit_away_2(const std::string &first, const std::string &second){
	if (diff(first.length(), second.length()) > 1){
		return false;
	}
	std::string small = first.length() < second.length() ? first : second;
	std::string large = first.length() < second.length() ? second : first;
	
	unsigned int different = 0;
	auto small_it = small.begin();
	auto large_it = large.begin();
	while (small_it != small.end() && large_it != large.end()){
		if (*small_it != *large_it){
			++different;
			if (different > 1){
				return false;
			}
			if (small.length() == large.length()){ // incase of replace
				++small_it;
			}
		}
		else{
			++small_it;
		}
		++large_it;
	}
	return true;

}

} // namespace ctci
