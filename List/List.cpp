#include "List.h"
#include <iostream>
using namespace std;

List::List()
	:head(nullptr), tail(nullptr), size(0)
{}

List::List(const List& other) : head(nullptr), tail(nullptr), size(0) {
	Node* cur = other.head;
	while (cur) {
		push_back(cur->value);
		cur = cur->next;
	}
}

List& List::operator=(const List& other) {
	if (this != &other) {
		if(this != nullptr){ clear(); }

		Node* current = other.head;
		for (size_t i = 0; i < other.size; ++i) {
			push_back(current->value);
			current = current->next;
		}
	}
	return *this;
}

void List::reverse() {
	Node* ptr1 = head;
	Node* ptr2 = ptr1->next;

	ptr1->next = nullptr;
	ptr1->prev = ptr2;

	while (ptr2 != nullptr) {
		ptr2->prev = ptr2->next;
		ptr2->next = ptr1;
		ptr1 = ptr2;
		ptr2 = ptr2->prev;
	}
	std::swap(head, tail);
}

void List::pop_back()
{
	if (tail == nullptr) {
		return;
	}
	if (tail == head) {
		head = nullptr;
	}
	Node* temp = tail;
	tail = tail->prev;
	if (tail != nullptr) {
		tail->next = nullptr;
	}
	else {
		head = nullptr;	
	}
	delete temp;
	size--;
}

void List::pop_front()
{
	if (head == nullptr) {
		return;
	}

	if (tail == head) {
		head = nullptr;
	}
	Node* temp = head;
	head = head->next;
	if (head != nullptr) {
		head->prev = nullptr;
	}
	else {
		head = nullptr;
	}
	delete temp;
	size--;
}

//List* List::clone() {
//	Node* new_head = new Node(head->prev, head->value);
//	Node* current = head;
//	Node* new_current = new_head;
//
//	for (size_t i = 0; i < size; ++i)
//	{
//		new_current->next = current->next;
//			
//	}
//}

void List::push_back(int value) {
	if (head && tail) {
		Node* new_node = new Node(tail, value);
		tail->next = new_node;
		tail = new_node;
	}
	else {
		Node* new_node = new Node(value);
		head = new_node;
		tail = new_node;
	}
	size++;
}

void List::push_front(int value) {
	if (head && tail) {
		Node* new_node = new Node(value);
		new_node->next = head;
		head->prev = new_node;
		head = new_node;
	}
	else {
		Node* new_node = new Node(value);
		head = new_node;
		tail = new_node;
	}
	size++;
}

void List::clear() {
	while (head) {
		Node* temp = head;
		head = head->next;
		delete temp;
	}
	tail = nullptr;
	size = 0;
}

bool List::insert(int index, int value)
{
	if (index < 0 || index > size - 1) {
		return false;	
	}

	Node* current = head;
	Node* new_node = new Node(value);

	if (index == size) {
		new_node->prev = tail;
		tail->next = new_node;
		tail = new_node;
		return true;
	}

	for (int i = 0; i < index; i++) {
		current = current->next;
	}
	if (current->prev) {
		current->prev->next = new_node;
		new_node->prev = current->prev;
	}
	else {
		head = new_node;
	}
	new_node->next = current;
	current->prev = new_node;
	size++;
	return true;
}

int List::replace(int key, int value)
{
	Node* current = head;
	int counter = 0;
	while (current)	{
		if (current->value == key) {
			current->value = value;
			counter++;
		}
		current = current->next;
	}
	return counter;
}

void List::show() const
{
	Node* current = head;
	while (current)
	{
		cout << current->value << " ";
		current = current->next;
	}
	cout << endl;
}

int List::operator[](int index)
{
	Node* current = head;
	for (int i = 0; i < index; i++) {
		current = current->next;
	}
	return current->value;
}

List::~List() {
	clear();
}
