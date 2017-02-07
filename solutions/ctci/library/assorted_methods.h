#ifndef ASSORTED_METHODS_H
#define ASSORTED_METHODS_H

#include "linked_list_node.h"

namespace libr{

namespace am{
linked_list_node *build_linked_list(const std::initializer_list<int> &list);
void delete_linked_list(linked_list_node *head);
} // namespace am

} // namespace libr

#endif // !ASSORTED_METHODS_H