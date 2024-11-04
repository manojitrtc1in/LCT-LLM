#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

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
}

void update(IntervalTree *tree, int pos, long x) {
    // Implementation of update function
}

long query(IntervalTree *tree, int from, int to) {
    // Implementation of query function
    return 0; // Placeholder
}

void process1(Task *task, int n, int m) {
    // Implementation of process1 function
}

void process2(Task *task, int n, int m) {
    // Implementation of process2 function
}

void process3(Task *task, int n, int m) {
    // Implementation of process3 function
}

void solve(Task *task, int testNumber) {
    int n = task->L[0], m = task->A[0]; // Placeholder for input reading
    task->idx = 0;
    task->L = (int *)malloc(n * sizeof(int));
    task->R = (int *)malloc(n * sizeof(int));
    task->A = (int *)malloc(m * sizeof(int));
    task->B = (int *)malloc(m * sizeof(int));
    task->C = (int *)malloc(m * sizeof(int));
    task->max = (int *)malloc(m * sizeof(int));
    task->best = (int *)malloc(m * sizeof(int));
    task->orderV = (int *)malloc(n * sizeof(int));
    task->orderC = (int *)malloc(m * sizeof(int));
    
    // Read input and initialize arrays
    // ...

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
    if (ret > 0) {
        printf("%d %d\n", task->best[aux] + 1, aux + 1);
    }
}

int main() {
    Task task;
    // Initialize task and read input
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
    free(task.tree);
    free(task.map);
    
    return 0;
}
