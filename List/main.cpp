#include <iostream>
#include"List.h"
int main()
{

	List l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.show();
	List k(l);
	k.push_back(4);
	k.push_back(5);
	k.push_back(6);
	std::cout << "\n";
	k.show();
	k.insert(0, 7);
	k.show();

}
