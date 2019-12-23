//
// Created by user on 23/12/2019.
//

#ifndef LAB_666_STACKTEST_H
#define LAB_666_STACKTEST_H

#include <iostream>
#include "Stack.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

void Stack_Test(){
    cout << "Stack" << endl;
    Stack<int> stack;
    int a;
    cout << "Добавление в начало (4)" << endl;
    for (int i = 0; i <= 3; i++) {
        cin >> a;
        stack.push(a);
    }

    cout << "size " << stack.size() << endl;
    stack.print();

    cout << "Удаление в начале элемента ";
    cout << stack.pop() << endl;
    stack.print();
}

#endif //LAB_666_STACKTEST_H
