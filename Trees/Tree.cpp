#include "Tree.h"

void Tree::print(Node* node = nullptr) {
	//Сделать проверки
	if (node == nullptr) {
		node = _root;
	}
	if (!node) return;
	std::cout << node->value << " ";
	//Обойти рекурсивно левую часть
	print(node->left);
	//Обойти рекурсивно правую часть
	print(node->right);
}

//незакоченный метод insert
void Tree::insert(int value)
{
	insert(value, _root);
}

void Tree::insert(int value, Node* node)
{
	if (node == nullptr) {
		Node* newNode = new Node(value);
		node = newNode;
		return;
	}
	if (value > node->value) {
		insert(value, node->right);
	}
	else {
		insert(value, node->left);
	}
}
