
#include <iostream>
using namespace std;

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct Node {
    int data;
    Node* next;
};

// Tao node
Node* createNode(int x) {
    Node* p = new Node;
    p->data = x;
    p->next = nullptr;
    return p;
}

// Chen dau
void insertFirst(Node*& head, int x) {
    Node* p = createNode(x);
    p->next = head;
    head = p;
}

// Chen cuoi
void insertLast(Node*& head, int x) {
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
void insertValue(Node*& head, int x, int index) {
    if (index < 0) {
        cout << "Vi tri khong hop le!" << endl;
        return;
    }

    if (index == 0) {
        insertFirst(head, x);
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
void deleteFirst(Node*& head) {
    if (head == nullptr) {
        cout << "List rong!" << endl;
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;
}

// Xoa cuoi
void deleteLast(Node*& head) {
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
void deleteValue(Node*& head, int index) {
    if (index < 0 || head == nullptr) {
        cout << "Vi tri khong hop le!" << endl;
        return;
    }

    if (index == 0) {
        deleteFirst(head);
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
int indexOf(Node* head, int x) {
    int index = 0;

    while (head != nullptr) {
        if (head->data == x) {
            return index;
        }
        head = head->next;
        index++;
    }

    return -1;
}

// Duyet xuoi
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Duyet nguoc
void printReverse(Node* head) {
    if (head == nullptr) return;

    printReverse(head->next);
    cout << head->data << " ";
}

#endif

#ifndef LINKED_LIST_NO_MAIN
int main() {
    Node* head = nullptr;

    insertFirst(head, 10);
    insertLast(head, 20);
    insertLast(head, 30);
    insertLast(head, 40);

    cout << "List ban dau: ";
    printList(head);

    insertValue(head, 15, 1);
    cout << "Sau khi chen vi tri 1: ";
    printList(head);

    deleteFirst(head);
    cout << "Sau khi xoa dau: ";
    printList(head);

    deleteLast(head);
    cout << "Sau khi xoa cuoi: ";
    printList(head);

    deleteValue(head, 1);
    cout << "Sau khi xoa vi tri 1: ";
    printList(head);

    cout << "Duyet nguoc: ";
    printReverse(head);
    cout << endl;

    // Giai phong bo nho
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
#endif
