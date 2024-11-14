#pragma once

class List
{
private:
	class Node {
	public:
		int value;
		Node* prev;
		Node* next;
		Node() :value(0	), prev(nullptr), next(nullptr)
		{}
		Node(int value) :value(value), prev(nullptr), next(nullptr)
		{}
		Node(Node* prev, int value) :value(value), prev(prev), next(nullptr)
		{}
	};
	Node* head;
	Node* tail;
	size_t size;
public:
	List();
	List(const List& other);
	List* clone();
	void push_back(int value);
	void push_front(int value);
	int back() const { return tail->value; }
	int front() const { return head->value; }
	void clear();
	bool insert(int index, int value);
	int replace(int key, int value);
	void show() const;
	int operator[](int index);
	~List();
};