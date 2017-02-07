#ifndef LINKED_LIST_GTEST_UTILITIES_H
#define LINKED_LIST_GTEST_UTILITIES_H

#include "gtest\gtest.h"
#include "ctci\library\linked_list_node.h"

namespace tlib{
::testing::AssertionResult AssertEqual(const char *first_expr,
                                       const char *second_expr,
                                       const libr::linked_list_node *first_p,
                                       const libr::linked_list_node *second_p);

#define EXPECT_LIST_EQ(first, second) EXPECT_PRED_FORMAT2(::tlib::AssertEqual, first, second)
} // namespace tlib

#endif // !LINKED_LIST_GTEST_UTILITIES_H