#pragma once

template<class T>
class List
{
private:
	class Node {
	public:
		T       value;
		Node*     prev;
		Node*     next;

		Node() :value(0	), prev(nullptr), next(nullptr)
		{}
		Node(int value) :value(value), prev(nullptr), next(nullptr)
		{}
		Node(Node* prev, int value) :value(value), prev(prev), next(nullptr)
		{}
	};
	Node*       head;
	Node*       tail;
	size_t      size;
public:
	List();
	List(const List& other);
	List& operator=(const List& other);
	void reverse();
	void pop_back();
	void pop_front();
	void push_back(T& value);
	void push_front(T& value);
	T& back() const { return tail->value; }
	T& front() const { return head->value; }
	void clear();
	bool insert(int index, T& value);
	int replace(int key, T& value);
	void show() const;
	T& operator[](int index);
	List<T>& operator+(const List<T>& other);
	List<T>& operator*(const List<T>& other);
	~List();
};

#include"List_impl.h"