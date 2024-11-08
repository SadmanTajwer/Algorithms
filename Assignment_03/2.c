#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000

struct item {
    int benefit_per_unit;
    int weight;
};

struct item items[MAX_N];

int cmp(const void* a, const void* b) {
    struct item* item1 = (struct item*)a;
    struct item* item2 = (struct item*)b;
    double ratio1 = (double)item1->benefit_per_unit / item1->weight;
    double ratio2 = (double)item2->benefit_per_unit / item2->weight;
    return (ratio2 > ratio1) ? 1 : -1;
}

int main() {
    int n, w, i;
    double total_benefit = 0;

    scanf("%d %d", &n, &w);

    for (i = 0; i < n; i++) {
        scanf("%d", &items[i].benefit_per_unit);
    }

    for (i = 0; i < n; i++) {
        scanf("%d", &items[i].weight);
    }

    qsort(items, n, sizeof(struct item), cmp);

    for (i = 0; i < n && w > 0; i++) {
        if (w >= items[i].weight) {
            total_benefit += items[i].benefit_per_unit * items[i].weight;
            w -= items[i].weight;
        } else {
            total_benefit += items[i].benefit_per_unit * w;
            w = 0;
        }
    }

    printf("%.2f\n", total_benefit);

    return 0;
}

