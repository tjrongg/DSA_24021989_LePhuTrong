
#ifndef QUEUEBYLIST_H
#define QUEUEBYLIST_H

#define LIST_ARRAY_NO_MAIN
#include "list_array.cpp"

struct Queue {
    // Them vao cuoi Queue
    void enqueue(int x) {
        insertLast(x);
    }

    // Lay va xoa phan tu dau Queue
    int dequeue() {
        if (n == 0) {
            cout << "Queue rong!" << endl;
            return -1;
        }

        int x = arr[0];
        deleteFirst();
        return x;
    }

    // Xem phan tu dau Queue
    int front() {
        if (n == 0) {
            cout << "Queue rong!" << endl;
            return -1;
        }

        return arr[0];
    }

    // Kiem tra Queue rong
    bool isEmpty() {
        return n == 0;
    }

    // Tra ve so phan tu
    int size() {
        return n;
    }

    // In Queue
    void print() {
        printForward();
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
