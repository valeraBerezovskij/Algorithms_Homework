#include<iostream>
#include"Tree.h"

int main() {
	Tree g;
	g.insert(5);
	g.insert(6);
	g.insert(7);
	g.insert(8);
	g.print();

	std::cout << g.find(5);
}