#pragma once

class Node {
public:
	int value;
	Node* next;
	Node() : value(0), next(nullptr) {}
	Node(int value) : value(value), next(nullptr) {}
};

class ForwardList
{
public:
	ForwardList() : head(nullptr) {}

	void push_back(int value) {
		Node* cur = head;
		while (cur != nullptr) {
			if (cur->next == nullptr) {
				cur->next = new Node(value);
			}
		}
	}
private:
	Node* head;
};

