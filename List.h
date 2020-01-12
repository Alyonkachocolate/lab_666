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
        Node *next_ = nullptr, *previous_ = nullptr;

        explicit Node(T value) : value_(value) {}
    };

    size_t size_ = 0;
    Node *first_ = nullptr;
    Node *last_ = nullptr;

    void push_only(Node *node) {
        first_ = last_ = node;

        ++size_;
    }

    void push_first(Node *node) {
        node->next_ = first_;
        first_->previous_ = node;
        first_ = node;

        ++size_;
    }

    void push_last(Node *node) {
        node->previous_ = last_;
        last_->next_ = node;
        last_ = node;

        ++size_;
    }

    void push_after(Node *previous, Node *node) {
        Node *next = previous->next_;

        previous->next_ = node;
        node->previous_ = previous;

        next->previous_ = node;
        node->next_ = next;

        ++size_;
    }

    void push_before(Node *next, Node *node) {
        Node *previous = next->previous_;

        previous->next_ = node;
        node->previous_ = previous;

        next->previous_ = node;
        node->next_ = next;

        ++size_;
    }

    T pop_only() {
        Node *node = first_;
        T value = node->value_;
        delete node;

        first_ = last_ = nullptr;
        size_ = 0;

        return value;
    }

    T pop_first() {
        Node *node = first_;
        (first_ = node->next_)->previous_ = nullptr;

        T value = node->value_;
        delete node;
        --size_;

        return value;
    }

    T pop_last() {
        Node *node = last_;
        (last_ = node->previous_)->next_ = nullptr;

        T value = node->value_;
        delete node;
        --size_;

        return value;
    }

    T pop(Node *node) {
        node->next_->previous_ = node->previous_;
        node->previous_->next_ = node->next_;

        T value = node->value_;
        delete node;
        --size_;

        return value;
    }

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
        if (size_ == 0) push_only(new Node(value));
        else push_first(new Node(value));
    }

    void push_end(T value) {
        if (size_ == 0) push_only(new Node(value));
        else push_last(new Node(value));
    }

    void push_i_index(T value, int index) {
        if (index < 0 || index > size_) throw out_of_range("Bad index");

        if (index == 0) push_first(new Node(value));
        else if (index == size_) push_last(new Node(value));
        else {
            int i = 0;
            Node *next = first_;
            while (i++ < index) next = next->next_;
            push_before(next, new Node(value));
        }
    }

    void add_after(T value, T previous_value) {
        if (size_ == 0) return;

        if (last_->value_ == previous_value) {
            push_last(new Node(value));
            return;
        }

        Node *previous = first_;
        while (previous != nullptr) {
            if (previous->value_ == previous_value) {
                push_after(previous, new Node(value));
                return;
            }
            previous = previous->next_;
        }
    }

    void add_before(T value, T next_value) {
        if (size_ == 0) return;

        cout << first_->value_ << endl;
        if (first_->value_ == next_value) {
            push_first(new Node(value));
            return;
        }

        Node *next = first_;
        while (next != nullptr) {
            if (next->value_ == next_value) {
                push_before(next, new Node(value));
                return;
            }
            next = next->next_;
        }
    }

    T pop_begin() {
        if (size_ == 0) throw out_of_range("List is empty");
        if (size_ == 1) return pop_only();

        return pop_first();
    }

    T pop_end() {
        if (size_ == 0) throw out_of_range("List is empty");
        if (size_ == 1) return pop_only();

        return pop_last();
    }

    void pop(T value) {
        if (size_ == 0) return;
        if (size_ == 1) {
            if (first_->value_ == value) pop_only();
            return;
        }
        if (first_->value_ == value) {
            pop_first();
            return;
        }
        if (last_->value_ == value) {
            pop_last();
            return;
        }

        Node* node = first_;
        while (node != last_) {
            if (node->value_ == value) {
                pop(node);
                return;
            }
            node = node->next_;
        }
    }

    T pop_i_index(int index) {
        if (index < 0 || index >= size_) throw out_of_range("Bad index");

        if (index == 0) return pop_first();
        if (index == size_ - 1) return pop_last();

        int i = 0;
        Node* node = first_;
        while (node != last_) {
            node = node->next_;
            if (++i == index) return pop(node);
        }

        throw out_of_range("Bad index");
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

