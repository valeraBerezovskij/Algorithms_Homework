#include "Queue.h"

Queue::Queue()
	: data(nullptr), size(0) { }

Queue::~Queue() {
	delete[] data;
}

int Queue::pop() {
	int result = data[0];
	int new_size = size - 1;
	int* new_data = new int[new_size];
	for (int i = 0; i < size; ++i) {
		new_data[i] = data[i + 1];
	}
	delete[] data;	
	data = new_data;
	size--;
	return result;
}

int Queue::top() {
	return data[0];
}

void Queue::push(int value) {
	int new_size = size + 1;
	int* new_data = new int[new_size];
	for (int i = 0; i < size; ++i){
		new_data[i] = data[i];
	}
	new_data[new_size - 1] = value;
	delete[]data;
	data = new_data;
	size += 1;
}

bool Queue::is_empty() {
	return size == 0;
}

void Queue::print() {
	if (data == nullptr) return;
	for (int i = 0; i < size; ++i) {
		std::cout << data[i] << ' ';
	}
	std::cout << std::endl;
}

int Queue::lenght() const {
	return size;
}
