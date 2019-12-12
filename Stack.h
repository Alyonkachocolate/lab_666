
#ifndef UNTITLED24_STACK_H
#define UNTITLED24_STACK_H

#include <iostream>
#include <cstddef>
#include <stdexcept>

using std::cout;
using std::endl;
using std::out_of_range;

template<typename T>

class Stack {

    class Node {
        friend class Stack;

        const T value_;
        Node *next_ = nullptr;

        explicit Node(T value) : value_(value) {}
    };

    size_t size_ = 0;
    Node *first_ = nullptr;

public:
    ~Stack() {
        Node *node = first_;
        while (node != nullptr) {
            Node *next = node->next_;
            delete node;
            node = next;
        }
    }

    void push(T value) {
        Node *node = new Node(value);
        node->next_ = first_;
        first_ = node;
        size_++;
    }

    T pop() {
        Node *removed = first_;
        if (removed == nullptr) {
            throw out_of_range("This stack is empty");
        }

        first_ = removed->next_;
        T value = removed->value_;
        delete removed;
        size_--;

        return value;
    }

    size_t size() const {
        return size_;
    };

    void print() {
        Node *node = first_;
        while (node != nullptr) {
            //Node *next = node->next_;
            cout << node->value_ << ' ';
            node = node->next_;
        }
        cout << endl;
    }

};


#endif //UNTITLED24_STACK_H
