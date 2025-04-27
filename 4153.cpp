#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
const int MAX_N = 30000;
int triangle[3]; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b, c;

    for(int i =  0; i < MAX_N; i++) {
        scanf("%d %d %d", &a, &b, &c);
        if (a + b + c == 0) break;
        triangle[0] = a;
        triangle[1] = b;
        triangle[2] = c;

        sort(triangle, triangle + 3);

        if (pow(triangle[2], 2) == pow(triangle[1], 2) + pow(triangle[0], 2)) {
            printf("right\n");
        } else printf("wrong\n");

    }

    return 0;
}