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

List* List::clone() {
	Node* new_head = new Node(head->prev, head->value);
	Node* current = head;
	Node* new_current = new_head;

	for (size_t i = 0; i < size; ++i)
	{
		new_current->next = current->next;
		
	}
}


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
