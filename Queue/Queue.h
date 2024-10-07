#pragma once
#include<iostream>	
class Queue
{
private:
	int* data;
	int size = 0;
public:
	Queue();
	~Queue();
	int pop();
	int top();
	void push(int value);
	bool is_empty();
	void print();
	int lenght() const;

};

