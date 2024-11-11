#include <stdio.h>
#include <string.h>

#define MAX_LEN 100005

int pi[MAX_LEN];

int main() {
    char P[MAX_LEN];
    scanf("%s", P);

    int m = strlen(P);
    pi[0] = 0;
    for (int i = 1, j = 0; i < m; i++) {
        while (j > 0 && P[i] != P[j]) {
            j = pi[j-1];
        }
        if (P[i] == P[j]) {
            j++;
        }
        pi[i] = j;
    }

    for (int i = 0; i < m; i++) {
        printf("%d ", pi[i]);
    }

    return 0;
}

