#include "remove_dups.h"
#include <unordered_set>

namespace ctci{
using libr::linked_list_node;

void delete_dups(linked_list_node *n){
	std::unordered_set<int> seen;
	linked_list_node *previous = nullptr;
	while (n != nullptr){
		if (seen.count(n->data)){
			previous->next = n->next;
			delete n;
			n = previous->next;
		}
		else{
			seen.insert(n->data);
			previous = n;
			n = n->next;
		}
	}
}

void delete_dups_2(linked_list_node *n){
	auto slow = n; // just renaming
	while (slow != nullptr){
		auto fast = slow;
		while (fast->next != nullptr){
			if (slow->data == fast->next->data){
				auto to_be_deleted = fast->next;
				fast->next = to_be_deleted->next;
				delete to_be_deleted;
			}
			else{
				fast = fast->next;
			}
		}
		slow = slow->next;
	}
}
} // namespace ctci