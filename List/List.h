#pragma once

class List
{
    class Node {
    public:
        int value;
        Node* prev;
        Node* next;
        Node() :value(0), prev(nullptr), next(nullptr)
        {}
        Node(int value) :value(value), prev(nullptr), next(nullptr)
        {}
        Node(Node* prev, int value) :value(value), prev(prev), next(nullptr)
        {}
    };
private:
    Node* head;
    Node* tail;
    size_t size;
public:
    List();
    void push_back(int value);
    void push_front(int value);
    void clear();
    void show() const;
    ~List();
};