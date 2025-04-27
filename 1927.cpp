#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;
vector<int> min_heap;

int parentof(int i) {
    return (i - 1) / 2;
}

int leftof(int i) {
    return 2 * i + 1;
}

int rightof(int i) {
    return 2 * i + 2;
}

void swap(vector<int>& heap, int i, int j) {
    int temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;
}

void push_heap(vector<int>& heap, int x) {
    if (heap.empty()) { // Handle empty case
        heap.push_back(x);
        return;
    }
    int current = heap.size();
    heap[current] = x; // Correct initial index
    int parent = parentof(current);

    while (current > 0 && heap[current] < heap[parent]) {
        swap(heap, current, parent);
        current = parent;
        parent = parentof(current);
    }
}

int pop_heap(vector<int>& heap) {
    if (heap.empty()) { // Prevent accessing empty heap
        return 0; 
    }

    int popped_value = heap[0];
    swap(heap, 0, heap.size() - 1);
    heap.erase(heap.begin() + heap.size() - 1);

    int current = 0;
    while (current < heap.size()) {
        int left = leftof(current);
        int right = rightof(current);

        if (left >= heap.size() && right >= heap.size()) {
            break; // No children, exit loop
        }

        int min_child = -1;

        if (right >= heap.size()) { 
            // Only left child exists
            if (heap[left] < heap[current]) {
                min_child = left;
            } else {
                break;
            }
        } else if (left >= heap.size()) {
            // Only right child exists
            if (heap[right] < heap[current]) {
                min_child = right;
            } else {
                break;
            }
        } else {
            // Both children exist; find the smaller one
            if (heap[left] < heap[right]) {
                min_child = left;
            } else {
                min_child = right;
            }

            if (heap[min_child] >= heap[current]) {
                break;
            }
        }

        swap(heap, current, min_child);
        current = min_child;
    }

    return popped_value;
}

void print_heap(vector<int>& heap) {
    for (int i = 0; i < heap.size(); ++i) {
        cout << heap[i] << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;
        if (x == 0) {
            if (!min_heap.empty()) {
                cout << pop_heap(min_heap) << endl;
            } else {
                // Handle case where trying to pop from empty heap
                cout << "0" << endl;
            }
        } else {
            push_heap(min_heap, x);
        }
        print_heap(min_heap);
    }
}
