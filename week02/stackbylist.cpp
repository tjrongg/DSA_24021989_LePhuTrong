#ifndef STACKBYLIST_H
#define STACKBYLIST_H

#define LIST_ARRAY_NO_MAIN
#include "list_array.h"

struct Stack {
    List list; // Moi Stack so huu 1 List rieng biet

    // Them phan tu vao dinh Stack
    void push(int x) {
        list.insertLast(x);
    }

    // Lay va xoa dinh Stack
    int pop() {
        if (isEmpty()) {
            cout << "Stack rong!" << endl;
            return -1;
        }
        int x = list.getValue(list.n - 1);
        list.deleteLast();
        return x;
    }

    // Xem dinh Stack
    int top() {
        if (isEmpty()) {
            cout << "Stack rong!" << endl;
            return -1;
        }
        return list.getValue(list.n - 1);
    }

    // Lay kich thuoc Stack
    int size() {
        return list.n;
    }

    // Kiem tra Stack rong
    bool isEmpty() {
        return list.n == 0;
    }
};

#endif

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Size hien tai: " << s.size() << endl;
    cout << "Top: " << s.top() << endl;
    cout << "Pop: " << s.pop() << endl;
    cout << "Top sau pop: " << s.top() << endl;

    return 0;
}
