#include <iostream>
#include"ForwardList.h"
int main()
{

	ForwardList l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_front(-1);
	l.push_front(-2);
	l.push_front(-3);
	l.push_front(-4);
	l.push_front(5);
	l.print();
	l.insert(100, 3);
	std::cout << "\n";
	l.print();

}
