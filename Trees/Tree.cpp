#include "Tree.h"

void Tree::print(Node* node) {
	std::cout << "print start\n";
	//������� ��������
	if (node == nullptr) {
		node = _root;
	}
	if (!node) {
		std::cout << "print end\n";
		return;
	}
	std::cout << node->value << " ";
	//������ ���������� ����� �����
	print(node->left);
	//������ ���������� ������ �����
	print(node->right);
}

//������������ ����� insert
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
