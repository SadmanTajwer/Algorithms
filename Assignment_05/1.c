#include <stdio.h>

#define INF 100000

int main() {
    int n, k, coins[30], dp[10001], i, j;
    scanf("%d %d", &n, &k);
    for (i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
    }
    dp[0] = 0;
    for (i = 1; i <= k; i++) {
        dp[i] = INF;
    }
    for (i = 1; i <= k; i++) {
        for (j = 0; j < n; j++) {
            if (i >= coins[j]) {
                dp[i] = dp[i] < dp[i - coins[j]] + 1 ? dp[i] : dp[i - coins[j]] + 1;
            }
        }
    }
    printf("%d\n", dp[k]);

    return 0;
}

