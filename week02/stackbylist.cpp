
#ifndef STACKBYLIST_H
#define STACKBYLIST_H

#define LIST_ARRAY_NO_MAIN
#include "list_array.cpp"

struct Stack {
    // Them phan tu vao dinh Stack
    void push(int x) {
        insertLast(x);
    }

    // Lay va xoa dinh Stack
    int pop() {
        if (n == 0) {
            cout << "Stack rong!" << endl;
            return -1;
        }

        int x = arr[n - 1];
        deleteLast();
        return x;
    }

    // Xem dinh Stack
    int top() {
        if (n == 0) {
            cout << "Stack rong!" << endl;
            return -1;
        }

        return arr[n - 1];
    }
int size() {
    return n;
}

    // Kiem tra Stack rong
    bool isEmpty() {
        return n == 0;
    }
};

#endif

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top: " << s.top() << endl;
    cout << "Pop: " << s.pop() << endl;
    cout << "Top sau pop: " << s.top() << endl;

    return 0;
}
