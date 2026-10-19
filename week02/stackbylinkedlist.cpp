
#ifndef STACKBYLINKEDLIST_H
#define STACKBYLINKEDLIST_H

#define LINKED_LIST_NO_MAIN
#include "linked_list.cpp"

struct Stack {
    Node* head;
    int count;

    Stack() {
        head = nullptr;
        count = 0;
    }

    void push(int x) {
        insertFirst(head, x);
        count++;
    }

    int pop() {
        if (head == nullptr) {
            cout << "Stack rong!" << endl;
            return -1;
        }

        int x = head->data;
        deleteFirst(head);
        count--;
        return x;
    }

    int top() {
        if (head == nullptr) {
            cout << "Stack rong!" << endl;
            return -1;
        }

        return head->data;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    int size() {
        return count;
    }

    void print() {
        printList(head);
    }

    void clear() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        count = 0;
    }

    ~Stack() {
        clear();
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

    cout << "Stack rong? " << s.isEmpty() << endl;

    return 0;
}
