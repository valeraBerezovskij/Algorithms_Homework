#pragma once
#include<iostream>

template<class T>
class Tree
{
private:
	class Node {
	public:
		T        value;
		Node*    right;
		Node*    left;
		Node(T& value)
			: Node(value, nullptr, nullptr) {}
		Node(T value, Node* right, Node* left)
			: value(value), right(right), left(left) {}
	};
	
private:
	Node*      _root;

	void  insert (T& value, Node*& node);
	void  print  (Node* node)              const;
	bool  find   (Node* node, T& value)    const;
	void  erase  (Node* node, T& value);
	void  del    (Node* node);
	Node* cpy    (Node* node);
public:
	Tree() : _root(nullptr) {}
	Tree(const Tree& other);
	Tree& operator=(const Tree& other);
	void print ();
	void insert(T& value);
	bool find  (T& value) const;
	void erase (T& value);
	~Tree();
};