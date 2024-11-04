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

void readInt(int* value) {
    scanf("%d", value);
}

void readInts(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        readInt(&arr[i]);
    }
}

void id4(int* arrays[], int sizes[], int count) {
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < sizes[i]; j++) {
            arrays[i][j]--;
        }
    }
}

void orderBy(int* base, int* arrays[], int sizes[], int count) {
    // Implement sorting logic here
}

long value(Position* pos, int r) {
    if (pos->link == NULL) {
        return 0;
    }
    return (pos->row - pos->last->row) * (r - pos->link->row);
}

void solve(TaskE* task) {
    int r = task->r;
    int c = task->c;
    int n = task->n;
    int k = task->k;
    Position* headPosition = malloc(k * sizeof(Position));
    Position* tailPosition = malloc(k * sizeof(Position));
    Position* positions = malloc(n * sizeof(Position));
    long answer = 0;

    for (int i = 0; i < k; i++) {
        headPosition[i].row = -1;
        headPosition[i].last = (i != 0) ? &headPosition[i - 1] : NULL;
        if (i != 0) {
            headPosition[i - 1].next = &headPosition[i];
        }
    }

    for (int i = 0; i < k; i++) {
        tailPosition[i].row = r;
        tailPosition[i].last = (i != 0) ? &tailPosition[i - 1] : NULL;
        if (i != 0) {
            tailPosition[i - 1].next = &tailPosition[i];
        }
    }

    for (int i = 0; i < n; i++) {
        positions[i].row = task->x[i];
        positions[i].id = i;
    }

    for (int i = 0; i < c; i++) {
        int at = 0;
        while (at < n && task->y[at] < i) {
            at++;
        }
        for (int j = 0; j < k - 1; j++) {
            headPosition[j + 1].link = &tailPosition[j];
        }
        // Implement the rest of the logic here
    }

    printf("%ld\n", answer);
    free(headPosition);
    free(tailPosition);
    free(positions);
}

int main() {
    TaskE task;
    readInt(&task.r);
    readInt(&task.c);
    readInt(&task.n);
    readInt(&task.k);
    task.x = malloc(task.n * sizeof(int));
    task.y = malloc(task.n * sizeof(int));
    readInts(task.x, task.n);
    readInts(task.y, task.n);
    id4((int*[]){task.x, task.y}, (int[]){task.n, task.n}, 2);
    solve(&task);
    free(task.x);
    free(task.y);
    return 0;
}
