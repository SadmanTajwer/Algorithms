#include <stdio.h>
#include <string.h>

#define MAX_M 40
#define MAX_N 40

char m[MAX_M + 1], n[MAX_N + 1];
int dp[MAX_M + 1][MAX_N + 1];

int main() {

    scanf("%s %s", m, n);

    int len_m = strlen(m);
    int len_n = strlen(n);


    for (int i = 0; i <= len_m; i++) {
        for (int j = 0; j <= len_n; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (m[i - 1] == n[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1];
            }
        }
    }


    printf("%d\n", dp[len_m][len_n]);


    int i = len_m;
    int j = len_n;
    char lcs[MAX_M + 1];
    int k = 0;
    while (i > 0 && j > 0) {
        if (m[i - 1] == n[j - 1]) {
            lcs[k++] = m[i - 1];
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    lcs[k] = '\0';


    for (int i = strlen(lcs) - 1; i >= 0; i--) {
        printf("%c", lcs[i]);
    }
    printf("\n");

    return 0;
}

