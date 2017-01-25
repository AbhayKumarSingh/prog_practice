#include "ctci\chapter01\q01_06\string_compression.h"
#include "common\gtest_custom.h"

namespace ctest{
#if GTEST_HAS_PARAM_TEST

typedef std::string (*T)(const std::string &);
CREATE_FIXTURE_CLASS(StringCompressionTest, T, compress);

TEST_P(StringCompressionTest, EmptyString){
	EXPECT_EQ(compress(""), "");
}

TEST_P(StringCompressionTest, SomeSimpleStrings){
	EXPECT_EQ(compress("aabbccaaa"), "a2b2c2a3");
	EXPECT_EQ(compress("aabcccccaaa"), "a2b1c5a3");
}

TEST_P(StringCompressionTest, CapitalsIncluded){
	EXPECT_EQ(compress("aabcccAAccaaa"), "a2b1c3A2c2a3");
	EXPECT_EQ(compress("AABBBCC"), "A2B3C2");
}

TEST_P(StringCompressionTest, NonCompactable){
	EXPECT_EQ(compress("ab"), "ab");
	EXPECT_EQ(compress("aabb"), "aabb");
	EXPECT_EQ(compress("abcd"), "abcd");
	EXPECT_EQ(compress("apple"), "apple");
	EXPECT_EQ(compress("aabcccAAccaa"), "aabcccAAccaa");
}

TEST_P(StringCompressionTest, VeryLongStrings){
	EXPECT_EQ(compress("aaaaaaaaaabcdefghijklmnopqrstuvwxyz"), "aaaaaaaaaabcdefghijklmnopqrstuvwxyz");
	EXPECT_EQ(compress("aaaaaaaaaabcdefgh"), "aaaaaaaaaabcdefgh");
	EXPECT_EQ(compress("aaaaaaaaaabcdefg"), "a10b1c1d1e1f1g1");
}

INSTANTIATE_TEST_CASE_P(
	Implementations,
	StringCompressionTest,
	::testing::Values(ctci::compress
	, ctci::compress_2, ctci::compress_3));
#endif // GTEST_HAS_PARAM_TEST
} //namespace ctest