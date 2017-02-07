#include "ctci\chapter02\q02_01\remove_dups.h"
#include "common\gtest_custom.h"
#include "common\linked_list_gtest_utilities.h"
#include <initializer_list>
#include "ctci\library\assorted_methods.h"

namespace ctest{
#if GTEST_HAS_PARAM_TEST

using libr::linked_list_node;
using libr::am::build_linked_list;
using libr::am::delete_linked_list;

typedef void (*T)(libr::linked_list_node *);
class RemoveDupsTest : public ::testing::TestWithParam<T> {
protected:
	virtual void SetUp() { delete_dups = GetParam(); }
	T delete_dups;
	void check_remove_dups(const std::initializer_list<int> &init,
                           const std::initializer_list<int> &after) const;

};

void RemoveDupsTest::check_remove_dups(const std::initializer_list<int> &init,
                                       const std::initializer_list<int> &after)const{
	auto head = build_linked_list(init);
	auto ans = build_linked_list(after);
	delete_dups(head);
	EXPECT_LIST_EQ(head, ans);
	delete_linked_list(head);
	delete_linked_list(ans);
}

TEST_P(RemoveDupsTest, Empty){
	check_remove_dups({}, {});
}

TEST_P(RemoveDupsTest, NoDuplicates){
	check_remove_dups({ 3 }, { 3 });
	check_remove_dups({ 3, 5 }, { 3, 5 });
	check_remove_dups({ 1, 2, 3, 4, 5 }, { 1, 2, 3, 4, 5 });
	check_remove_dups({ 1, 2, 3, 4, 5, 7, 8 }, { 1, 2, 3, 4, 5, 7, 8});
}

TEST_P(RemoveDupsTest, ManyDuplicates){
	check_remove_dups({ 4, 5, 1, 2, 5, 8, 2, 3, 2, 7 }, { 4, 5, 1, 2, 8, 3, 7 });
	check_remove_dups({ 4, 5, 1, 2, 5, 4, 2, 3, 2, 7 }, { 4, 5, 1, 2, 3, 7 });
}

TEST_P(RemoveDupsTest, AllDuplicates){
	check_remove_dups({ 3, 3, 3, 3, 3, 3, 3, 3 }, { 3 });
}

TEST_P(RemoveDupsTest, ConsecutiveDuplicates){
	check_remove_dups({ 4, 5, 1, 2, 5, 4, 2, 3, 2, 7 }, { 4, 5, 1, 2, 3, 7 });
}

TEST_P(RemoveDupsTest, DuplicatesAtLast){
	check_remove_dups({ 1, 2, 3, 4, 5, 2 }, { 1, 2, 3, 4, 5 });
	check_remove_dups({ 1, 2, 3, 4, 5, 2, 2, 2 }, { 1, 2, 3, 4, 5 });
}

TEST_P(RemoveDupsTest, TypicalCase){
	check_remove_dups({ 4, 1, 2, 5, 8, 2, 3, 2, 7 }, { 4, 1, 2, 5, 8, 3, 7 });
	check_remove_dups({ 4, 1, 2, 5, 8, 2, 3 }, { 4, 1, 2, 5, 8, 3 });
}

INSTANTIATE_TEST_CASE_P(
	Implementations,
	RemoveDupsTest,
	::testing::Values(ctci::delete_dups
	, ctci::delete_dups_2));
#endif // GTEST_HAS_PARAM_TEST
} //namespace ctest