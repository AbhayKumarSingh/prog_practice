#include "assorted_methods.h"

namespace libr{
namespace am{

linked_list_node *build_linked_list(const std::initializer_list<int> &list){
	linked_list_node *head = nullptr;
	linked_list_node *current = nullptr;
	for (auto elem : list){
		auto new_one = new linked_list_node(elem);
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

void delete_linked_list(linked_list_node *head){
	auto previous = head;
	while (head != nullptr){
		head = head->next;
		delete previous;
		previous = head;
	}
}

} // namespace am
} // namespace libr