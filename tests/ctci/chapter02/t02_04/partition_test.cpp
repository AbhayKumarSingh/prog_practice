#include "ctci\chapter02\q02_04\partition.h"
#include "gtest\gtest.h"
#include "ctci\library\assorted_methods.h"
#include <initializer_list>

namespace ctest{
#if GTEST_HAS_PARAM_TEST

using libr::linked_list_node;
using libr::am::build_linked_list;
using libr::am::delete_linked_list;

namespace{
int count_lessthan(linked_list_node *head, int x){
	int count = 0;
	while (head){
		if (head->data < x){
			++count;
		}
		head = head->next;
	}
	return count;
}

void verify_partition(linked_list_node *head, int lessthan_count, int x){
	while (head){
		if (lessthan_count){
			EXPECT_LT(head->data, x);
			--lessthan_count;
		}
		else{
			EXPECT_GE(head->data, x);
		}
		head = head->next;
	}
}
} // namespace

typedef libr::linked_list_node *(*T)(libr::linked_list_node *, int);
class PartitionTest: public ::testing::TestWithParam<T> {
protected:
	virtual void SetUp() { partition = GetParam(); }
	T partition;
	void check_partition(const std::initializer_list<int> &list, int x);
};

void PartitionTest::check_partition(const std::initializer_list<int> &list, int x){
	auto head = build_linked_list(list);
	int count = count_lessthan(head, x);
	auto ans = partition(head, x);
	verify_partition(ans, count, x);
	delete_linked_list(ans);
}

TEST_P(PartitionTest, Empty){
	check_partition({}, 43);
}

TEST_P(PartitionTest, SingleElement){
	check_partition({ 4 }, -3);
	check_partition({ 4 }, 0);
	check_partition({ 4 }, 4);
	check_partition({ 4 }, 50);
}

TEST_P(PartitionTest, TwoElements){
	check_partition({ 4, 8 }, -1);
	check_partition({ 4, 8 }, 0);
	check_partition({ 4, 8 }, 4);
	check_partition({ 4, 8 }, 5);
	check_partition({ 4, 8 }, 8);
	check_partition({ 4, 8 }, 10);

	check_partition({ 3, 4 }, 0);
	check_partition({ 3, 4 }, 3);
	check_partition({ 3, 4 }, 4);
	check_partition({ 3, 4 }, 6);
}

TEST_P(PartitionTest, AlsoNegativeElements){
	check_partition({ 4, -50, 12, 2, 5, -6, 7, -1, 23, -1, -25 }, 50);
	check_partition({ 4, -50, 12, 2, 5, -6, 7, -1, 23, -1, -25 }, -27);
	check_partition({ 4, -50, 12, 2, 5, -6, 7, -1, 23, -1, -25 }, -1);
	check_partition({ 4, -50, 12, 2, 5, -6, 7, -1, 23, -1, -25 }, 2);
	check_partition({ 4, -50, 12, 2, 5, -6, 7, -1, 23, -1, -25 }, 3);
	check_partition({ 4, -50, 12, 2, 5, -6, 7, -1, 23, -1, -25 }, -50);
	check_partition({ 4, -50, 12, 2, 5, -6, 7, -1, 23, -1, -25 }, -60);
	check_partition({ 4, -50, 12, 2, 5, -6, 7, -1, 23, -1, -25 }, 100);
}

TEST_P(PartitionTest, AllInBegin){
	check_partition({ 15, 14, 13, 12, 13, 11 }, 43);
}

TEST_P(PartitionTest, AllInAfter){
	check_partition({ 15, 14, 13, 12, 13, 11 }, 3);
}

TEST_P(PartitionTest, TypicalCase){
	check_partition({ 5, 4, 3, 2, 3, 1 }, 3);
	check_partition({ 25, 14, 33, 12, 43, 71, 65, 45 }, 25);
	check_partition({ 25, 14, 33, 12, 43, 71, 65, 45 }, 2);
	check_partition({ 25, 14, 33, 12, 43, 71, 65, 45 }, 70);
	check_partition({ 25, 14, 33, 12, 43, 71, 65, 45 }, 43);
	check_partition({ 25, 14, 33, 12, 43, 71, 65, 45 }, 34);
}

INSTANTIATE_TEST_CASE_P(
	Implementations,
	PartitionTest,
	::testing::Values(ctci::partition,
                      ctci::partition_2,
                      ctci::partition_3));
#endif // GTEST_HAS_PARAM_TEST
} //namespace ctest