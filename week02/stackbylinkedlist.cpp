#ifndef STACKBYLINKEDLIST_H
#define STACKBYLINKEDLIST_H


#include "linked_list.h"

struct Stack {
    LinkedList list; // Moi Stack so huu 1 LinkedList rieng
    int count = 0;

    // Them vao dinh Stack (chen dau danh sach - O(1))
    void push(int x) {
        list.insertFirst(x);
        count++;
    }

    // Lay va xoa dinh Stack (xoa dau danh sach - O(1))
    int pop() {
        if (isEmpty()) {
            cout << "Stack rong!" << endl;
            return -1;
        }
        int x = list.head->data;
        list.deleteFirst();
        count--;
        return x;
    }

    // Xem dinh Stack
    int top() {
        if (isEmpty()) {
            cout << "Stack rong!" << endl;
            return -1;
        }
        return list.head->data;
    }

    // Kiem tra Stack rong
    bool isEmpty() {
        return list.head == nullptr;
    }

    // Kich thuoc Stack
    int size() {
        return count;
    }

    // In Stack (tu dinh xuong day)
    void print() {
        list.printList();
    }

    // Xoa toan bo Stack
    void clear() {
        list.clear();
        count = 0;
    }
};

#endif

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Stack: ";
    s.print();

    cout << "Top: " << s.top() << endl;
    cout << "Pop: " << s.pop() << endl;

    cout << "Stack sau pop: ";
    s.print();

    cout << "Size hien tai: " << s.size() << endl;
    cout << "Stack rong? " << s.isEmpty() << endl;

    return 0;
}
