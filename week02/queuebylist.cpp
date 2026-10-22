#ifndef QUEUEBYLIST_H
#define QUEUEBYLIST_H


#include "list_array.h"

struct Queue {
    List list; // Moi Queue so huu 1 List rieng biet

    // Them vao cuoi Queue
    void enqueue(int x) {
        list.insertLast(x);
    }

    // Lay va xoa phan tu dau Queue
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue rong!" << endl;
            return -1;
        }

        int x = list.getValue(0);
        list.deleteFirst();
        return x;
    }

    // Xem phan tu dau Queue
    int front() {
        if (isEmpty()) {
            cout << "Queue rong!" << endl;
            return -1;
        }

        return list.getValue(0);
    }

    // Kiem tra Queue rong
    bool isEmpty() {
        return list.n == 0;
    }

    // Tra ve so phan tu
    int size() {
        return list.n;
    }

    // In Queue
    void print() {
        list.printForward();
    }
};

#endif

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Queue: ";
    q.print();

    cout << "Front: " << q.front() << endl;
    cout << "Dequeue: " << q.dequeue() << endl;

    cout << "Queue sau dequeue: ";
    q.print();

    cout << "Size: " << q.size() << endl;

    return 0;
}
