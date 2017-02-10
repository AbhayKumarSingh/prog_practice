#include "ctci\chapter02\q02_03\delete_middle_node.h"
#include "common\linked_list_gtest_utilities.h"
#include "ctci\library\assorted_methods.h"
#include <initializer_list>

namespace ctest{
using libr::linked_list_node;
using libr::am::build_linked_list;
using libr::am::delete_linked_list;

namespace{

// just a utility func. Enter sensible values to the parameters.
// Note: no error checking done
void check_delete_middle_node(const std::initializer_list<int> &before,
								size_t pos,
                                const std::initializer_list<int> &after){
	auto head = build_linked_list(before);
	auto head_ans = build_linked_list(after);
	linked_list_node *deletable_node = head;
	for (size_t i = 0; i < pos; ++i){
		deletable_node = deletable_node->next;
	}
	EXPECT_TRUE(ctci::delete_node(deletable_node));
	EXPECT_LIST_EQ(head, head_ans);
	delete head;
	delete head_ans;
}

} // namespace

TEST(DeleteMiddleNodeTest, NoNodePassed){
	EXPECT_FALSE(ctci::delete_node(nullptr));
}

TEST(DeleteMiddleNodeTest, SingleNode){
	auto head = build_linked_list({ 1 });
	auto deletable_node = head;
	EXPECT_EQ(deletable_node->data, 1);
	EXPECT_FALSE(ctci::delete_node(deletable_node));
	delete head;
}

TEST(DeleteMiddleNodeTest, TypicalCases){
	check_delete_middle_node({ 1, 2, 3, 4, 5 }, 0, { 2, 3, 4, 5 });
	check_delete_middle_node({ 1, 2, 3, 4, 5 }, 1, { 1, 3, 4, 5 });
	check_delete_middle_node({ 1, 2, 3, 4, 5 }, 2, { 1, 2, 4, 5 });
	check_delete_middle_node({ 1, 2, 3, 4, 5 }, 3, { 1, 2, 3, 5 });
}

TEST(DeleteMiddleNodeTest, LastNode){
	auto head = build_linked_list({ 1, 2, 3, 4, 5 });
	auto deletable_node = head->next->next->next->next;
	EXPECT_EQ(deletable_node->data, 5);
	EXPECT_FALSE(ctci::delete_node(deletable_node));
	delete head;
}

} // namespace ctest