#include "palindrome.h"
#include "..\..\library\assorted_methods.h"
#include <stack>

namespace ctci{

using libr::linked_list_node;

namespace{
linked_list_node *reversed_list(linked_list_node *head){
	linked_list_node * reversed_head = nullptr;
	while (head){
		auto temp = new linked_list_node(head->data);
		temp->next = reversed_head;
		reversed_head = temp;
		head = head->next;
	}
	return reversed_head;
}

bool is_equal(linked_list_node *first, linked_list_node *second){
	while (first && second){
		if (first->data != second->data){
			return false;
		}
		first = first->next;
		second = second->next;
	}
	return first == nullptr && second == nullptr;
}
} // namespace

bool is_palindrome(linked_list_node *head){
	linked_list_node *reversed = reversed_list(head);
	auto is_palindrome = is_equal(head, reversed);
	libr::am::delete_linked_list(reversed);
	return is_palindrome;
}

bool is_palindrome_2(linked_list_node *head){
	auto *slow = head;
	auto *fast = head;
	std::stack<int> st;

	while (fast && fast->next){
		st.push(slow->data);
		slow = slow->next;
		fast = fast->next->next;
	}

	if (fast){
		slow = slow->next;
	}

	while (slow){
		if (slow->data != st.top()){
			return false;
		}
		slow = slow->next;
		st.pop();
	}
	return true;
}

namespace{

bool is_palindrome_3(linked_list_node *head, int length, linked_list_node **end_p){
	if (0 == length){
		*end_p = head;
		return true;
	}
	if (1 == length){
		*end_p = head->next;
		return true;
	}
	linked_list_node *end = nullptr;
	auto ans = is_palindrome_3(head->next, length - 2, &end);
	*end_p = end->next;
	return head->data == end->data && ans;
}

} // namespace

bool is_palindrome_3(linked_list_node *head){
	int length = libr::am::length(head);
	linked_list_node *nullpointer = nullptr;
	return is_palindrome_3(head, length, &nullpointer);
}

// the following implementation is not given in the book
bool is_palindrome_4(linked_list_node *head){
	auto *slow = head;
	auto *fast = head;
	std::stack<int> st;

	int seen = 0;
	while (fast){
		if (0 == seen % 2){
			st.push(slow->data);
			slow = slow->next;
		}

		fast = fast->next;
		++seen;
	}

	if (0 != seen % 2){ // stack cannot be empty when odd elements are seen
		st.pop();
	}

	while (slow){
		if (slow->data != st.top()){
			return false;
		}
		slow = slow->next;
		st.pop();
	}
	return true;
}

} // namespace ctci