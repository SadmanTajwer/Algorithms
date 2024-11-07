#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAXN 100000

int N, arr[MAXN];

int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int findMinDis() {
    int i, min = INT_MAX;
    for (i = 1; i < N; i++) {
        int dif = abs(arr[i] - arr[i - 1]);
        if (dif < min) {
            min = dif;
        }
    }
    return min;
}

int main() {
    int i;
    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    qsort(arr, N, sizeof(int), cmp);
    printf("%d\n", findMinDis());
}
