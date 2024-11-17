#include <stdio.h>
#define MAX_M 40
#define MAX_N 40
#define INF 1000

int main() {
    int M, N, grid[MAX_M][MAX_N], dp[MAX_M][MAX_N];
    scanf("%d %d", &M, &N);
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &grid[i][j]);
            dp[i][j] = INF;
        }
    }
    for (int j = 0; j < N; j++) {
        dp[M-1][j] = grid[M-1][j];
    }
    for (int i = M-2; i >= 0; i--) {
        for (int j = 0; j < N; j++) {
            int min_danger = dp[i+1][j];
            if (j > 0) {
                min_danger = (min_danger < dp[i+1][j-1]) ? min_danger : dp[i+1][j-1];
            }
            if (j < N-1) {
                min_danger = (min_danger < dp[i+1][j+1]) ? min_danger : dp[i+1][j+1];
            }
            dp[i][j] = grid[i][j] + min_danger;
        }
    }
    int min_danger = INF;
    for (int j = 0; j < N; j++) {
        min_danger = (min_danger < dp[0][j]) ? min_danger : dp[0][j];
    }
    printf("%d\n", min_danger);
    return 0;
}

