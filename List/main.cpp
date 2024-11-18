#include <iostream>
#include "List.h"
#include "LIFOList.h"

int main()
{
	LIFOList<int> l;
	l.push(1);
	l.push(2);
	l.push(3);
	l.print();
	l.pop();
	l.print();

}
