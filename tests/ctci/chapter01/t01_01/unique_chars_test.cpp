#include "ctci\chapter01\q01_01\unique_chars.h"
#include "common\gtest_custom.h"

namespace ctest{
#if GTEST_HAS_PARAM_TEST

typedef bool(*T)(std::string);
CREATE_FIXTURE_CLASS(UniqueCharsTest, T, is_unique_chars);

TEST_P(UniqueCharsTest, EmptyStringHasUniqueChars){
	EXPECT_TRUE(is_unique_chars(""));
}

TEST_P(UniqueCharsTest, SingleCharString){
	EXPECT_TRUE(is_unique_chars("b"));
	EXPECT_TRUE(is_unique_chars("a"));
}

TEST_P(UniqueCharsTest, TwoCharsString){
	EXPECT_TRUE(is_unique_chars("ab"));
	EXPECT_FALSE(is_unique_chars("bb"));
	EXPECT_FALSE(is_unique_chars("aa"));
}

TEST_P(UniqueCharsTest, StringWithUniqueChars){
	EXPECT_TRUE(is_unique_chars("abcd"));
	EXPECT_TRUE(is_unique_chars("rats"));
	EXPECT_TRUE(is_unique_chars("hat"));
}

TEST_P(UniqueCharsTest, StringWithRepeatingChars){
	EXPECT_FALSE(is_unique_chars("aba"));
	EXPECT_FALSE(is_unique_chars("tomato"));
	EXPECT_FALSE(is_unique_chars("apple"));
}

TEST_P(UniqueCharsTest, StringWithThreeRepeatingChars){
	EXPECT_FALSE(is_unique_chars("aptplpe"));
	EXPECT_FALSE(is_unique_chars("apppe"));
}

TEST(UniqueCharsTest, Imp1Specific){
	EXPECT_TRUE(::ctci::is_unique_chars("apPlLe"));
}

TEST(UniqueCharsTest, Imp2Specific){
	EXPECT_FALSE(::ctci::is_unique_chars_2("apPlLe"));
}

INSTANTIATE_TEST_CASE_P(
	Implementations,
	UniqueCharsTest,
	::testing::Values(ctci::is_unique_chars, ctci::is_unique_chars_2));

#else

	TEST(DummyTest, ValueParameterizedTestsAreNotSupportedOnThisPlatform) {}

#endif // GTEST_HAS_PARAM_TEST
} // namespace ctest