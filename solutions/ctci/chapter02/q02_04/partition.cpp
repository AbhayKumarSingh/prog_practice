#include "partition.h"
#include "..\..\library\assorted_methods.h"

namespace ctci{
using libr::linked_list_node;

linked_list_node *partition(linked_list_node *node, int x){
	linked_list_node *before_start = nullptr;
	linked_list_node *before_end= nullptr;
	linked_list_node *after_start = nullptr;
	linked_list_node *after_end = nullptr;
	while (node){
		auto next = node->next;
		node->next = nullptr;
		if (node->data < x){
			if (!before_start){
				before_start = node;
				before_end = before_start;
			}
			else{
				before_end->next = node;
				before_end = node;
			}
		}
		else{
			if (!after_start){
				after_start = node;
				after_end = after_start;
			}
			else{
				after_end->next = node;
				after_end = node;
			}
		}
		node = next;
	}

	if (!before_start){
		return after_start;
	}

	before_end->next = after_start;
	return before_start;
}

linked_list_node *partition_2(linked_list_node *node, int x){
	linked_list_node *before = node;
	linked_list_node *after = node;
	while (node){
		auto next = node->next;
		if (node->data < x){
			node->next = before;
			before = node;
		}
		else{
			after->next = node;
			after = node;
		}
		node = next;
	}
	if (after){
		after->next = nullptr;
	}

	return before;
}

// the following implementation is not given in book
linked_list_node *partition_3(linked_list_node *node, int x){
	linked_list_node *before = node;
	linked_list_node *after= node;
	while (after && after->next){
		node = after->next;
		if (node->data < x){
			after->next = node->next;
			node->next = before;
			before = node;
		}
		else{
			after->next = node;
			after = node;
		}
	}

	return before;
}

} // namespace ctci