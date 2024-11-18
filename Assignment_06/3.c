#include <stdio.h>
#define MAX_N 100
#define INF 1000

int N, rows[MAX_N+1], cols[MAX_N+1], dp[MAX_N+1][MAX_N+1];

int matrix_chain_multiplication(int i, int j) {
    if (i == j) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    int min_ops = INF;
    for (int k = i; k < j; k++) {
        int ops = matrix_chain_multiplication(i, k) + matrix_chain_multiplication(k+1, j)
                  + rows[i]*cols[k]*cols[j];
        min_ops = (ops < min_ops) ? ops : min_ops;
    }
    dp[i][j] = min_ops;
    return min_ops;
}

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d %d", &rows[i], &cols[i]);
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            dp[i][j] = -1;
        }
    }
    int min_ops = matrix_chain_multiplication(1, N);
    printf("%d\n", min_ops);
    return 0 ;
}

