#include "ctci\chapter01\q01_04\palindrome_permutation.h"
#include "common\gtest_custom.h"

namespace ctest{
#if GTEST_HAS_PARAM_TEST

typedef bool(*T)(const std::string &);
CREATE_FIXTURE_CLASS(PalindromePermutationTest, T, is_permutation_of_palindrome);

TEST_P(PalindromePermutationTest, SomeTrivialStrings){
	EXPECT_TRUE(is_permutation_of_palindrome(""));
	EXPECT_TRUE(is_permutation_of_palindrome("aab"));
	EXPECT_TRUE(is_permutation_of_palindrome("accbccb"));
	EXPECT_TRUE(is_permutation_of_palindrome("aabcbc"));
	EXPECT_FALSE(is_permutation_of_palindrome("abcd"));
	EXPECT_FALSE(is_permutation_of_palindrome("accbcecb"));
	EXPECT_FALSE(is_permutation_of_palindrome("accfbcecb"));
}

TEST_P(PalindromePermutationTest, StringWithSpacesAndCapitals){
	EXPECT_TRUE(is_permutation_of_palindrome("Tact Coa"));
	EXPECT_TRUE(is_permutation_of_palindrome("Tact CoA"));
	EXPECT_TRUE(is_permutation_of_palindrome("Tact Co a"));
	EXPECT_FALSE(is_permutation_of_palindrome("Tact Copa"));
	EXPECT_FALSE(is_permutation_of_palindrome("Tact Co Pa"));
	EXPECT_FALSE(is_permutation_of_palindrome("Tact Co PA"));
}

INSTANTIATE_TEST_CASE_P(
	Implementations,
	PalindromePermutationTest,
	::testing::Values(ctci::is_permutation_of_palindrome
			, ctci::is_permutation_of_palindrome_2
			, ctci::is_permutation_of_palindrome_3));
#endif // GTEST_HAS_PARAM_TEST
} //namespace ctest