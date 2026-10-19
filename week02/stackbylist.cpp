
#define LIST_ARRAY_NO_MAIN
#include "list_array.cpp"

// Them phan tu vao dinh Stack
void push(int x) {
    insertLast(x);
}

// Xoa phan tu o dinh Stack
void pop() {
    if (n == 0) {
        cout << "Stack rong!" << endl;
        return;
    }

    deleteLast();
}

// Xem phan tu o dinh Stack
void top() {
    if (n == 0) {
        cout << "Stack rong!" << endl;
        return;
    }

    getIdArr(n - 1);
}

int main() {
    push(10);
    push(20);
    push(30);

    cout << "Stack ban dau: ";
    printForward();

    cout << "Dinh Stack: ";
    top();

    pop();

    cout << "Sau khi pop: ";
    printForward();

    return 0;
}

