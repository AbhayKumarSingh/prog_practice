#ifndef LINKED_LIST_NODE_H
#define LINKED_LIST_NODE_H

#include <string>

namespace libr{

class linked_list_node{
public:
	linked_list_node *next;
	linked_list_node *prev;
	linked_list_node *last;
	int data;
	linked_list_node(int d, linked_list_node *n, linked_list_node *p);
	linked_list_node(int d);
	void set_next(linked_list_node *n);
	void set_previous(linked_list_node *p);
	std::string print_forward() const;
	linked_list_node *clone();
};

} // namespace libr

#endif // !LINKED_LIST_NODE_H