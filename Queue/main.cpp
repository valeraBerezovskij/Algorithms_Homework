#include <iostream>
#include "Queue.h"
using namespace std;

int main()
{
	Queue q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);

	q.pop();
	q.pop();
	q.pop();

	q.print();

}