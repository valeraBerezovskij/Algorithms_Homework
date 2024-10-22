#include "ForwardList.h"

ForwardList::~ForwardList() {
	Node* cur = head;
	while (cur != nullptr) {
		Node* next_node = cur->next;
		delete cur;
		cur = next_node;
	}
	head = nullptr;
	tale = nullptr;
}

void ForwardList::push_back(int value) {
	Node* new_node = new Node(value);
	if (!head) {
		head = new_node;
	}
	else {
		tale->next = new_node;
	}
	tale = new_node;
}

void ForwardList::push_front(int value) {
	Node* new_node = new Node(value);
	if (!head) {
		head = new_node;
	}
	else {
		new_node->next = head;
	}
	head = new_node;
}

void ForwardList::insert(int value, size_t index) {
	Node* new_node = new Node(value);
	Node* cur = head;
	for (int i = 0; i < index; ++i) {
		cur = cur->next;
	}
	Node* temp_next = cur->next;
	cur->next = new_node;
	new_node->next = temp_next;
}

void ForwardList::print()
{
	Node* cur = head;
	while (cur != nullptr) {	
		std::cout << cur->value	 << ' ';
		cur = cur->next;
	}
}
