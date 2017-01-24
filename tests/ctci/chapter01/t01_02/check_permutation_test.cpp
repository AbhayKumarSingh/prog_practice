#include "ctci\chapter01\q01_02\check_permutation.h"
#include "common\gtest_custom.h"

namespace ctest{
#if GTEST_HAS_PARAM_TEST

typedef bool(*T)(std::string, std::string);
CREATE_FIXTURE_CLASS(CheckPermutationTest, T, permutation);

TEST_P(CheckPermutationTest, EmptyStrings){
	EXPECT_TRUE(permutation("", ""));
	EXPECT_FALSE(permutation("", "ap"));
	EXPECT_FALSE(permutation("tap", ""));
}

TEST_P(CheckPermutationTest, UnequalLengthStrings){
	EXPECT_FALSE(permutation("abcd", "ab"));
	EXPECT_FALSE(permutation("abcd", "abcde"));
	EXPECT_FALSE(permutation("abc", "abcd"));
	EXPECT_FALSE(permutation("abcde", "abcd"));
}

TEST_P(CheckPermutationTest, StringPermutationOfItself){
	EXPECT_TRUE(permutation("tom", "tom"));
	EXPECT_TRUE(permutation("mango", "mango"));
}

TEST_P(CheckPermutationTest, SimplePermutation){
	EXPECT_TRUE(permutation("mango", "gnoma"));
	EXPECT_TRUE(permutation("gnoma", "mango"));
}

TEST_P(CheckPermutationTest, PermutationNegative){
	EXPECT_FALSE(permutation("mango", "mnaot"));
	EXPECT_FALSE(permutation("mnaot", "mango"));
	EXPECT_FALSE(permutation("mango", "abcde"));
}

TEST_P(CheckPermutationTest, CapitalLetterPositive){
	EXPECT_TRUE(permutation("Abcd", "cbAd"));
	EXPECT_TRUE(permutation("ToM", "oTM"));
}

TEST_P(CheckPermutationTest, CapitalLetterNegative){
	EXPECT_FALSE(permutation("Abcd", "cbad"));
	EXPECT_FALSE(permutation("ToM", "otm"));
}

TEST_P(CheckPermutationTest, MultipleLetters){
	EXPECT_TRUE(permutation("apple", "papel"));
	EXPECT_TRUE(permutation("carrot", "tarroc"));
	EXPECT_FALSE(permutation("hello", "llloh"));
}

TEST_P(CheckPermutationTest, Spaces){
	EXPECT_TRUE(permutation("he is a good person", "heisagoo d  p erson"));
	EXPECT_FALSE(permutation("he is a good person", "heisagoo d  person"));
}
INSTANTIATE_TEST_CASE_P(
	Implementations,
	CheckPermutationTest,
	::testing::Values(ctci::permutation, ctci::permutation_2));
#endif // GTEST_HAS_PARAM_TEST
} // namespace ctest