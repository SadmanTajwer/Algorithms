#include <stdio.h>
#include <string.h>

#define MAX_T_LEN 10000000
#define MAX_P_LEN 1000

char T[MAX_T_LEN+1], P[MAX_P_LEN+1];
int pi[MAX_P_LEN];

void prefix_function() {
    int m = strlen(P), k = 0;
    pi[0] = 0;
    for (int i = 1; i < m; i++) {
        while (k > 0 && P[k] != P[i]) {
            k = pi[k-1];
        }
        if (P[k] == P[i]) {
            k++;
        }
        pi[i] = k;
    }
}

void kmp_search() {
    int n = strlen(T), m = strlen(P), k = 0;
    for (int i = 0; i < n; i++) {
        while (k > 0 && P[k] != T[i]) {
            k = pi[k-1];
        }
        if (P[k] == T[i]) {
            k++;
        }
        if (k == m) {
            printf("%d %d\n", i-m+1, i);
            k = pi[k-1];
        }
    }
}

int main() {
    scanf("%s %s", T, P);
    prefix_function();
    kmp_search();
    return 0;
}
