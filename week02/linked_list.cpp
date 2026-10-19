#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int x) {
    Node* p = new Node;
    p->data = x;
    p->next = nullptr;
    return p;
}

void insertFirst(Node*& head, int x) {
    Node* p = createNode(x);
    p->next = head;
    head = p;
}

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

void DeleteFisrt(Node*& head) {
    if (head == nullptr) return;

    Node* cur = head;
    head = head->next;
    delete cur;
}

#endif
