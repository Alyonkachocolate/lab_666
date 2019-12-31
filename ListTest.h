//
// Created by user on 23/12/2019.
//

#ifndef LAB_666_LISTTEST_H
#define LAB_666_LISTTEST_H

#include <iostream>
#include "List.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

void List_Test() {
    cout << "List" << endl;
    List<int> list;

    int c;

    cout << "Добавление в начало (2)" << endl;
    for (int i = 0; i < 2; i++) {
        cin >> c;
        list.push_begin(c);
    }
    list.print();

    cout<<"Добавление в конец (2)"<<endl;
    for (int i = 0; i < 2; i++) {
        cin >> c;
        list.push_end(c);
    }
    list.print();

    cout<<"Добавление по индексу (1) (значение, индекс)"<<endl;
    int k;
    cin >> c >> k;
    list.push_i_index(c, k);
    list.print();

    cout << "Добавление по значению после элемента (1) (значение, после какого элемента)" << endl;
    cin >> c >> k;
    list.add_after(c, k);
    list.print();

    cout << "Добавление по значению до элемента (1) (значение, до какого элемента)" << endl;
    cin >> c >> k;
    list.add_before(c, k);
    list.print();

    cout << "Размер: " << list.size() << endl;
    list.print();

    cout << "Удаление с начала" << endl << list.pop_begin() << endl;
    list.print();

    cout << "Удаление с концв" << endl << list.pop_end() << endl;
    list.print();
}

#endif //LAB_666_LISTTEST_H
