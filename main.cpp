#include <iostream>
#include "Stack.h"
#include "Queue.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() {

//    Stack<int> stack;
//    int a;
//    for (int i = 0; i <= 3; i++) {
//        cin >> a;
//        stack.push(a);
//    }
//    cout << stack.size() << endl;
//    stack.print();
//    cout << stack.pop() << endl;
//    stack.print();

    Queue<int> queue;
    int b;

    for (int i = 0; i <= 3; i++) {
        cin >> b;
        queue.push(b);
    }

    cout << "size " << queue.size() << endl;
    queue.print();
    cout << queue.pop() << endl;
    queue.print();

    return 0;
}