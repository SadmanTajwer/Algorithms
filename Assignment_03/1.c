#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_N 100000
#define MAX_K 1000000

int coins[MAX_N];
int dp[MAX_K+1];

int main() {
    int n, k, i, j;

    scanf("%d %d", &n, &k);

    for (i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
    }

    for (i = 1; i <= k; i++) {
        dp[i] = INT_MAX;
        for (j = 0; j < n; j++) {
            if (coins[j] <= i && dp[i-coins[j]] != INT_MAX && dp[i-coins[j]]+1 < dp[i]) {
                dp[i] = dp[i-coins[j]]+1;
            }
        }
    }

    printf("%d\n", dp[k]);

    return 0;
}
