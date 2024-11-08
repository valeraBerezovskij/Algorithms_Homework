#include <iostream>
#include"ForwardList.h"
int main()
{

	ForwardList l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.print();
	ForwardList k;
	k.push_back(4);
	k.push_back(5);
	k.push_back(6);
	k = l;
	std::cout << "\n";
	k.print();

}
