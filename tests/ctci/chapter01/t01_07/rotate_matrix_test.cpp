#include "ctci\chapter01\q01_07\rotate_matrix.h"
#include "gmock\gmock.h"
#include <iostream>

namespace ctest{
TEST(RotateMatrixTest, One){
	int a[][ctci::ROTATE_MAX] = {
		{ 1 } };
	int b[][ctci::ROTATE_MAX] = {
		{ 1 } };
	ctci::rotate(a, 1);
	EXPECT_THAT(a, ::testing::ContainerEq(b));
}

TEST(RotateMatrixTest, Two){
	int a[][ctci::ROTATE_MAX] = {
		{ 1, 2 },
		{ 5, 6 } };
	int b[][ctci::ROTATE_MAX] = {
		{ 5, 1 },
		{ 6, 2 } };
	ctci::rotate(a, 2);
	EXPECT_THAT(a, ::testing::ContainerEq(b));
}

TEST(RotateMatrixTest, Three){
	int a[][ctci::ROTATE_MAX] = {
		{  1,   2,   3},
		{  5,   6,   7},
		{ 13,  14,  15} };
	int b[][ctci::ROTATE_MAX] = {
		{ 13,   5,   1},
		{ 14,   6,   2},
		{ 15,   7,   3} };
	ctci::rotate(a, 3);
	EXPECT_THAT(a, ::testing::ContainerEq(b));
}

TEST(RotateMatrixTest, Four){
	int a[][ctci::ROTATE_MAX] = {
		{  1,   2,   3,   4 },
		{  5,   6,   7,   8 },
		{  9,  10,  11,  12 },
		{ 13,  14,  15,  16 } };
	int b[][ctci::ROTATE_MAX] = {
		{ 13,   9,   5,   1 },
		{ 14,  10,   6,   2 },
		{ 15,  11,   7,   3 },
		{ 16,  12,   8,   4 } };
	ctci::rotate(a, 4);
	EXPECT_THAT(a, ::testing::ContainerEq(b));
}

TEST(RotateMatrixTest, Five){
	int a[][ctci::ROTATE_MAX] = {
		{  1,   2,   3,   4,   2 },
		{  5,   6,   7,   8,   2 },
		{  9,  10,  11,  12,   2 },
		{ 13,  14,  15,  16,   2 },
		{ 13,  14,  15,  16,   2 } };
	int b[][ctci::ROTATE_MAX] = {
		{ 13,  13,   9,   5,   1 },
		{ 14,  14,  10,   6,   2 },
		{ 15,  15,  11,   7,   3 },
		{ 16,  16,  12,   8,   4 },
		{  2,   2,   2,   2,   2 } };
	ctci::rotate(a, 5);
	EXPECT_THAT(a, ::testing::ContainerEq(b));
}

TEST(RotateMatrixTest, Six){
	int a[][ctci::ROTATE_MAX] = {
		{  1,   2,   3,   4,   2,   9 },
		{  5,   6,   7,   8,   2,   9 },
		{  8,   8,   8,   8,   8,   9 },
		{  9,  10,  11,  12,   2,   9 },
		{ 13,  14,  15,  16,   2,   9 },
		{ 13,  14,  15,  16,   2,   9 } };
	int b[][ctci::ROTATE_MAX] = {
		{ 13,  13,   9,   8,   5,  1 },
		{ 14,  14,  10,   8,   6,  2 },
		{ 15,  15,  11,   8,   7,  3 },
		{ 16,  16,  12,   8,   8,  4 },
		{  2,   2,   2,   8,   2,  2 },
		{  9,   9,   9,   9,   9,  9 } };
	ctci::rotate(a, 6);
	EXPECT_THAT(a, ::testing::ContainerEq(b));
}
} // namespace ctest