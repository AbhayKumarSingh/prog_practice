#include "return_kth_to_last.h"

namespace ctci{
using libr::linked_list_node;

namespace{
linked_list_node *nth_to_last_node(linked_list_node *head, size_t k, size_t &back_index){
	if (head == nullptr){
		return nullptr;
	}
	
	auto prev_ans = nth_to_last_node(head->next, k, back_index);
	++back_index;
	if (back_index == k){
		return head;
	}
	return prev_ans;
}
} // namespace

linked_list_node *nth_to_last_node(linked_list_node *head, size_t k){
	size_t seed = 0;
	return nth_to_last_node(head, k, seed);
}

linked_list_node *nth_to_last_node_2(linked_list_node *head, size_t k){
	// create the separation
	linked_list_node *lead = head;
	linked_list_node *follow = head;
	for (size_t i = 0; i < k; ++i){
		if (lead == nullptr){
			return nullptr;
		}
		lead = lead->next;
	}
	// move simultaneously
	while (lead != nullptr){
		lead = lead->next;
		follow = follow->next;
	}
	return follow;
}

} // namespace ctci