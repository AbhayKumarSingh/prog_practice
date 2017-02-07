#include "linked_list_node.h"
#include <iostream>

namespace libr{

linked_list_node::linked_list_node(int d, linked_list_node *n, linked_list_node *p)
	: data(d), next(n), prev(p){
}

linked_list_node::linked_list_node(int d)
	: data(d), next(nullptr), prev(nullptr){
}

void linked_list_node::set_next(linked_list_node *n){
	next = n;
	if (this == last){
		last = n;
	}
	if (n != nullptr && n->prev != this) {
		n->set_previous(this);
	}
}

void linked_list_node::set_previous(linked_list_node *p){
	prev = p;
	if (p != nullptr && p->next != this) {
		p->set_next(this);
	}
}

std::string linked_list_node::print_forward() const{
	if (next != nullptr) {
		return std::to_string(data) + "->" + next->print_forward();
	}
	else {
		return std::to_string(data);
	}
}

linked_list_node *linked_list_node::clone(){
	linked_list_node *next2 = nullptr;
	if (next != nullptr) {
		next2 = next->clone();
	}
	linked_list_node *head2 = new linked_list_node(data, next2, nullptr);
	return head2;
}

} // namespace libr
