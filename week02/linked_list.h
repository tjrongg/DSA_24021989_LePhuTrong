#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct LinkedList {
    Node* head = nullptr;

    // Tao node
    Node* createNode(int x) {
        Node* p = new Node;
        p->data = x;
        p->next = nullptr;
        return p;
    }

    // Truy cap phan tu tai vi tri index
    void getIdList(int index) {
        if (index < 0) {
            cout << "Vi tri khong hop le!" << endl;
            return;
        }
        Node* cur = head;
        for (int i = 0; i < index && cur != nullptr; i++) {
            cur = cur->next;
        }
        if (cur == nullptr) {
            cout << "Vi tri khong hop le!" << endl;
            return;
        }
        cout << cur->data << endl;
    }

    // Chen dau
    void insertFirst(int x) {
        Node* p = createNode(x);
        p->next = head;
        head = p;
    }

    // Chen cuoi
    void insertLast(int x) {
        Node* p = createNode(x);
        if (head == nullptr) {
            head = p;
            return;
        }
        Node* cur = head;
        while (cur->next != nullptr) {
            cur = cur->next;
        }
        cur->next = p;
    }

    // Chen tai vi tri index
    void insertValue(int x, int index) {
        if (index < 0) {
            cout << "Vi tri khong hop le!" << endl;
            return;
        }
        if (index == 0) {
            insertFirst(x);
            return;
        }
        Node* cur = head;
        for (int i = 0; i < index - 1 && cur != nullptr; i++) {
            cur = cur->next;
        }
        if (cur == nullptr) {
            cout << "Vi tri khong hop le!" << endl;
            return;
        }
        Node* p = createNode(x);
        p->next = cur->next;
        cur->next = p;
    }

    // Xoa dau
    void deleteFirst() {
        if (head == nullptr) {
            cout << "List rong!" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Xoa cuoi
    void deleteLast() {
        if (head == nullptr) {
            cout << "List rong!" << endl;
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        Node* cur = head;
        while (cur->next->next != nullptr) {
            cur = cur->next;
        }
        delete cur->next;
        cur->next = nullptr;
    }

    // Xoa tai vi tri index
    void deleteValue(int index) {
        if (index < 0 || head == nullptr) {
            cout << "Vi tri khong hop le!" << endl;
            return;
        }
        if (index == 0) {
            deleteFirst();
            return;
        }
        Node* cur = head;
        for (int i = 0; i < index - 1 && cur != nullptr; i++) {
            cur = cur->next;
        }
        if (cur == nullptr || cur->next == nullptr) {
            cout << "Vi tri khong hop le!" << endl;
            return;
        }
        Node* temp = cur->next;
        cur->next = temp->next;
        delete temp;
    }

    // Tim vi tri cua x
    int indexOf(int x) {
        int index = 0;
        Node* cur = head;
        while (cur != nullptr) {
            if (cur->data == x) {
                return index;
            }
            cur = cur->next;
            index++;
        }
        return -1;
    }

    // Duyet xuoi
    void printList() {
        Node* cur = head;
        while (cur != nullptr) {
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << endl;
    }

    // Ham phu tro de quy cho duyet nguoc
    void printReverseHelper(Node* node) {
        if (node == nullptr) return;
        printReverseHelper(node->next);
        cout << node->data << " ";
    }

    // Duyet nguoc
    void printReverse() {
        printReverseHelper(head);
        cout << endl;
    }

    // Giai phong bo nho
    void clear() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Tu dong giai phong bo nho khi ket thuc
    ~LinkedList() {
        clear();
    }
};

#endif


