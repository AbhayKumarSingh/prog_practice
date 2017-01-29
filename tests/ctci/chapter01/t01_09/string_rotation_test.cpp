#include "ctci\chapter01\q01_09\string_rotation.h"
#include "gtest\gtest.h"

namespace ctest{
using ctci::is_rotation;

TEST(StringRotationTest, EmptyString){
	EXPECT_TRUE(is_rotation("",""));
}

TEST(StringRotationTest, SingleSize){
	EXPECT_TRUE(is_rotation("p", "p"));
	EXPECT_TRUE(is_rotation("e", "e"));
}

TEST(StringRotationTest, TwoSize){
	EXPECT_TRUE(is_rotation("av", "av"));
	EXPECT_TRUE(is_rotation("av", "va"));
	EXPECT_FALSE(is_rotation("av", "ba"));
}

TEST(StringRotationTest, DifferentChars){
	EXPECT_FALSE(is_rotation("waterbottle", "erbittlowat"));
	EXPECT_FALSE(is_rotation("erbittlowat", "waterbottle"));
}

TEST(StringRotationTest, CapitalsIncluded){
	EXPECT_TRUE(is_rotation("waterBottle", "erBottlewat"));
	EXPECT_FALSE(is_rotation("waterBottle", "erbottlewat"));
	EXPECT_TRUE(is_rotation("erBottlewat", "waterBottle"));
}

TEST(StringRotationTest, AllSameChars){
	EXPECT_TRUE(is_rotation("aaaaa", "aaaaa"));
	EXPECT_TRUE(is_rotation("gggg", "gggg"));
}

TEST(StringRotationTest, DifferentSize){
	EXPECT_FALSE(is_rotation("abcd", "abcdef"));
	EXPECT_FALSE(is_rotation("abcdef", "abcd"));
}

TEST(StringRotationTest, BookEg){
	EXPECT_TRUE(is_rotation("waterbottle", "erbottlewat"));
	EXPECT_TRUE(is_rotation("erbottlewat", "waterbottle"));
}
} // namespace ctest