#include "List.h"
#include <iostream>
using namespace std;

template<class T>
List<T>::List()
	: head(nullptr), tail(nullptr), size(0)
{}

template<class T>
List<T>::List(const List<T>& other) : head(nullptr), tail(nullptr), size(0) {
	Node* cur = other.head;
	while (cur) {
		push_back(cur->value);
		cur = cur->next;
	}
}

template<class T>
List<T>& List<T>::operator=(const List<T>& other) {
	if (this != &other) {
		if (this != nullptr) { clear(); }

		Node* current = other.head;
		for (size_t i = 0; i < other.size; ++i) {
			push_back(current->value);
			current = current->next;
		}
	}
	return *this;
}

template<class T>
void List<T>::reverse() {
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

template<class T>
void List<T>::pop_back()
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

template<class T>
void List<T>::pop_front() {
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

template<class T>
void List<T>::push_back(T& value) {
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

template<class T>
void List<T>::push_front(T& value) {
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

template<class T>
void List<T>::clear() {
	while (head) {
		Node* temp = head;
		head = head->next;
		delete temp;
	}
	tail = nullptr;
	size = 0;
}

template<class T>
bool List<T>::insert(int index, T& value)
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

template<class T>
int List<T>::replace(int key, T& value)
{
	Node* current = head;
	int counter = 0;
	while (current) {
		if (current->value == key) {
			current->value = value;
			counter++;
		}
		current = current->next;
	}
	return counter;
}

template<class T>
void List<T>::show() const
{
	Node* current = head;
	while (current)
	{
		cout << current->value << " ";
		current = current->next;
	}
	cout << endl;
}

template<class T>
T& List<T>::operator[](int index)
{
	Node* current = head;
	for (int i = 0; i < index; i++) {
		current = current->next;
	}
	return current->value;
}

template<class T>
List<T>& List<T>::operator+(const List<T>& other)
{
	List<T>* newList = new List<T>();

	//Добавить элементы с одного списка
	Node* current = head;
	for (size_t i = 0; i < size; ++i) {
		newList->push_back(current->value);
		current = current->next;
	}
	//Добавить элементы со второго списка
	current = other.head;
	for (size_t i = 0; i < other.size; ++i) {
		newList->push_back(current->value);
		current = current->next;
	}
	//вернуть список
	return *newList;
}

template<class T>
inline List<T>& List<T>::operator*(const List<T>& other)
{
	List<T>* newList = new List<T>();
	Node* currentThis = head;

	//Пройтись по первому списку
	for (size_t i = 0; i < size; ++i)
	{
		//Пройтись по второму
		Node* currentOther = other.head;
		for (size_t j = 0; j < other.size; ++j)
		{
			//Проверить на наличие
			if (currentThis->value == currentOther->value) {
				//Добавить
				newList->push_back(currentThis->value);
			}
			currentOther = currentOther->next;
		}
		currentThis = currentThis->next;
	}
	//Вернуть список
	return *newList;
}

template<class T>
List<T>::~List() {
	clear();
}
