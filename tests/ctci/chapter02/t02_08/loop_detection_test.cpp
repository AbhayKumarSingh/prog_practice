#include "ctci\chapter02\q02_08\loop_detection.h"
#include "gtest\gtest.h"
#include "ctci\library\assorted_methods.h"

namespace ctest{
using libr::am::build_linked_list;
using libr::am::delete_linked_list;

TEST(LoopDetectionTest, Empty){
	EXPECT_EQ(ctci::find_beginning(nullptr), nullptr);
}

TEST(LoopDetectionTest, SingleNodeWithoutCycle){
	auto head = build_linked_list({ 2 });
	EXPECT_EQ(ctci::find_beginning(head), nullptr);
	delete_linked_list(head);
}

TEST(LoopDetectionTest, SingleNodeWithCycle){
	auto head = build_linked_list({ 2 });
	head->next = head;
	EXPECT_EQ(ctci::find_beginning(head), head);
	head->next = nullptr;
	delete_linked_list(head);
}

TEST(LoopDetectionTest, WithoutCycle){
	auto head = build_linked_list({ 1, 2, 3, 4, 5, 6, 7 });
	EXPECT_EQ(ctci::find_beginning(head), nullptr);
	delete_linked_list(head);
}

TEST(LoopDetectionTest, TwoNodesWithoutCycle){
	auto head = build_linked_list({ 1, 2 });
	EXPECT_EQ(ctci::find_beginning(head), nullptr);
	delete_linked_list(head);
}

TEST(LoopDetectionTest, TwoNodeCompleteCycle){
	auto head = build_linked_list({ 1, 2 });
	auto last = head->next;
	auto loop_start = head;
	last->next = loop_start;
	EXPECT_EQ(ctci::find_beginning(head), loop_start);
	last->next = nullptr;
	delete_linked_list(head);
}

TEST(LoopDetectionTest, TwoNodeEndCycle){
	auto head = build_linked_list({ 1, 2 });
	auto last = head->next;
	auto loop_start = head->next;
	last->next = loop_start;
	EXPECT_EQ(ctci::find_beginning(head), loop_start);
	last->next = nullptr;
	delete_linked_list(head);
}

TEST(LoopDetectionTest, LongChainEndCycle){
	auto head = build_linked_list({ 1, 2, 3, 4, 5, 6, 7, 8 });
	auto last = head->next->next->next->next->next->next->next;
	auto loop_start = head->next->next->next->next->next->next->next;
	last->next = loop_start;
	EXPECT_EQ(ctci::find_beginning(head), loop_start);
	last->next = nullptr;
	delete_linked_list(head);
}

TEST(LoopDetectionTest, LongChainSmallCycle){
	auto head = build_linked_list({ 11, 12 ,13, 14, 15, 1, 2, 3, 4, 5, 6, 7, 8 });
	auto last = head->next->next->next->next->next->
                      next->next->next->next->next->next->next;
	auto loop_start = head->next->next->next->next->next->
                            next->next->next->next->next;
	last->next = loop_start;
	EXPECT_EQ(ctci::find_beginning(head), loop_start);
	last->next = nullptr;
	delete_linked_list(head);
}

TEST(LoopDetectionTest, BigLoop){
	auto head = build_linked_list({ 11, 12, 13, 14, 15, 1, 2, 3, 4, 5, 6, 7, 8 });
	auto last = head->next->next->next->next->next->
                      next->next->next->next->next->next->next;
	auto loop_start = head;
	last->next = loop_start;
	EXPECT_EQ(ctci::find_beginning(head), loop_start);
	last->next = nullptr;
	delete_linked_list(head);
}

TEST(LoopDetectionTest, BigLoopFromSecondNode){
	auto head = build_linked_list({ 11, 12, 13, 14, 15, 1, 2, 3, 4, 5, 6, 7, 8 });
	auto last = head->next->next->next->next->next->
                      next->next->next->next->next->next->next;
	auto loop_start = head->next;
	last->next = loop_start;
	EXPECT_EQ(ctci::find_beginning(head), loop_start);
	last->next = nullptr;
	delete_linked_list(head);
}

} // namespace ctest