#include "assorted_methods.h"

namespace libr{
namespace am{

linked_list_node *build_linked_list(const std::initializer_list<int> &list){
	return build_linked_list(list.begin(), list.end());
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