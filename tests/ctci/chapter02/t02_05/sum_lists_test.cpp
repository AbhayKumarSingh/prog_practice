#include "ctci\chapter02\q02_05\sum_lists.h"
#include "gtest\gtest.h"
#include "ctci\library\assorted_methods.h"
#include <vector>
#include "common\linked_list_gtest_utilities.h"

namespace ctest{
#if GTEST_HAS_PARAM_TEST

using libr::linked_list_node;
using libr::am::build_linked_list;
using libr::am::delete_linked_list;

typedef linked_list_node *(*T)(linked_list_node *, linked_list_node *);
class SumListsTest: public ::testing::TestWithParam<T> {
protected:
	virtual void SetUp() { add_lists = GetParam(); }
	T add_lists;
	void check_add_lists(const std::vector<int> &, const std::vector<int> & , const std::vector<int> &);
};

void SumListsTest::check_add_lists(const std::vector<int> &first,
                                   const std::vector<int> &second,
                                   const std::vector<int> &ans){
	linked_list_node *first_head = nullptr, *second_head = nullptr, *ans_head = nullptr;
	if (add_lists == ctci::add_lists){
		first_head = build_linked_list(first.rbegin(), first.rend());
		second_head = build_linked_list(second.rbegin(), second.rend());
		ans_head = build_linked_list(ans.rbegin(), ans.rend());
	}
	else if (add_lists == ctci::add_lists_2){
		first_head = build_linked_list(first.begin(), first.end());
		second_head = build_linked_list(second.begin(), second.end());
		ans_head = build_linked_list(ans.begin(), ans.end());
	}
	else{
		ADD_FAILURE() << "control must not reach here" << std::endl;
	}
	EXPECT_LIST_EQ(add_lists(first_head, second_head), ans_head);
	delete_linked_list(first_head);
	delete_linked_list(second_head);
	delete_linked_list(ans_head);
}

TEST_P(SumListsTest, BothEmpty){
	check_add_lists({}, {}, {});
}

TEST_P(SumListsTest, OneEmpty){
	check_add_lists({}, { 1, 2, 3 }, { 1, 2, 3 });
	check_add_lists({ 1, 2, 3 }, {}, { 1, 2, 3 });
	check_add_lists({}, { 1 }, { 1 });
	check_add_lists({ 1 }, {}, { 1 });
	check_add_lists({ 1, 4 }, {}, { 1, 4 });
	check_add_lists({},{ 1, 4 }, { 1, 4 });
}

TEST_P(SumListsTest, AdditionWithZero){
	check_add_lists({ 0 }, { 1, 4, 3, 4 }, { 1, 4, 3, 4 });
	check_add_lists({ 1, 4, 3, 4 }, { 0 }, { 1, 4, 3, 4 });
	check_add_lists({ 0 }, { 0 }, { 0 });
}

TEST_P(SumListsTest, UnequalLength){
	check_add_lists({ 1, 4, 3, 4 }, { 3, 4, 5 }, { 1, 7, 7, 9 });
	check_add_lists({ 3, 4, 5 }, { 1, 4, 3, 4 }, { 1, 7, 7, 9 });
	check_add_lists({ 1, 4, 3, 4 }, { 4, 5 }, { 1, 4, 7, 9 });
}

TEST_P(SumListsTest, Carry){
	check_add_lists({ 1, 4, 3, 4 }, { 9, 9, 9 }, { 2, 4, 3, 3 });
	check_add_lists({ 9, 9, 9 }, { 1, 4, 3, 4 }, { 2, 4, 3, 3 });
	check_add_lists({ 1, 4, 3, 4 }, { 9, 9, 9, 9 }, { 1, 1, 4, 3, 3 });
	check_add_lists({ 9, 9, 9, 9 }, { 1, 4, 3, 4 }, { 1, 1, 4, 3, 3 });
	check_add_lists({ 8 }, { 7 }, { 1, 5 });
	check_add_lists({ 7 }, { 8 }, { 1, 5 });
}

TEST_P(SumListsTest, LeadingZeroes){
	check_add_lists({ 1, 2, 3 }, { 0, 4, 5, 6 }, { 0, 5, 7, 9 });
	check_add_lists({ 0, 9, 9, 9, 9 }, { 1, 4, 3, 4 }, { 1, 1, 4, 3, 3 });
}

TEST_P(SumListsTest, TypicalCases){
	check_add_lists({ 1, 2, 3 }, { 4, 5, 6 }, { 5, 7, 9 });
	check_add_lists({ 1, 1, 2, 3 }, { 4, 5, 6 }, { 1, 5, 7, 9 });
	check_add_lists({ 1, 2, 3 }, { 1, 4, 5, 6 }, { 1, 5, 7, 9 });
}

INSTANTIATE_TEST_CASE_P(
	Implementations,
	SumListsTest,
	::testing::Values(ctci::add_lists,
                      ctci::add_lists_2));
#endif // GTEST_HAS_PARAM_TEST
} //namespace ctest