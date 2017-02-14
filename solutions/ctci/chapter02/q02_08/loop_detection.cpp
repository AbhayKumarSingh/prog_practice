#include "loop_detection.h"

namespace ctci{

using libr::linked_list_node;

linked_list_node *find_beginning(linked_list_node *head){
	linked_list_node *slow = head;
	linked_list_node *fast = head;

	while (fast && fast->next){
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast){
			break;
		}
	}

	if (!fast || !fast->next){
		return nullptr;
	}

	fast = head;
	while (slow != fast){
		slow = slow->next;
		fast = fast->next;
	}
	return fast;
}

} // namespace ctci