#include "ctci\chapter02\q02_02\return_kth_to_last.h"
#include "gtest\gtest.h"
#include <initializer_list>
#include "ctci\library\assorted_methods.h"

namespace ctest{
#if GTEST_HAS_PARAM_TEST

using libr::linked_list_node;
using libr::am::build_linked_list;
using libr::am::delete_linked_list;

typedef libr::linked_list_node *(*T)(libr::linked_list_node *, size_t);
class ReturnKthToLastTest: public ::testing::TestWithParam<T> {
protected:
	virtual void SetUp() { nth_to_last_node = GetParam(); }
	T nth_to_last_node;
	void check_nth_to_last_node(const std::initializer_list<int> &list, size_t pos, int data);
};

// don't call the following function when the tested function is expected to return nullptr
void ReturnKthToLastTest::check_nth_to_last_node(const std::initializer_list<int> &list, size_t pos, int data){
	auto head = build_linked_list(list);
	auto ans_node = nth_to_last_node(head, pos);
	EXPECT_EQ(ans_node->data, data);
	delete_linked_list(head);
}

TEST_P(ReturnKthToLastTest, Empty){
	auto head = build_linked_list({});
	auto ans_node = nth_to_last_node(head, 3);
	EXPECT_EQ(ans_node, nullptr);
	delete_linked_list(head);
}

TEST_P(ReturnKthToLastTest, OutOfRange){
	auto head = build_linked_list({ 1, 2, 3, 4 });
	auto ans_node = nth_to_last_node(head, 80);
	EXPECT_EQ(ans_node, nullptr);
	delete_linked_list(head);
}

TEST_P(ReturnKthToLastTest, ZeroIndex){
	auto head = build_linked_list({ 1, 2, 3, 4 });
	auto ans_node = nth_to_last_node(head, 0);
	EXPECT_EQ(ans_node, nullptr);
	delete_linked_list(head);
}

TEST_P(ReturnKthToLastTest, EmptyZeroIndex){
	auto head = build_linked_list({});
	auto ans_node = nth_to_last_node(head, 0);
	EXPECT_EQ(ans_node, nullptr);
	delete_linked_list(head);
}

TEST_P(ReturnKthToLastTest, TypicalCase){
	check_nth_to_last_node({ 1, 2, 3, 4, 5, 6, 7 }, 1, 7);
	check_nth_to_last_node({ 1, 2, 3, 4, 5, 6, 7 }, 2, 6);
	check_nth_to_last_node({ 1, 2, 3, 4, 5, 6, 7 }, 3, 5);
	check_nth_to_last_node({ 1, 2, 3, 4, 5, 6, 7 }, 5, 3);
	check_nth_to_last_node({ 1, 2, 3, 4, 5, 6, 7 }, 7, 1);
	check_nth_to_last_node({ 5 }, 1, 5);
	check_nth_to_last_node({ 5, 9 }, 1, 9);
	check_nth_to_last_node({ 5, 9 }, 2, 5);
}

INSTANTIATE_TEST_CASE_P(
	Implementations,
	ReturnKthToLastTest,
	::testing::Values(ctci::nth_to_last_node
	, ctci::nth_to_last_node_2));
#endif // GTEST_HAS_PARAM_TEST
} //namespace ctest