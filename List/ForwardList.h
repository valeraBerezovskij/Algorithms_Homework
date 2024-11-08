#pragma once
#include<iostream>

class Node {
public:
	int value;
	Node* next;
	Node() : value(0), next(nullptr) {}
	Node(const Node& other);
	Node(int value) : value(value), next(nullptr) {}
};

class ForwardList
{
public:
	ForwardList() : head(nullptr), tale(nullptr) {}
	ForwardList(const ForwardList& other);
	~ForwardList();
	void push_back(int value);
	void push_front(int value);
	void insert(int value, size_t index);
	void print();

	ForwardList& operator=(const ForwardList& other);
private:
	Node* head;
	Node* tale;
};

