//
// Created by user on 23/12/2019.
//

#ifndef LAB_666_QUEUETEST_H
#define LAB_666_QUEUETEST_H

#include <iostream>
#include "Queue.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

void Queue_Test(){
    cout << "Queue" << endl;
    Queue<int> queue;

    int b;
    cout << "Добавление в начало (4)" << endl;
    for (int i = 0; i <= 3; i++) {
        cin >> b;
        queue.push(b);
    }

    cout << "size " << queue.size() << endl;
    queue.print();

    cout << "Удаление в конце элемента ";
    cout << queue.pop() << endl;
    queue.print();
}
#endif //LAB_666_QUEUETEST_H
