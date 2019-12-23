//
// Created by user on 23/12/2019.
//

#ifndef LAB_666_LIST_H
#define LAB_666_LIST_H

#include <iostream>
#include <cstddef>
#include <stdexcept>

using std::cout;
using std::endl;
using std::out_of_range;

template<typename T>

class List {
    class Node {
        friend class List;

        const T value_;
        Node *next_ = nullptr;

        explicit Node(T value) : value_(value) {}
    };

    size_t size_ = 0;
    Node *first_ = nullptr;
    Node *last_ = nullptr;

public:
    ~List() {
        Node *node = first_;
        while (node != nullptr) {
            Node *next = node->next_;
            delete node;
            node = next;
        }
    }

    void push_begin(T value) {
        Node *node = new Node(value);
        if (first_ == nullptr) {
            first_ = last_ = node;
        } else {
            node->next_ = first_;
            first_ = node;
        }
        size_++;
    }

    void push_end(T value) {
        Node *node = new Node(value);
        if (first_ == nullptr) {
            first_ = last_ = node;
        } else {
            Node *new_last = new Node(value);
            new_last->next_= nullptr;
            last_->next_=new_last;
            last_=new_last;
        }
        size_++;
    }

    void push_i_index(T value, int k) {
        if (k==1)  push_begin(value);
        if (k==size_) push_end(value);
        if (k!=1 && k!=size_) {
        Node *new_node = new Node(value);
        Node *node = first_;
        Node *node1= nullptr;
        int i=1;
        while (i!=k-1) {
            node = node->next_;
            i++;
        }
        for (int i=0; i<2; i++) node1=node->next_;
        node->next_=new_node;
        new_node->next_=node1;
        size_++;}
    }

    void add_after(T value, T previous) {
        Node *node = last_;
        if (previous==node->value_) push_end(value);
        if (previous!=node->value_) {
            Node *new_node = new Node(value);
            node = first_;
            while (node->value_!=previous){
                node = node->next_;
            }
            Node *node1= node->next_;
            node->next_=new_node;
            new_node->next_=node1;
            size_++;}
    }

    void add_before(T value, T previous) {
        Node *node = first_;
        if (previous==node->value_) push_begin(value);
        if (previous!=node->value_) {
            Node *new_node = new Node(value);
            node = first_;
            while (node->next_->value_!=previous){
                node = node->next_;
            }
            Node *node1= node->next_;
            node->next_=new_node;
            new_node->next_=node1;
            size_++;}
    }

    T pop_begin() {
        if (size_ == 1) {
            Node *removed = last_;
            T value = removed->value_;
            delete removed;
            first_ = last_ = nullptr;
            size_ = 0;
            return value;
        } else {
            Node *new_last = nullptr;
            Node *node = first_;
            while (node != last_) {
                new_last = node;
                node = node->next_;
            }
            T value = node->value_;
            delete node;
            new_last->next_=nullptr;
            last_=new_last;
            size_--;
            return value;}
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

#endif //LAB_666_LIST_H

