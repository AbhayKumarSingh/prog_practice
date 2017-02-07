#include "linked_list_gtest_utilities.h"

namespace tlib{
::testing::AssertionResult AssertEqual(const char *first_expr,
                                       const char *second_expr,
                                       const libr::linked_list_node *first_p,
                                       const libr::linked_list_node *second_p){
	auto first = first_p;
	auto second = second_p;
	while (first != nullptr && second != nullptr)
	{
		if (first->data != second->data){
			return ::testing::AssertionFailure()
				<< "expected: " << first_expr << std::endl << "which is: "
				<< first_p->print_forward() << std::endl << "to be equal to: "
				<< second_expr << std::endl << "which is: " << second_p->print_forward();
		}

		first = first->next;
		second = second->next;
	}

	if (first == nullptr && second == nullptr){
		return ::testing::AssertionSuccess();
	}
	else{
		return ::testing::AssertionFailure() << "the lists don't have equal lengths";
	}
}
} // namespace tlib