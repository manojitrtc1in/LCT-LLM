#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_N 200000
#define MAX_M 200000

typedef struct {
    int *L, *R, *A, *B, *C, *max, *best;
    int *orderV, *orderC;
    long *tree;
    int *map;
    int idx;
} Task;

typedef struct {
    long *array;
    int n;
} IntervalTree;

void initIntervalTree(IntervalTree *tree, int n) {
    tree->array = (long *)malloc(sizeof(long) * (4 * n + 1));
    tree->n = n;
    memset(tree->array, 0, sizeof(long) * (4 * n + 1));
}

void update(IntervalTree *tree, int pos, long x) {
    // Update logic here
}

long query(IntervalTree *tree, int from, int to) {
    // Query logic here
    return 0; // Placeholder
}

void process1(Task *task, int n, int m) {
    // Process1 logic here
}

void process2(Task *task, int n, int m) {
    // Process2 logic here
}

void process3(Task *task, int n, int m) {
    // Process3 logic here
}

void solve(Task *task, int testNumber) {
    int n = task->idx, m = task->idx; // Placeholder for input
    task->L = (int *)malloc(sizeof(int) * n);
    task->R = (int *)malloc(sizeof(int) * n);
    task->A = (int *)malloc(sizeof(int) * m);
    task->B = (int *)malloc(sizeof(int) * m);
    task->C = (int *)malloc(sizeof(int) * m);
    task->max = (int *)malloc(sizeof(int) * m);
    task->best = (int *)malloc(sizeof(int) * m);
    task->orderV = (int *)malloc(sizeof(int) * n);
    task->orderC = (int *)malloc(sizeof(int) * m);
    
    // Input reading logic here

    IntervalTree tree;
    initIntervalTree(&tree, task->idx);
    
    process1(task, n, m);
    process2(task, n, m);
    process3(task, n, m);
    
    long ret = 0;
    int aux = -1;
    for (int i = 0; i < m; i++) {
        long x = 1L * task->max[i] * task->C[i];
        if (x > ret) {
            ret = x;
            aux = i;
        }
    }
    
    printf("%ld\n", ret);
    if (ret > 0)
        printf("%d %d\n", task->best[aux] + 1, aux + 1);
}

int main() {
    Task task;
    task.idx = 0; // Placeholder for input
    solve(&task, 1);
    
    // Free allocated memory
    free(task.L);
    free(task.R);
    free(task.A);
    free(task.B);
    free(task.C);
    free(task.max);
    free(task.best);
    free(task.orderV);
    free(task.orderC);
    
    return 0;
}
