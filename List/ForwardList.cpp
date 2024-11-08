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

ForwardList& ForwardList::operator=(const ForwardList& other)
{
	if (this != &other) {
		head = new Node(*other.head);
	}
	return *this;
}

ForwardList::ForwardList(const ForwardList& other) {
	head = new Node(*other.head); //Тут у нас вызвался копирующий конструктор для Node
}

Node::Node(const Node& other) : value(other.value), next(nullptr) {
	if (other.next != nullptr) {
		next = new Node(*other.next); // А тут они все скопировались
	}
}