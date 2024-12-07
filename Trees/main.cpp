#include<iostream>
#include"Tree.h"
#include"Tree_impl.h"

int main() {
	Tree<int> g;
	int a = 1, b = 2, c = 3, d = 4;
	g.insert(a);
	g.insert(b);
	g.insert(c);
	g.insert(d);
	g.print();

	Tree<int> be = g;
	be.print();
}