#include <stdio.h>
#define MAX_N 30

int main() {
    int N, arr[MAX_N], dp[MAX_N], ans = 1;

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < N; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i]) {
                dp[i] = (dp[i] > dp[j] + 1) ? dp[i] : dp[j] + 1;
            }
        }
        ans = (ans > dp[i]) ? ans : dp[i];
    }
    printf("%d\n", ans);
    return 0;
}

