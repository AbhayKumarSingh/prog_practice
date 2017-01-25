#include <sstream>
#include "string_compression.h"

namespace ctci{
std::string compress(const std::string &str){
	std::string compressed = "";
	int count = 0;

	for (size_t i = 0; i < str.length(); ++i){
		++count;
		if(i >= str.length() - 1 || str[i] != str[i + 1]){
			compressed += str[i] + std::to_string(count);
			count = 0;
		}
	}

	return compressed.length() < str.length() ? compressed : str;
}

std::string compress_2(const std::string &str){
	std::stringstream compressedStream;
	int count = 0;

	for (size_t i = 0; i < str.length(); ++i){
		++count;
		if (i >= str.length() - 1 || str[i] != str[i + 1]){
			compressedStream << str[i] << count;
			count = 0;
		}
	}
	std::string compressed (compressedStream.str());
	return compressed.length() < str.length() ? compressed : str;
}

namespace{
int count_compress(const std::string &str){
	int length = 0;
	int count = 0;
	for (size_t i = 0; i < str.length(); ++i){
		++count;
		if (i >= str.length() - 1 || str[i] != str[i + 1]){
			length += 1 + std::to_string(count).length();
			count = 0;
		}
	}
	return length;
}
} // namespace

std::string compress_3(const std::string &str){
	std::string compressed; // empty string
	size_t compressed_length = count_compress(str);
	if (compressed_length >= str.length()){
		return str;
	}

	compressed.reserve(compressed_length);
	int count = 0;

	for (size_t i = 0; i < str.length(); ++i){
		++count;
		if (i >= str.length() - 1 || str[i] != str[i + 1]){
			compressed += str[i];
			compressed += std::to_string(count);
			count = 0;
		}
	}

	return compressed;

}
} // namespace ctci