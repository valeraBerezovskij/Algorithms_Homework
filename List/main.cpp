#include <iostream>
#include"ForwardList.h"
int main()
{
	Node head(1);
	head.next = new Node(2);
	head.next->next = new Node(3);
	head.next->next->next = new Node(4);

	Node* cur = &head;
	while (cur != nullptr) {
		std::cout << cur->value << ' ';
		cur = cur->next;
	}
}
