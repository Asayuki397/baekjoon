#include <stdio.h>
#include <iostream>

using namespace std;
const int MAX_N = 1000000;
int dp[MAX_N + 1];

int main() {
    //fast io for competetive algorithms
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for(int i = 2; i < n + 1; i++) {
        dp[i] = dp[i - 1] + 1;
        
        if (i % 2 == 0) {
            dp[i] = min(dp[i/2] + 1, dp[i]);
        }

        if (i % 3 == 0) {
            dp[i] = min(dp[i/3] + 1, dp[i]);
        } 
    }
    cout << dp[n];
    return 0;
}