#include <stdio.h>
#include <math.h>

int walk(int n, const int* stairs, int (*dp)[300], int currentIdx, int life) {
    if (n == 1) {
        return stairs[0];
    }
    if (dp[life][currentIdx]) {
        return dp[life][currentIdx];
    }

    if (currentIdx == n - 1) {
        dp[life][currentIdx] = stairs[currentIdx];
        return dp[life][currentIdx];
    }

    if (life != 0) {
        
        if (currentIdx == n - 2) {
            dp[life][currentIdx] = walk(n, stairs, dp, currentIdx + 1, 0) + stairs[currentIdx];
            
        } else {
            dp[life][currentIdx] = std::max(walk(n, stairs, dp, currentIdx + 1, 0), walk(n, stairs, dp, currentIdx + 2, 1)) + stairs[currentIdx];
        }
        return dp[life][currentIdx];
    } else {
        if (currentIdx == n - 2) {
            return 0;
        }

        dp[life][currentIdx] = walk(n, stairs, dp, currentIdx + 2, 1) + stairs[currentIdx];
        return dp[life][currentIdx];
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int step;

    int stairs[300];

    for (int i = 0; i < n; i++) {
        scanf("%d", &stairs[i]);
    }
    
    int dp[2][300] = {0};

    printf("%d", std::max(walk(n, stairs, dp, 0, 1), walk(n, stairs, dp, 1, 1)));

}