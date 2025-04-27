#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int temp;
        scanf("%d", &temp);
        cnt++;
        if (temp == 1) {
            cnt--;
            continue;
        }
        for (int j = 2; j < temp/2 + 1; j++) {
            if (temp % j == 0) {
                cnt--;
                break;
            }
        }
    }
    printf("%d", cnt);
}