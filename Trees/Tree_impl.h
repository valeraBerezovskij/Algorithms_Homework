#include "Tree.h"

template<class T>
inline void Tree<T>::print(Node* node) const {
	if (!node) {
		return;
	}
	print(node->left);
	std::cout << node->value << " ";
	print(node->right);
}

template<class T>
typename Tree<T>::Node* Tree<T>::cpy(Node* node) {
	if (!node) {
		return nullptr;
	}
	Node* newNode = new Node(node->value);

	newNode->left  = cpy(node->left);
	newNode->right = cpy(node->right);

	return newNode;
}

template<class T>
inline Tree<T>::Tree(const Tree& other) {
	_root = cpy(other._root);
}

template<class T>
inline Tree<T>& Tree<T>::operator=(const Tree& other) {
	if (this != &other) {
		del(_root);
		_root = nullptr;
		_root = cpy(other._root);
	}
	return *this;
}

template<class T>
inline void Tree<T>::print() {
	print(_root);
}

template<class T>
inline void Tree<T>::insert(T& value) {
	if (_root == nullptr)
		_root = new Node(value);
	else
		insert(value, _root);
}

template<class T>
inline bool Tree<T>::find(Node* node, T& value) const {
	if (!node) { return false; }
	if (node->value == value) { return true; }

	if (value > node->value) {
		return find(node->right, value);
	}
	else if (value < node->value) {
		return find(node->left, value);
	}

	return false;
}

template<class T>
inline bool Tree<T>::find(T& value) const {
	return find(_root, value);
}

template<class T>
inline void Tree<T>::erase(Node* node, T& value)
{
	if (!node) { return; }

	if (value > node->value) {
		erase(node->right, value);
	}
	else if (value < node->value) {
		erase(node->left, value);
	}
	else {
		//нет узлов
		if (!node->left && !node->right) {
			delete node;
			node = nullptr;
		}
		//узел слева
		else if (node->left && !node->right) {
			Node* temp = node;
			node = node->left;
			delete temp;
		}
		//узел справа
		else if (!node->left && node->right) {
			Node* temp = node;
			node = node->right;
			delete temp;
		}
		//два узла
		else if (node->left && node->right) {
			Node* minright = node->right;
			for (; minright->left; ) {
				minright = minright->left;
			}
			node->value = minright->value;
			erase(node->right, minright->value);
		}
	}
}

template<class T>
inline void Tree<T>::erase(T& value) {
	if (!_root) { return; }
	erase(_root, value);
}

template<class T>
inline void Tree<T>::del(Node* node) {
	if (!node) { return; }
	del(node->left);
	del(node->right);
	delete node;
}

template<class T>
inline Tree<T>::~Tree() {
	del(_root);
}

template<class T>
inline void Tree<T>::insert(T& value, Node*& node) {
	if (!node) {
		node = new Node(value);
		return;
	}
	if (value > node->value) {
		insert(value, node->right);
	}
	else if (value < node->value) {
		insert(value, node->left);
	}
}
