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
	LIFOList(const LIFOList& other);
	~LIFOList();
	void push(T value);
	void pop();
	void print();
	LIFOList& operator=(const LIFOList& other);

private:
	Node<T>* head;
	Node<T>* tail;
	size_t size;
};

template<class T>
inline LIFOList<T>::LIFOList(const LIFOList& other)
	: head(nullptr), tail(nullptr), size(0)
{
	if (other.head) {
		head = new Node<T>(*other.head);
		Node<T>* current = head;
		Node<T>* current2 = other.head->next;
		while (current2) {
			current->next = new Node<T>(*сurrent2);
			current = current->next;
			current2 = current2->next;
		}
		tail = current;
		size = other.size;
	}
}

template<class T>
inline LIFOList<T>::~LIFOList() {
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

template<class T>
inline void LIFOList<T>::push(T value) {
	Node<T>* new_node = new Node<T>(value);
	if (!head) {
		head = new_node;
		tail = new_node;
	}
	else {
		//добавляем в начало
		new_node->next = head;
		head = new_node;
	}
	++size;
}

template<class T>
inline void LIFOList<T>::pop() {
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

template<class T>
inline void LIFOList<T>::print() {
	Node<T>* cur = head;
	while (cur != nullptr) {
		std::cout << cur->value << ' ';
		cur = cur->next;
	}
}

template<class T>
inline LIFOList<T>& LIFOList<T>::operator=(const LIFOList& other) {
	if (this != &other) {
		//Удалить
		Node<T>* cur = head;
		while (cur != nullptr) {
			Node<T>* next_node = cur->next;
			delete cur;
			cur = next_node;
		}
		//Занулить
		head = nullptr;
		tail = nullptr;
		size = 0;

		// Копировать
		if (other.head) {
			head = new Node<T>(*other.head);
			Node<T>* current = head;
			Node<T>* current2 = other.head->next;
			while (current2) {
				current->next = new Node<T>(*current2);
				current = current->next;
				current2 = current2->next;
			}
			tail = current;
			size = other.size;
		}
	}
	return *this;
}