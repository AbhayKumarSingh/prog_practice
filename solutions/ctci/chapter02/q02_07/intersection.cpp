#include "intersection.h"
#include <cmath>

namespace ctci{
using libr::linked_list_node;

namespace{
int find_length_and_end(linked_list_node *head, linked_list_node **end){
	*end = nullptr;
	int len = 0;
	while (head){
		if (!head->next){
			*end = head;
		}
		++len;
		head = head->next;
	}
	return len;
}
} // namespace

linked_list_node *find_intersection(linked_list_node *list1, linked_list_node *list2){
	if (!list1 || !list2){ // this check is not really necessary but good to have here
		return nullptr;
	}
	linked_list_node *end1 = nullptr;
	auto len1 = find_length_and_end(list1, &end1);

	linked_list_node *end2 = nullptr;
	auto len2 = find_length_and_end(list2, &end2);

	// check if they are intersecting return false otherwise
	if (end1 != end2){
		return nullptr;
	}

	// decide the larger and the smaller list
	auto larger = len1 > len2 ? list1 : list2;
	auto smaller = len1 > len2 ? list2 : list1;

	// move the pointer in the correct list by difference
	auto diff = std::abs(len1 - len2);
	while (diff && larger){ // the second condition is just for safety
		larger = larger->next;
		--diff;
	}

	// move simultaneously to check if they are intersecting
	while (smaller != larger){
		larger = larger->next;
		smaller = smaller->next;
	}
	return larger; // by default
}

} // namespace ctci