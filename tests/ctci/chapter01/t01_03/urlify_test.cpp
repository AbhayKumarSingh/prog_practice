#include "ctci\chapter01\q01_03\urlify.h"
#include "gtest\gtest.h"

namespace ctest{
namespace {
char arr[200] = {};

void expect_equal(char *input, char *expected){
	strcpy(arr, input);
	ctci::replace_spaces(arr);
	EXPECT_STREQ(arr, expected);
}
}
TEST(UrlifyTest, EmptyString){
	expect_equal("", "");
}

TEST(UrlifyTest, MultipleEmptySpace){
	expect_equal("hel l  o", "hel%20l%20%20o");
	expect_equal("hello   bro  . HI", "hello%20%20%20bro%20%20.%20HI");
}

TEST(UrlifyTest, OnlyGaps){
	expect_equal(" ", "%20");
	expect_equal("  ", "%20%20");
	expect_equal("   ", "%20%20%20");
}

TEST(UrlifyTest, GapAtTheEnd){
	expect_equal("what is that? ", "what%20is%20that?%20");
	expect_equal("what is that?  ", "what%20is%20that?%20%20");
	expect_equal("what is that?   ", "what%20is%20that?%20%20%20");
}

TEST(UrlifyTest, StringWithSpecialCharacters){
	expect_equal("what%20i,s%20that?", "what%20i,s%20that?");
	expect_equal("what%20is% 20that?", "what%20is%%2020that?");
}

TEST(UrlifyTest, SimpleGaps){
	expect_equal("what is that?", "what%20is%20that?");
}

TEST(UrlifyTest, TextBookExample){
	expect_equal("Mr John Smith", "Mr%20John%20Smith");
}
} // namespace ctest