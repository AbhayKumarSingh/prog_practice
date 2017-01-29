#include "ctci\chapter01\q01_08\zero_matrix.h"
#include "common\gtest_custom.h"
#include "gmock\gmock.h"

namespace ctest{
#if GTEST_HAS_PARAM_TEST

template <size_t M, size_t N>
using T = void (*)(int(&matrix)[M][N]);

template<size_t K, size_t L>
class ZeroMatrixTest : public ::testing::TestWithParam<T<K,L>> {
protected:
   virtual void SetUp() { set_zeros = GetParam(); }
   T<K,L> set_zeros;
};

#define R 1
#define C 1
typedef ZeroMatrixTest<R, C> ZeroMatrixTest1N1;
TEST_P(ZeroMatrixTest1N1, P1){
	int a[][C] = { 4 };
	int b[][C] = { 4 };
	set_zeros(a);
	EXPECT_THAT( a, ::testing::ContainerEq(b));
	a[0][0] = 0;
	b[0][0] = 0;
	set_zeros(a);
	EXPECT_THAT(a, ::testing::ContainerEq(b));
}

INSTANTIATE_TEST_CASE_P(
	Implementations,
	ZeroMatrixTest1N1,
	::testing::Values(ctci::set_zeros<R, C>
	, ctci::set_zeros_2<R, C>));

#undef R
#undef C
#define R 1
#define C 5
typedef ZeroMatrixTest<R, C> ZeroMatrixTest1N5;
TEST_P(ZeroMatrixTest1N5, P1){
	int a[][C] = { { 1, 0, 3, 4, 5 } };
	int b[][C] = { { 0, 0, 0, 0, 0 } };
	set_zeros(a);
	EXPECT_THAT(a, ::testing::ContainerEq(b));
}

TEST_P(ZeroMatrixTest1N5, P2){
	int a[][C] = { { 1, 7, 3, 4, 5 } };
	int b[][C] = { { 1, 7, 3, 4, 5 } };
	set_zeros(a);
	EXPECT_THAT(a, ::testing::ContainerEq(b));
}

TEST_P(ZeroMatrixTest1N5, P3){
	int a[][C] = { { 0, 0, 0, 0, 0 } };
	int b[][C] = { { 0, 0, 0, 0, 0 } };
	set_zeros(a);
	EXPECT_THAT(a, ::testing::ContainerEq(b));
}


INSTANTIATE_TEST_CASE_P(
	Implementations,
	ZeroMatrixTest1N5,
	::testing::Values(ctci::set_zeros<R, C>
	, ctci::set_zeros_2<R, C>));

#undef R
#undef C
#define R 5
#define C 1
typedef ZeroMatrixTest<R, C> ZeroMatrixTest5N1;
TEST_P(ZeroMatrixTest5N1, P1){
	int a[R][C] = { 1, 3, 3, 4, 0 } ;
	int b[R][C] = { 0, 0, 0, 0, 0 };
	set_zeros(a);
	EXPECT_THAT(a, ::testing::ContainerEq(b));
}

TEST_P(ZeroMatrixTest5N1, P2){
	int a[R][C] = { 1, 7, 3, 4, 5 };
	int b[R][C] = { 1, 7, 3, 4, 5 };
	set_zeros(a);
	EXPECT_THAT(a, ::testing::ContainerEq(b));
}

TEST_P(ZeroMatrixTest5N1, P3){
	int a[R][C] = { 0, 0, 0, 0, 0 };
	int b[R][C] = { 0, 0, 0, 0, 0 };
	set_zeros(a);
	EXPECT_THAT(a, ::testing::ContainerEq(b));
}

INSTANTIATE_TEST_CASE_P(
	Implementations,
	ZeroMatrixTest5N1,
	::testing::Values(ctci::set_zeros<R, C>
	, ctci::set_zeros_2<R, C>));

#undef R
#undef C
#define R 2
#define C 3
typedef ZeroMatrixTest<R, C> ZeroMatrixTest2N3;
TEST_P(ZeroMatrixTest2N3, P1){
	int a[][C] = {
		{ 1, 0, 3 },
		{ 4, 5, 6 } };

	int b[][C] = {
		{ 0, 0, 0 },
		{ 4, 0, 6 } };
	set_zeros(a);
	EXPECT_THAT(a, ::testing::ContainerEq(b));
}

TEST_P(ZeroMatrixTest2N3, P2){
	int a[][C] = {
		{ 1, 2, 3 },
		{ 4, 5, 6 } };

	int b[][C] = {
		{ 1, 2, 3 },
		{ 4, 5, 6 } };
	set_zeros(a);
	EXPECT_THAT(a, ::testing::ContainerEq(b));
}

TEST_P(ZeroMatrixTest2N3, P3){
	int a[][C] = {
		{ 0, 2, 3 },
		{ 4, 5, 0 } };

	int b[][C] = {
		{ 0, 0, 0 },
		{ 0, 0, 0 } };
	set_zeros(a);
	EXPECT_THAT(a, ::testing::ContainerEq(b));
}

INSTANTIATE_TEST_CASE_P(
	Implementations,
	ZeroMatrixTest2N3,
	::testing::Values(ctci::set_zeros<R,C>
	, ctci::set_zeros_2<R,C>));

#undef R
#undef C
#define R 5
#define C 6
typedef ZeroMatrixTest<R, C> ZeroMatrixTest5N6;
TEST_P(ZeroMatrixTest5N6, P1){
	int a[][C] = {
		{ 1, 2, 3, 4, 5, 6 },
		{ 7, 5, 2, 5, 8, 3 },
		{ 9, 6, 2, 3, 2, 5 },
		{ 2, 9, 1, 3, 4, 3 },
		{ 4, 5, 6, 7, 5, 9 } };

	int b[][C] = {
		{ 1, 2, 3, 4, 5, 6 },
		{ 7, 5, 2, 5, 8, 3 },
		{ 9, 6, 2, 3, 2, 5 },
		{ 2, 9, 1, 3, 4, 3 },
		{ 4, 5, 6, 7, 5, 9 } };
	set_zeros(a);
	EXPECT_THAT(a, ::testing::ContainerEq(b));
}

TEST_P(ZeroMatrixTest5N6, P2){
	int a[][C] = {
		{ 1, 2, 3, 4, 5, 6 },
		{ 7, 5, 0, 5, 8, 3 },
		{ 9, 6, 2, 3, 2, 5 },
		{ 2, 9, 1, 3, 0, 3 },
		{ 4, 5, 6, 7, 5, 9 } };

	int b[][C] = {
		{ 1, 2, 0, 4, 0, 6 },
		{ 0, 0, 0, 0, 0, 0 },
		{ 9, 6, 0, 3, 0, 5 },
		{ 0, 0, 0, 0, 0, 0 },
		{ 4, 5, 0, 7, 0, 9 } };
	set_zeros(a);
	EXPECT_THAT(a, ::testing::ContainerEq(b));
}

TEST_P(ZeroMatrixTest5N6, P3){
	int a[][C] = {
		{ 1, 2, 3, 4, 5, 6 },
		{ 7, 5, 0, 0, 8, 3 },
		{ 9, 6, 2, 3, 2, 5 },
		{ 2, 9, 1, 3, 0, 3 },
		{ 4, 5, 6, 7, 5, 9 } };

	int b[][C] = {
		{ 1, 2, 0, 0, 0, 6 },
		{ 0, 0, 0, 0, 0, 0 },
		{ 9, 6, 0, 0, 0, 5 },
		{ 0, 0, 0, 0, 0, 0 },
		{ 4, 5, 0, 0, 0, 9 } };
	set_zeros(a);
	EXPECT_THAT(a, ::testing::ContainerEq(b));
}

TEST_P(ZeroMatrixTest5N6, P4){
	int a[][C] = {
		{ 1, 2, 3, 4, 5, 6 },
		{ 7, 5, 0, 7, 8, 3 },
		{ 9, 6, 2, 3, 0, 5 },
		{ 2, 9, 1, 3, 0, 3 },
		{ 4, 5, 6, 7, 5, 9 } };

	int b[][C] = {
		{ 1, 2, 0, 4, 0, 6 },
		{ 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0 },
		{ 4, 5, 0, 7, 0, 9 } };
	set_zeros(a);
	EXPECT_THAT(a, ::testing::ContainerEq(b));
}

TEST_P(ZeroMatrixTest5N6, P5){
	int a[][C] = {
		{ 1, 2, 3, 4, 5, 0 },
		{ 7, 5, 2, 5, 8, 3 },
		{ 9, 6, 2, 3, 2, 5 },
		{ 2, 9, 1, 3, 4, 3 },
		{ 0, 5, 6, 7, 5, 9 } };

	int b[][C] = {
		{ 0, 0, 0, 0, 0, 0 },
		{ 0, 5, 2, 5, 8, 0 },
		{ 0, 6, 2, 3, 2, 0 },
		{ 0, 9, 1, 3, 4, 0 },
		{ 0, 0, 0, 0, 0, 0 } };
	set_zeros(a);
	EXPECT_THAT(a, ::testing::ContainerEq(b));
}

TEST_P(ZeroMatrixTest5N6, P6){
	int a[][C] = {
		{ 1, 2, 3, 4, 5, 7 },
		{ 7, 5, 2, 5, 8, 3 },
		{ 9, 6, 2, 0, 2, 5 },
		{ 2, 9, 1, 3, 4, 3 },
		{ 8, 5, 6, 7, 5, 9 } };

	int b[][C] = {
		{ 1, 2, 3, 0, 5, 7 },
		{ 7, 5, 2, 0, 8, 3 },
		{ 0, 0, 0, 0, 0, 0 },
		{ 2, 9, 1, 0, 4, 3 },
		{ 8, 5, 6, 0, 5, 9 } };
	set_zeros(a);
	EXPECT_THAT(a, ::testing::ContainerEq(b));
}


INSTANTIATE_TEST_CASE_P(
	Implementations,
	ZeroMatrixTest5N6,
	::testing::Values(ctci::set_zeros<R, C>
	, ctci::set_zeros_2<R, C>));

#endif // GTEST_HAS_PARAM_TEST
} //namespace ctest