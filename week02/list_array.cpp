#ifndef LIST_ARRAY_H
#define LIST_ARRAY_H

#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

struct List {
    int arr[MAX_SIZE];
    int n = 0;
};
    // Truy cap phan tu (in ra man hinh)
    void getIdArr(int index) {
        if (index < 0 || index >= n) {
            cout << "Vi tri khong hop le!" << endl;
            return;
        }
        cout << arr[index] << endl;
    }

    // Lay gia tri phan tu (de dung cho Stack)
    int getValue(int index) {
        if (index < 0 || index >= n) return -1;
        return arr[index];
    }

    // Chen cuoi
    void insertLast(int x) {
        if (n >= MAX_SIZE) {
            cout << "List da day!" << endl;
            return;
        }
        arr[n] = x;
        n++;
    }

    // Chen dau
    void insertFirst(int x) {
        if (n >= MAX_SIZE) {
            cout << "List da day!" << endl;
            return;
        }
        for (int i = n; i > 0; i--) {
            arr[i] = arr[i - 1];
        }
        arr[0] = x;
        n++;
    }

    // Chen tai vi tri index
    void insertValue(int x, int index) {
        if (index < 0 || index > n || n >= MAX_SIZE) {
            cout << "Vi tri khong hop le!" << endl;
            return;
        }
        for (int i = n; i > index; i--) {
            arr[i] = arr[i - 1];
        }
        arr[index] = x;
        n++;
    }

    // Xoa dau
    void deleteFirst() {
        if (n == 0) {
            cout << "List rong!" << endl;
            return;
        }
        for (int i = 0; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        n--;
    }

    // Xoa cuoi
    void deleteLast() {
        if (n == 0) {
            cout << "List rong!" << endl;
            return;
        }
        n--;
    }

    // Xoa tai vi tri index
    void deleteIdArr(int index) {
        if (index < 0 || index >= n) {
            cout << "Vi tri khong hop le!" << endl;
            return;
        }
        for (int i = index; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        n--;
    }

    // Duyet xuoi
    void printForward() {
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Duyet nguoc
    void printReverse() {
        for (int i = n - 1; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

#endif

#ifndef LIST_ARRAY_NO_MAIN
int main() {
    List myList;

    myList.insertLast(10);
    myList.insertLast(20);
    myList.insertLast(30);

    cout << "List ban dau: ";
    myList.printForward();

    myList.insertFirst(5);
    cout << "Sau khi chen dau: ";
    myList.printForward();

    myList.insertValue(15, 2);
    cout << "Sau khi chen vi tri 2: ";
    myList.printForward();

    myList.deleteFirst();
    cout << "Sau khi xoa dau: ";
    myList.printForward();

    myList.deleteLast();
    cout << "Sau khi xoa cuoi: ";
    myList.printForward();

    myList.deleteIdArr(1);
    cout << "Sau khi xoa vi tri 1: ";
    myList.printForward();

    return 0;
}
#endif
