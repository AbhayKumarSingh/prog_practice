#ifndef ASSORTED_METHODS_H
#define ASSORTED_METHODS_H

#include "linked_list_node.h"

namespace libr{

namespace am{

template<class It>
linked_list_node *build_linked_list(It first, It last){
	linked_list_node *head = nullptr;
	linked_list_node *current = nullptr;
	for (auto it = first; it != last; ++it){
		auto new_one = new linked_list_node(*it);
		if (current == nullptr){ // condition can be improved
			head = new_one;
		}
		else{
			current->set_next(new_one);
		}
		current = new_one;
	}
	return head;
}

linked_list_node *build_linked_list(const std::initializer_list<int> &list);
void delete_linked_list(linked_list_node *head);
} // namespace am

} // namespace libr

#endif // !ASSORTED_METHODS_H