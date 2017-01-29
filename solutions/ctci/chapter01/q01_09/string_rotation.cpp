#include "string_rotation.h"

namespace ctci{
bool is_rotation(const std::string &s1, const std::string &s2){
	if (s1.length() != s2.length())
		return false;
	std::string s2s2 = s2 + s2;
	return s2s2.find(s1) != std::string::npos;
}
} // namespace ctci