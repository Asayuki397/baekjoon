#include <stdio.h>
#include <iostream>

using namespace std;

int heap[];

int size;

int parent(int index) {
    return (index - 1) / 2;
}

int left(int index) {
    return 2 * index + 1;
}

int right(int index) {
    return 2 * index + 2;
}

void heapifyUP(int index) {
    while (index != 0 && heap[parent(index)])
}

int main() {

    int N;
    cin >> N;
    int arr[N];
    
    for (int i = 0; i < N; i++) {

        int size = sizeof(arr) / sizeof(*arr);
        int input;
        cin >> input;

        if (input == 0) {
            if (size == 0) {
                cout << "0" << endl;
            } else {
                cout << arr[0] << endl;
                swap(&arr[0], &arr[size - 1]);
                heapify(arr, size - 1, 0);
                heapSort(arr, size - 1);
            }
        }
    }
}