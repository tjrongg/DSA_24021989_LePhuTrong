#ifndef QUEUEBYLINKEDLIST_H
#define QUEUEBYLINKEDLIST_H


#include "linked_list.h"

struct Queue {
    LinkedList list;
    Node* tail = nullptr; // Con tro luu vi tri cuoi hang doi
    int count = 0;

    // Them vao cuoi Queue - O(1)
    void enqueue(int x) {
        Node* p = list.createNode(x);
        if (isEmpty()) {
            list.head = tail = p;
        } else {
            tail->next = p;
            tail = p;
        }
        count++;
    }

    // Lay va xoa phan tu dau Queue - O(1)
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue rong!" << endl;
            return -1;
        }

        int x = list.head->data;
        list.deleteFirst();
        count--;

        // Neu xoa xong ma Queue rong thi reset luon tail
        if (list.head == nullptr) {
            tail = nullptr;
        }
        return x;
    }
};

    // Xem phan tu dau Queue
    int front() {
        if (isEmpty()) {
            cout << "Queue rong!" << endl;
            return -1;
        }

        return list.head->data;
    }

    // Kiem tra Queue rong
    bool isEmpty() {
        return list.head == nullptr;
    }

    // Tra ve so phan tu
    int size() {
        return count;
    }

    // In Queue
    void print() {
        list.printList();
    }

    // Giai phong bo nho
    void clear() {
        list.clear();
        count = 0;
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
