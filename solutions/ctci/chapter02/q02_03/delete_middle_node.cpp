#include "delete_middle_node.h"

namespace ctci{
using libr::linked_list_node;
bool delete_node(libr::linked_list_node *n){
	if (!n || !n->next){
		return false;
	}

	auto to_be_deleted = n->next;
	*n = *to_be_deleted;
	delete to_be_deleted;
	return true;
}
} // namespace ctci