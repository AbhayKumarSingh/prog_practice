#include "ctci\chapter01\q01_05\one_away.h"
#include "common\gtest_custom.h"

namespace ctest{
#if GTEST_HAS_PARAM_TEST

typedef bool(*T)(const std::string &, const std::string &);
CREATE_FIXTURE_CLASS(OneAwayTest, T, one_edit_away);

TEST_P(OneAwayTest, SameString){
	EXPECT_TRUE(one_edit_away("", ""));
	EXPECT_TRUE(one_edit_away("a", "a"));
	EXPECT_TRUE(one_edit_away("ab", "ab"));
	EXPECT_TRUE(one_edit_away("abcd", "abcd"));
}

TEST_P(OneAwayTest, InsertString){
	EXPECT_TRUE(one_edit_away("", "a"));
	EXPECT_TRUE(one_edit_away("a", "ab"));
	EXPECT_TRUE(one_edit_away("a", "ba"));
	EXPECT_TRUE(one_edit_away("abc", "aqbc"));
	EXPECT_TRUE(one_edit_away("abc", "abqc"));
	EXPECT_TRUE(one_edit_away("abc", "abqc"));
	EXPECT_TRUE(one_edit_away("abc", "qabc"));
	EXPECT_FALSE(one_edit_away("abc", "qabcq"));
	EXPECT_FALSE(one_edit_away("abc", "qabqcq"));
	EXPECT_FALSE(one_edit_away("abc", "tabrcq"));
	EXPECT_FALSE(one_edit_away("a", "pab"));
}

TEST_P(OneAwayTest, DeleteString){
	EXPECT_TRUE(one_edit_away("a", ""));
	EXPECT_TRUE(one_edit_away("ab", "a"));
	EXPECT_TRUE(one_edit_away("ba", "a"));
	EXPECT_TRUE(one_edit_away("aqbc", "abc"));
	EXPECT_TRUE(one_edit_away("abqc", "abc"));
	EXPECT_TRUE(one_edit_away("abqc", "abc"));
	EXPECT_TRUE(one_edit_away("qabc", "abc"));
	EXPECT_FALSE(one_edit_away("qabcq", "abc"));
	EXPECT_FALSE(one_edit_away("qabqcq", "abc"));
	EXPECT_FALSE(one_edit_away("tabrcq", "abc"));
	EXPECT_FALSE(one_edit_away("pab", "a"));
}

TEST_P(OneAwayTest, ReplaceString){
	EXPECT_TRUE(one_edit_away("a", "t"));
	EXPECT_TRUE(one_edit_away("t", "a"));
	EXPECT_TRUE(one_edit_away("a", "r"));
	EXPECT_TRUE(one_edit_away("r", "a"));
	EXPECT_TRUE(one_edit_away("abcd", "abrd"));
	EXPECT_TRUE(one_edit_away("abrd", "abcd"));
	EXPECT_TRUE(one_edit_away("abcd", "arcd"));
	EXPECT_TRUE(one_edit_away("arcd", "abcd"));
	EXPECT_TRUE(one_edit_away("abcd", "abcu"));
	EXPECT_TRUE(one_edit_away("abcu", "abcd"));
	EXPECT_FALSE(one_edit_away("abcd", "rbcr"));
	EXPECT_FALSE(one_edit_away("rbcr", "abcd"));
	EXPECT_FALSE(one_edit_away("a", "tr"));
	EXPECT_FALSE(one_edit_away("tr", "a"));
}

TEST_P(OneAwayTest, BookExamples){
	EXPECT_TRUE(one_edit_away("pale", "ple"));
	EXPECT_TRUE(one_edit_away("pales", "pale"));
	EXPECT_TRUE(one_edit_away("pale", "bale"));
	EXPECT_FALSE(one_edit_away("pale", "bae"));
}

INSTANTIATE_TEST_CASE_P(
	Implementations,
	OneAwayTest,
	::testing::Values(ctci::one_edit_away
			, ctci::one_edit_away_2));
#endif // GTEST_HAS_PARAM_TEST
} //namespace ctest