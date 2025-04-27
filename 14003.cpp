#include <stdio.h>
#include <iostream>
int DeleteElement(int arr[], int n, int key) {
    int i, j;
    for (i = 0, j = 0; i < n; i++) {
        if (arr[i] == key) {
            arr[j++] = arr[i];
        }
    }
    return j;
}

int main(void) {
    int n;
    scanf("%d", &n);
    int a[n];
    int b[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int target;
    int i = 0;
    while (a[0] != 0) {
        target = a[0];
        DeleteElement(a, n, target);
        i++;
    }

    for (int k = 0; k < i; k++) {
        std::cout << b[k] << " ";
        if (b[k] == 0) {
            std::cout << std::endl;
            break;
        }
    }   
}