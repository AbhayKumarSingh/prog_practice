#include <limits.h>
#include "Source.h"
#include "gtest\gtest.h"
#include "gmock\gmock.h"
#include "Turtle.h"
#include "Painter.h"

TEST(FactorialTest, Negative) {
	// This test is named "Negative", and belongs to the "FactorialTest"
	// test case.
	EXPECT_EQ(1, Factorial(-5));
	EXPECT_EQ(1, Factorial(-1));
	EXPECT_GT(Factorial(-10), 0);

	// <TechnicalDetails>
	//
	// EXPECT_EQ(expected, actual) is the same as
	//
	//   EXPECT_TRUE((expected) == (actual))
	//
	// except that it will print both the expected value and the actual
	// value when the assertion fails.  This is very helpful for
	// debugging.  Therefore in this case EXPECT_EQ is preferred.
	//
	// On the other hand, EXPECT_TRUE accepts any Boolean expression,
	// and is thus more general.
	//
	// </TechnicalDetails>
}

// Tests factorial of 0.
TEST(FactorialTest, Zero) {
	EXPECT_EQ(1, Factorial(0));
}

// Tests factorial of positive numbers.
TEST(FactorialTest, Positive) {
	EXPECT_EQ(1, Factorial(1));
	EXPECT_EQ(2, Factorial(2));
	EXPECT_EQ(6, Factorial(3));
	EXPECT_EQ(40320, Factorial(8));
}

// Tests IsPrime()

// Tests negative input.
TEST(IsPrimeTest, Negative) {
	// This test belongs to the IsPrimeTest test case.
	EXPECT_FALSE(IsPrime(-1));
	EXPECT_FALSE(IsPrime(-2));
	EXPECT_FALSE(IsPrime(INT_MIN));
}

// Tests some trivial cases.
TEST(IsPrimeTest, Trivial) {
	EXPECT_FALSE(IsPrime(0));
	EXPECT_FALSE(IsPrime(1));
	EXPECT_TRUE(IsPrime(2));
	EXPECT_TRUE(IsPrime(3));
}

// Tests positive input.
TEST(IsPrimeTest, Positive) {
	EXPECT_FALSE(IsPrime(4));
	EXPECT_TRUE(IsPrime(5));
	EXPECT_FALSE(IsPrime(6));
	EXPECT_TRUE(IsPrime(23));
}

class MockTurtle : public Turtle {
public:
	MOCK_METHOD0(PenUp, void());
	MOCK_METHOD0(PenDown, void());
	MOCK_METHOD1(Forward, void(int distance));
	MOCK_METHOD1(Turn, void(int degrees));
	MOCK_METHOD2(GoTo, void(int x, int y));
	MOCK_CONST_METHOD0(GetX, int());
	MOCK_CONST_METHOD0(GetY, int());
};

using ::testing::AtLeast;                     // #1

TEST(PainterTest, CanDrawSomething) {
	MockTurtle turtle;                          // #2
	EXPECT_CALL(turtle, PenDown())              // #3
		.Times(AtLeast(1));

	Painter painter(&turtle);                   // #4

	EXPECT_TRUE(painter.DrawCircle(0, 0, 10));
}                                             // #5

TEST(PainterTest, sample) {
	EXPECT_TRUE(1 == 1);
}

int main(int argc, char** argv) {
	// The following line must be executed to initialize Google Mock
	// (and Google Test) before running the tests.
	::testing::InitGoogleMock(&argc, argv);
	return RUN_ALL_TESTS();
}

// Step 3. Call RUN_ALL_TESTS() in main().
//
// We do this by linking in src/gtest_main.cc file, which consists of
// a main() function which calls RUN_ALL_TESTS() for us.
//
// This runs all the tests you've defined, prints the result, and
// returns 0 if successful, or 1 otherwise.
//
// Did you notice that we didn't register the tests?  The
// RUN_ALL_TESTS() macro magically knows about all the tests we
// defined.  Isn't this convenient?


//int main(int ac, char* av[])
//{
//	testing::InitGoogleTest(&ac, av);
//	return RUN_ALL_TESTS();
//}