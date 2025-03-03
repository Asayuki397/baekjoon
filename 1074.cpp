#include <stdio.h>
#include <cmath>

using namespace std;


int main() {
    int r;
    int c;
    int N;
    
    scanf("%d %d %d", &N, &r, &c);
    //00 01
    //10 11


    int j;
    long int sum;
    int k, l;
    printf("%d\n", k);

    for (int i = 0; i < N; i++) {
        
        j = N - i;
        k = pow(2, j);
        l = pow(2, 2*j - 1);

        if ( (r > k) && (c > k)) {
            sum += l * 3;
        } else if (r > k) {
            sum += l * 2;
        } else if (c > k) {
            sum += l;
        }
    }

    printf("%d", sum);
}