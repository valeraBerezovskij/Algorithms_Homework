#pragma once
#include<iostream>

class Stack
{
private:
	int* data;
	int size;
public:
	Stack();
	~Stack();

	void push(const int value);
	int top();
	int pop();

	void print();
	int length();
};

