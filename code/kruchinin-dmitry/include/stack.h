// Copyright 2014 Dmitry Kruchinin

#include <string>
#include "include/node.h"

#ifndef CODE_KRUCHININ_DMITRY_INCLUDE_STACK_H_
#define CODE_KRUCHININ_DMITRY_INCLUDE_STACK_H_

template <typename Type>
class Stack {
 public:
    Stack() : size(0) {
        tail = NULL;
    }

    ~Stack() {
        Node<Type>* tmp = tail;
        while (tmp) {
            tmp = tail->next;
            delete tail;
            tail = tmp;
        }
    }

    void push(Type element) {
        Node<Type>* tmp = new Node<Type>(element, tail);
        size++;
        tail = tmp;
    }

    Type pop() {
        if (size == 0) {
            throw std::string("Stack is empty");
        } else {
            Type Element = tail->element;
            Node<Type>* tmp = tail->next;
            delete tail;
            size--;

            tail = tmp;
            return Element;
        }
    }

    Type top() {
        if (size == 0)
            throw std::string("Stack is empty");
        else
            return tail->element;
    }

    bool isEmpty() {
        return (size == 0);
    }

 private:
    Node<Type>* tail;
    int size;
};

#endif  // CODE_KRUCHININ_DMITRY_INCLUDE_STACK_H_
