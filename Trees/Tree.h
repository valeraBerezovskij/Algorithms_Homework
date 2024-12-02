#pragma once
#include<iostream>

class Tree
{
private:
	class Node {
	public:
		int      value;
		Node*    right;
		Node*    left;
		Node(int value) 
			: Node(value, nullptr, nullptr) {}
		Node(int value, Node* right, Node* left)
			: value(value), right(right), left(left) {}
	};
	
private:
	Node*      _root;
	void insert(int value, Node*& node);
	void print (Node* node) const;
	bool find  (Node* node, int value) const;
	void erase (Node* node, int value);
public:
	Tree() : _root(nullptr) {}
	void print ();
	void insert(int value);
	bool find  (int value) const;
	void erase (int value);
};

