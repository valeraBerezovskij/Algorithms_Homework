#include <iostream>
#include"List.h"
int main()
{

	List l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.show();
	l.reverse();
	std::cout << "\n";
	l.pop_back();
	l.show();
	//List k;
	//k.push_back(4);
	//k.push_back(5);
	//k.push_back(6);

	//std::cout << "\n";

	//k.show();
	//
	//l = k;
	//
	//l.show();

}
