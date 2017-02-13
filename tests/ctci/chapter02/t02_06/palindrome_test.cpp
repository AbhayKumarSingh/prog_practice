#include "ctci\chapter02\q02_06\palindrome.h"
#include "gtest\gtest.h"
#include "ctci\library\assorted_methods.h"
#include <initializer_list>

namespace ctest{
#if GTEST_HAS_PARAM_TEST

using libr::linked_list_node;
using libr::am::build_linked_list;
using libr::am::delete_linked_list;

typedef bool (*T)(libr::linked_list_node *);
class PalindromeTest: public ::testing::TestWithParam<T> {
protected:
	virtual void SetUp() { is_palindrome = GetParam(); }
	T is_palindrome;
	void check_is_palindrome(const std::initializer_list<int> &list, bool t_value){
		auto head = build_linked_list(list);
		EXPECT_EQ(is_palindrome(head), t_value);
		delete_linked_list(head);
	}
};

TEST_P(PalindromeTest, Empty){
	check_is_palindrome({}, true);
}

TEST_P(PalindromeTest, TypicalCases){
	check_is_palindrome({ 4 }, true);
	check_is_palindrome({ 4, 4 }, true);
	check_is_palindrome({ 7, 4, 7 }, true);
	check_is_palindrome({ 7, 4, 4, 7 }, true);
	check_is_palindrome({ 7, 4, 3, 4, 7 }, true);
	check_is_palindrome({ 4, 7, 4, 4, 7, 4 }, true);
	check_is_palindrome({ 7, 3, 4, 3, 4, 3, 7 }, true);

	check_is_palindrome({ 4, 7 }, false);
	check_is_palindrome({ 7, 4, 3, 5, 4, 7 }, false);
	check_is_palindrome({ 7, 4, 3, 4, 5, 7 }, false);
	check_is_palindrome({ 11, 19, 12, 8, 13, 17 }, false);
}

INSTANTIATE_TEST_CASE_P(
	Implementations,
	PalindromeTest,
	::testing::Values(ctci::is_palindrome,
                      ctci::is_palindrome_2,
                      ctci::is_palindrome_3,
                      ctci::is_palindrome_4));
#endif // GTEST_HAS_PARAM_TEST
} //namespace ctest