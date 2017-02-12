#include "sum_lists.h"

namespace ctci{
using libr::linked_list_node;

namespace{
linked_list_node *add_lists(linked_list_node *l1, linked_list_node *l2, int carry){
	if (!l1 && !l2 && !carry){
		return nullptr;
	}
	int sum = carry;
	linked_list_node *first_next = nullptr;
	linked_list_node *second_next = nullptr;
	if (l1){
		sum += l1->data;
		first_next = l1->next;
	}

	if (l2){
		sum += l2->data;
		second_next = l2->next;
	}
	auto head = new linked_list_node(sum % 10);
	head->next = add_lists(first_next, second_next, sum / 10);
	return head;
}
} // namespace

linked_list_node *add_lists(linked_list_node *l1, linked_list_node *l2){
	return add_lists(l1, l2, 0);
}

namespace{

struct partial_sum{
	linked_list_node *head;
	int carry;
};

int length(linked_list_node *head){
	int length = 0;
	while (head){
		++length;
		head = head->next;
	}
	return length;
}

linked_list_node *insert_before(linked_list_node *head, int value){
	auto temp = new linked_list_node(value);
	temp->next = head;
	return temp;
}

void pad_zeroes(linked_list_node *&head, int num_zeroes){
	for (int i = 0; i < num_zeroes; ++i){
		head = insert_before(head, 0);
	}
}

void delete_initial_zeroes(linked_list_node *&head, linked_list_node *up_to){
	while (head && head != up_to){
		auto temp = head;
		head = head->next;
		delete temp;
	}
}

partial_sum add_lists_internal(linked_list_node *l1, linked_list_node *l2){
	if (!l1 && !l2)
		return partial_sum{ nullptr, 0 };
	auto p_sum = add_lists_internal(l1->next, l2->next);
	int value = l1->data + l2->data + p_sum.carry;
	auto full_result = insert_before(p_sum.head, value % 10);
	partial_sum ans = { full_result, value / 10 };
	return ans;
}
} // namespace

linked_list_node *add_lists_2(linked_list_node *l1, linked_list_node *l2){
	auto l1_init = l1;
	auto l2_init = l2;

	int l1_length = length(l1);
	int l2_length = length(l2);
	if (l1_length > l2_length){
		pad_zeroes(l2, l1_length - l2_length);
	}
	else{
		pad_zeroes(l1, l2_length - l1_length);
	}

	auto result = add_lists_internal(l1, l2);
	delete_initial_zeroes(l1, l1_init);
	delete_initial_zeroes(l2, l2_init);
	
	return !result.carry ? result.head : insert_before(result.head, result.carry);
}

} // namespace ctci