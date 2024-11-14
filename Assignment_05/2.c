#include <stdio.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int coins[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
    }
    int dp[k+1];
    dp[0] = 0;
    for (int i = 1; i <= k; i++) {
        dp[i] = k+1;
        for (int j = 0; j < n; j++) {
            if (coins[j] <= i && dp[i-coins[j]]+1 < dp[i]) {
                dp[i] = dp[i-coins[j]]+1;
            }
        }
    }
    if (dp[k] == k+1) {
        printf("No solution found.\n");
        return 0;
    }
    int count[n];
    for (int i = 0; i < n; i++) {
        count[i] = 0;
    }
    int i = k;
    while (i > 0) {
        for (int j = 0; j < n; j++) {
            if (coins[j] <= i && dp[i-coins[j]]+1 == dp[i]) {
                count[j]++;
                i -= coins[j];
                break;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (count[i] > 0) {
            printf("%d %d\n", coins[i], count[i]);
        }
    }
    return 0;
}
