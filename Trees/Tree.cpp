#include "Tree.h"


void Tree::print(Node* node) const {
	if (!node) {
		return;
	}
	print(node->left);
	std::cout << node->value << " ";
	print(node->right);
}



void Tree::print() {
	print(_root);
}

void Tree::insert(int value) {
	if (_root == nullptr)
		_root = new Node(value);
	else 
		insert(value, _root);
}

bool Tree::find(Node* node, int value) const{
	if (!node)                { return false; }
	if (node->value == value) { return true;  }

	if (value > node->value) {
		find(node->right, value);
	}
	else if (value < node->value) {
		find(node->left, value);
	}

	return false;
}

bool Tree::find(int value) const {
	return find(_root, value);
}

void Tree::erase(Node* node, int value)
{
	if (!node) { return; }

	if (value > node->value) {
		find(node->right, value);
	}
	else if (value < node->value) {
		find(node->left, value);
	}
	else {

	}
}
void Tree::erase(int value) {
	if (!_root) { return; }
	erase(_root, value);
}

void Tree::insert(int value, Node*& node) {
	if (!node) { 
		node = new Node(value);
		return;
	}
	if (value > node->value) {
		insert(value, node->right);
	}
	else if(value < node->value) {
		insert(value, node->left);
	}
}
