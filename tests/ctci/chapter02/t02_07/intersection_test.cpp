#include "ctci\chapter02\q02_07\intersection.h"
#include "gtest\gtest.h"
#include "ctci\library\assorted_methods.h"

namespace ctest{
using libr::linked_list_node;
using libr::am::build_linked_list;
using libr::am::delete_linked_list;

TEST(IntersectionTest, BothNull){
	EXPECT_EQ(ctci::find_intersection(nullptr, nullptr), nullptr);
}

TEST(IntersectionTest, OneNull){
	auto head1 = build_linked_list({ 1, 2, 3, 4, 5, 6, 7, 8 });
	EXPECT_EQ(ctci::find_intersection(head1, nullptr), nullptr);
	EXPECT_EQ(ctci::find_intersection(nullptr, head1), nullptr);
	delete_linked_list(head1);
}

TEST(IntersectionTest, OneNode){
	auto head1 = build_linked_list({ 1 });
	EXPECT_EQ(ctci::find_intersection(head1, head1), head1);
	delete_linked_list(head1);
}

TEST(IntersectionTest, OneNodeCommonWithNoBranching){
	auto head1 = build_linked_list({ 1, 2, 3, 4 });
	auto joint = head1->next->next->next;
	EXPECT_EQ(ctci::find_intersection(head1, joint), joint);
	EXPECT_EQ(ctci::find_intersection(joint, head1), joint);
	delete_linked_list(head1);
}

TEST(IntersectionTest, OneNodeCommonWithOneNodeBranching){
	auto head1 = build_linked_list({ 1, 2, 3, 4 });
	auto head2 = build_linked_list({ 11 });
	auto last2 = head2;
	auto joint = head1->next->next->next;
	last2->next = joint;
	EXPECT_EQ(ctci::find_intersection(head1, head2), joint);
	EXPECT_EQ(ctci::find_intersection(head2, head1), joint);
	last2->next = nullptr;
	delete_linked_list(head1);
	delete_linked_list(head2);
}

TEST(IntersectionTest, NothingCommon){
	auto head1 = build_linked_list({ 1, 2, 3, 4 });
	auto head2 = build_linked_list({ 11, 12, 13, 14 });
	EXPECT_EQ(ctci::find_intersection(head1, head2), nullptr);
	EXPECT_EQ(ctci::find_intersection(head2, head1), nullptr);
	delete_linked_list(head1);
	delete_linked_list(head2);
}

TEST(IntersectionTest, EverythingCommon){
	auto head1 = build_linked_list({ 1, 2, 3, 4 });
	EXPECT_EQ(ctci::find_intersection(head1, head1), head1);
	delete_linked_list(head1);
}

TEST(IntersectionTest, EverythingExceptOneCommon){
	auto head1 = build_linked_list({ 1, 2, 3, 4 });
	EXPECT_EQ(ctci::find_intersection(head1, head1->next), head1->next);
	EXPECT_EQ(ctci::find_intersection(head1->next, head1), head1->next);
	delete_linked_list(head1);
}

TEST(IntersectionTest, TypicalCase){
	auto head1 = build_linked_list({ 1, 2, 3, 4, 5, 6, 7, 8 });
	auto head2 = build_linked_list({ 11, 12, 13 });
	auto last2 = head2->next->next;
	auto joint = head1->next->next->next->next;
	last2->next = joint;
	EXPECT_EQ(ctci::find_intersection(head1, head2), joint);
	EXPECT_EQ(ctci::find_intersection(head2, head1), joint);
	last2->next = nullptr;
	delete_linked_list(head1);
	delete_linked_list(head2);
}

} // namespace ctest