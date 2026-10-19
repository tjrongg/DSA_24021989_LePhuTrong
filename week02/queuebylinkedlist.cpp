
#ifndef QUEUEBYLINKEDLIST_H
#define QUEUEBYLINKEDLIST_H

#define LINKED_LIST_NO_MAIN
#include "linked_list.cpp"

struct Queue {
    Node* head;
    int count;

    // Khoi tao Queue rong
    Queue() {
        head = nullptr;
        count = 0;
    }

    // Them vao cuoi Queue
    void enqueue(int x) {
        insertLast(head, x);
        count++;
    }

    // Lay va xoa phan tu dau Queue
    int dequeue() {
        if (head == nullptr) {
            cout << "Queue rong!" << endl;
            return -1;
        }

        int x = head->data;
        deleteFirst(head);
        count--;

        return x;
    }

    // Xem phan tu dau Queue
    int front() {
        if (head == nullptr) {
            cout << "Queue rong!" << endl;
            return -1;
        }

        return head->data;
    }

    // Kiem tra Queue rong
    bool isEmpty() {
        return head == nullptr;
    }

    // Tra ve so phan tu
    int size() {
        return count;
    }

    // In Queue
    void print() {
        printList(head);
    }

    // Giai phong bo nho
    void clear() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }

        count = 0;
    }

    ~Queue() {
        clear();
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
