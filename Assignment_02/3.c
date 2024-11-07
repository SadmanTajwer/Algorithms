#include <stdio.h>

#define MAX_N 100000

int N, array[MAX_N];

void merge_sort(int l, int r) {
    if (l >= r) {
        return;
    }
    int mid = (l + r) / 2;
    merge_sort(l, mid);
    merge_sort(mid+1, r);
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) {
        L[i] = array[l + i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = array[mid + 1 + i];
    }
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k++] = L[i++];
        } else {
            array[k++] = R[j++];
        }
    }
    while (i < n1) {
        array[k++] = L[i++];
    }
    while (j < n2) {
        array[k++] = R[j++];
    }
}

int find_max_repeat_element() {
    int max_count = 0, count = 1, max_elem = array[0];
    for (int i = 1; i < N; i++) {
        if (array[i] == array[i-1]) {
            count++;
        } else {
            if (count > max_count) {
                max_count = count;
                max_elem = array[i-1];
            }
            count = 1;
        }
    }
    if (count > max_count) {
        max_count = count;
        max_elem = array[N-1];
    }
    return max_elem;
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &array[i]);
    }
    merge_sort(0, N-1);
    int max_repeat = find_max_repeat_element();
    printf("%d\n",max_repeat);
}
