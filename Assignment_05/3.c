#include <stdio.h>

#define MAX_N 30
#define MAX_W 10000

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int N, W, b[MAX_N], w[MAX_N], dp[MAX_N+1][MAX_W+1], i, j;


    scanf("%d %d", &N, &W);
    for (i = 0; i < N; i++) {
        scanf("%d", &b[i]);
    }
    for (i = 0; i < N; i++) {
        scanf("%d", &w[i]);
    }


    for (i = 0; i <= N; i++) {
        for (j = 0; j <= W; j++) {
            dp[i][j] = 0;
        }
    }


    for (i = 1; i <= N; i++) {
        for (j = 1; j <= W; j++) {
            if (w[i-1] > j) {
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = max(dp[i-1][j], b[i-1] + dp[i-1][j-w[i-1]]);
            }
        }
    }


    printf("%d\n", dp[N][W]);

    return 0;
}
