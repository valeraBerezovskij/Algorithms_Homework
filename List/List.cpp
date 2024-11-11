#include "List.h"
#include <iostream>
using namespace std;

List::List()
    :head(nullptr), tail(nullptr), size(0)
{}

List::List(const List& other) : head(nullptr), tail(nullptr), size(0) {
    Node* cur = other.head;
    while (cur) {
        push_back(cur->value);
        cur = cur->next;
    }
}

void List::push_back(int value) {
    if (head && tail) {
        Node* new_node = new Node(tail, value);
        tail->next = new_node;
        tail = new_node;
    }
    else {
        Node* new_node = new Node(value);
        head = new_node;
        tail = new_node;
    }
    size++;
}

void List::push_front(int value) {
    if (head && tail) {
        Node* new_node = new Node(value);
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }
    else {
        Node* new_node = new Node(value);
        head = new_node;
        tail = new_node;
    }
    size++;
}

void List::clear() {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
    size = 0;
}

void List::show() const
{
    Node* current = head;
    while (current)
    {
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl;
}

List::~List() {
    clear();
}
    