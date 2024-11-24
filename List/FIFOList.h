#pragma once
#include<iostream>

template <class T>
class Node {
public:
    T value;
    Node* next;

    Node() : value(T()), next(nullptr) {}
    Node(T val) : value(val), next(nullptr) {}
    Node(const Node& other) : value(other.value), next(nullptr) {
        if (other.next != nullptr) {
            next = new Node(*other.next);
        }
    }
};

template<class T>
class FIFOList {
public:
    FIFOList() : head(nullptr), tail(nullptr), size(0) {}
    FIFOList(const FIFOList& other);
    ~FIFOList();
    void push(T value);
    void pop();
    void print();
    FIFOList& operator=(const FIFOList& other);

private:
    Node<T>* head;
    Node<T>* tail;
    size_t size;
};

template<class T>
inline FIFOList<T>::FIFOList(const FIFOList& other)
    : head(nullptr), tail(nullptr), size(0)
{
    if (other.head) {
        head = new Node<T>(*other.head);
        Node<T>* current = head;
        Node<T>* otherCurrent = other.head->next;
        while (otherCurrent) {
            current->next = new Node<T>(*otherCurrent);
            current = current->next;
            otherCurrent = otherCurrent->next;
        }
        tail = current;
        size = other.size;
    }
}

template<class T>
inline FIFOList<T>::~FIFOList() {
    Node<T>* cur = head;
    while (cur != nullptr) {
        Node<T>* next_node = cur->next;
        delete cur;
        cur = next_node;
    }
    head = nullptr;
    tail = nullptr;
    size = 0;
}

template<class T>
inline void FIFOList<T>::push(T value) {
    Node<T>* new_node = new Node<T>(value);
    if (!head) {
        head = new_node;
        tail = new_node;
    }
    else {
        tail->next = new_node;
        tail = new_node;
    }
    ++size;
}

template<class T>
inline void FIFOList<T>::pop() {
    if (!head) {
        return;
    }

    Node<T>* del = head;
    head = head->next;
    if (!head) {
        tail = nullptr;
    }
    delete del;
    --size;
}

template<class T>
inline void FIFOList<T>::print() {
    Node<T>* cur = head;
    while (cur != nullptr) {
        std::cout << cur->value << ' ';
        cur = cur->next;
    }
    std::cout << '\n';
}

template<class T>
inline FIFOList<T>& FIFOList<T>::operator=(const FIFOList& other) {
    if (this != &other) {
        //Удалить
        Node<T>* cur = head;
        while (cur != nullptr) {
            Node<T>* next_node = cur->next;
            delete cur;
            cur = next_node;
        }

        //Занулить
        head = nullptr;
        tail = nullptr;
        size = 0;

        //Копировать
        if (other.head) {
            head = new Node<T>(*other.head);
            Node<T>* current = head;
            Node<T>* otherCurrent = other.head->next;
            while (otherCurrent) {
                current->next = new Node<T>(*otherCurrent);
                current = current->next;
                otherCurrent = otherCurrent->next;
            }
            tail = current;
            size = other.size;
        }
    }
    return *this;
}
