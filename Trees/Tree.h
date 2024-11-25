#pragma once
#include<iostream>

class Tree
{
private:
	class Node {
	public:
		int value;
		Node* right;
		Node* left;
		Node(int value) 
			: Node(value, nullptr, nullptr) {}
		Node(int value, Node* right, Node* left)
			: value(value), right(right), left(left) {}
	};
	
private:
	Node* _root;
public:
	Tree() : _root(nullptr) {}
	void print(Node* node = nullptr);
	void insert(int value);
	void insert(int value, Node* node);
};

