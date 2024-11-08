#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000

struct task {
    int start_time;
    int end_time;
};

struct task tasks[MAX_N];

int cmp(const void* a, const void* b) {
    struct task* task1 = (struct task*)a;
    struct task* task2 = (struct task*)b;
    return task1->end_time - task2->end_time;
}

int main() {
    int n, i, last_end_time = -1, completed_tasks = 0;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d %d", &tasks[i].start_time, &tasks[i].end_time);
    }

    qsort(tasks, n, sizeof(struct task), cmp);

    for (i = 0; i < n; i++) {
        if (tasks[i].start_time >= last_end_time) {
            completed_tasks++;
            last_end_time = tasks[i].end_time;
        }
    }

    printf("%d\n", completed_tasks);

    return 0;
}

