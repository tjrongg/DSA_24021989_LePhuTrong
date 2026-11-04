#define PRIORITYQUEUE_NO_MAIN
#include "priorityqueue_maxheap.cpp"

#include <iostream>
using namespace std;


// Heap Sort sử dụng Priority Queue (Max Heap)
void heapSort(int arr[], int n) {
    PriorityQueue q;
    initQueue(q);

    // Bước 1: Đưa tất cả phần tử vào Max Heap
    for (int i = 0; i < n; i++) {
        insert(q, arr[i]);
    }

    // Bước 2: Lấy phần tử lớn nhất ra lần lượt
    // và đưa vào mảng từ cuối về đầu
    for (int i = n - 1; i >= 0; i--) {
        arr[i] = delMax(q);
    }
}

int main() {
    int arr[] = {15, 45, 25, 35, 5};
    int n = 5;

    heapSort(arr, n);

    cout << "Mang sau khi sap xep: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
