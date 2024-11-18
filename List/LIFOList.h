#pragma once
#include<iostream>

template <class T>
class Node {
public:
	T value;
	Node* next;

	Node() : value(T()), next(nullptr) {}
	Node(T val) : value(val), next(nullptr) {}
	Node(const Node& other) : value(other.value), next(nullptr) {
		if (other.next != nullptr) {
			next = new Node(*other.next);
		}
	}
};

template<class T>
class LIFOList {
public:
	LIFOList() : head(nullptr), tail(nullptr) {}
	LIFOList(const LIFOList& other) 
		: head(nullptr), tail(nullptr), size(0) 
	{
		if (other.head) {
			head = new Node<T>(*other.head);
			Node<T>* current = head;
			Node<T>* ñurrent2 = other.head->next;
			while (ñurrent2) {
				current->next = new Node<T>(*ñurrent2);
				current = current->next;
				ñurrent2 = ñurrent2->next;
			}
			tail = current;
			size = other.size;
		}
	}
	~LIFOList() {
		Node<T>* cur = head;
		while (cur != nullptr) {
			Node<T>* next_node = cur->next;
			delete cur;
			cur = next_node;
		}
		head = nullptr;
		tail = nullptr;
		size = 0;
	}

	void push(T value) {
		Node<T>* new_node = new Node<T>(value);
		if (!head) {
			head = new_node;
			tail = new_node;
		}
		else {
			tail->next = new_node;
			tail = new_node;
		}
		++size;
	}

	void pop() {
		if (!head) { return; }

		if (tail == head) {
			delete head;
			head = nullptr;
			tail = nullptr;
		}
		else {
			Node<T>* current = head;
			while (current->next != tail) {
				current = current->next;
			}
			delete tail;
			tail = current;
			tail->next = nullptr;
		}
		size--;
	}
	void print() {
		Node<T>* cur = head;
		while (cur != nullptr) {
			std::cout << cur->value << ' ';
			cur = cur->next;
		}
	}
	LIFOList& operator=(const LIFOList& other) {
		if (this != &other) {
			this->size = other.size;
			head = new Node(*other.head);
		}
		return *this;
	}

private:
	Node<T>* head;
	Node<T>* tail;
	size_t size;
};