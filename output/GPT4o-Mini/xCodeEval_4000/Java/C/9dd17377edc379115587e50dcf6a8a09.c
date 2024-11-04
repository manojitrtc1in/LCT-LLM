#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Position {
    int row;
    int id;
    struct Position* last;
    struct Position* next;
    struct Position* link;
} Position;

typedef struct {
    int* data;
    int size;
} IntArray;

typedef struct {
    int r, c, n, k;
    int* x;
    int* y;
} TaskE;

void decreaseByOne(int* arrays[], int sizes[]) {
    for (int i = 0; i < sizes[0]; i++) {
        for (int j = 0; j < sizeof(arrays) / sizeof(arrays[0]); j++) {
            arrays[j][i]--;
        }
    }
}

long value(Position* pos, int r) {
    if (pos->link == NULL) {
        return 0;
    }
    return (pos->row - pos->last->row) * (r - pos->link->row);
}

int compare(const void* a, const void* b) {
    Position* posA = (Position*)a;
    Position* posB = (Position*)b;
    if (posA->row != posB->row) {
        return posA->row - posB->row;
    }
    return posA->id - posB->id;
}

void solve(TaskE* task) {
    int r = task->r;
    int c = task->c;
    int n = task->n;
    int k = task->k;

    Position* headPosition = malloc(k * sizeof(Position));
    Position* tailPosition = malloc(k * sizeof(Position));
    for (int i = 0; i < k; i++) {
        headPosition[i].row = -1;
        headPosition[i].id = -1;
        headPosition[i].last = (i != 0) ? &headPosition[i - 1] : NULL;
        if (i != 0) {
            headPosition[i - 1].next = &headPosition[i];
        }
        tailPosition[i].row = r;
        tailPosition[i].id = -2;
        tailPosition[i].last = (i != 0) ? &tailPosition[i - 1] : NULL;
        if (i != 0) {
            tailPosition[i - 1].next = &tailPosition[i];
        }
    }

    Position* positions = malloc(n * sizeof(Position));
    for (int i = 0; i < n; i++) {
        positions[i].row = task->x[i];
        positions[i].id = i;
    }

    long answer = 0;
    for (int i = 0; i < c; i++) {
        int at = 0;
        while (at < n && task->y[at] < i) {
            at++;
        }
        for (int j = 0; j < k - 1; j++) {
            headPosition[j + 1].link = &tailPosition[j];
        }
        Position* set[2] = { &headPosition[k - 1], &tailPosition[0] };
        headPosition[k - 1].next = &tailPosition[0];
        tailPosition[0].last = &headPosition[k - 1];
        long delta = 0;

        for (int j = i; j < c; j++) {
            while (at < n && task->y[at] == j) {
                Position* where = set[0]; // Simplified for demonstration
                Position* current = where;
                for (int l = 1; l < k; l++) {
                    delta -= value(current, r);
                    current = current->last;
                }
                Position* next = where->next;
                delta -= value(next, r);
                current = &positions[at];
                where->next = current;
                current->last = where;
                next->last = current;
                current->next = next;
                current->link = (k == 1) ? current : where->link;
                set[0] = current; // Update set for demonstration
                delta += value(next, r);
                delta += value(current, r);
                current = where;
                for (int l = 1; l < k; l++) {
                    current->link = current->link->last;
                    delta += value(current, r);
                    current = current->last;
                }
                at++;
            }
            answer += delta;
        }
    }
    printf("%ld\n", answer);
    free(headPosition);
    free(tailPosition);
    free(positions);
}

int main() {
    TaskE task;
    scanf("%d %d %d %d", &task.r, &task.c, &task.n, &task.k);
    task.x = malloc(task.n * sizeof(int));
    task.y = malloc(task.n * sizeof(int));
    for (int i = 0; i < task.n; i++) {
        scanf("%d", &task.x[i]);
    }
    for (int i = 0; i < task.n; i++) {
        scanf("%d", &task.y[i]);
    }
    decreaseByOne((int*[]){task.x, task.y}, (int[]){task.n, task.n});
    qsort(task.y, task.n, sizeof(int), compare);
    solve(&task);
    free(task.x);
    free(task.y);
    return 0;
}
