#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

int main() {
    priority_queue<int, vector<int>> q;
    
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int k;
        scanf("%d", &k);
        if (k == 0) {
            if (q.empty()) {
                printf("0\n");
            } else {
                printf("%d\n", q.top());
                q.pop();
            }
        } else {
            q.push(k);
        }
    }
}