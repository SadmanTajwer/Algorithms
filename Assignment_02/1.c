#include<stdio.h>

#define MAX_N 100000

struct student {
    int roll;
    float height;
} array[MAX_N];

int N;

void merge(int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    struct student L[n1], R[n2];
    for (int i = 0; i < n1; i++) {
        L[i].height = array[l + i].height;
        L[i].roll = array[l + i].roll;
    }
    for (int j = 0; j < n2; j++) {
        R[j].height = array[m + 1 + j].height;
        R[j].roll = array[m + 1 + j].roll;
    }
    int i = 0, j = 0, k = l;
    while (i < n1 || j < n2) {
        if (i < n1 && (j >= n2 || L[i].height <= R[j].height)) {
            array[k] = L[i++];
        } else {
            array[k] = R[j++];
        }
        k++;
    }
}

void mergeSort(int l, int r) {
    if (l < r) {
        int mid = l + (r - l) / 2;
        mergeSort(l, mid);
        mergeSort(mid + 1, r);
        merge(l, mid, r);
    }
}

int main() {
    float h;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%f", &h);
        array[i].height = h;
        array[i].roll = i + 1;
    }
    mergeSort(0, N - 1);
    int k;
    scanf("%d", &k);
    if (array[k - 1].height == array[k - 2].height || array[k - 1].height == array[k].height) {
        float val = array[k - 1].height;
        int u = k - 1;
        int l = 0;
        while (l <= u) {
            int m = (l + u + 1) / 2;
            u = (val == array[m].height) ? m : u;
            l = (val > array[m].height) ? m : l;
        }
        k = l + 1;
        printf("%d", array[k].roll);
    } else {
        printf("%d", array[k - 1].roll);
    }
}
