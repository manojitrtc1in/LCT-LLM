#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

typedef struct {
    int count;
    long cost;
} Count;

typedef struct {
    int *data;
    int size;
} IntArray;

typedef struct {
    IntArray *counts;
    int k;
} Solver;

void increment(Count *count, long cost) {
    if (count->count >= count->k) return;
    count->cost += cost;
    count->count++;
}

long min(long a, long b) {
    return (a < b) ? a : b;
}

void sort(IntArray *arr) {
    qsort(arr->data, arr->size, sizeof(int), (int (*)(const void *, const void *))compare);
}

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void solver(Solver *solver) {
    int n;
    scanf("%d", &n);
    scanf("%d", &solver->k);
    
    IntArray arr;
    arr.size = n;
    arr.data = (int *)malloc(n * sizeof(int));
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr.data[i]);
    }
    
    sort(&arr);
    
    Count *counts = (Count *)calloc(1000001, sizeof(Count)); // Assuming max value is 1000000
    counts[0].count = 0;
    long ans = LONG_MAX;
    
    for (int i = 0; i < arr.size; i++) {
        int num = arr.data[i];
        int cost = 0;
        while (num > 0) {
            if (num < 1000001 && counts[num].count == 0) {
                counts[num].count = 0;
                counts[num].cost = 0;
            }
            increment(&counts[num], cost);
            num /= 2;
            cost++;
        }
        increment(&counts[0], cost);
    }
    
    for (int i = 0; i < 1000001; i++) {
        if (counts[i].count >= solver->k) {
            ans = min(ans, counts[i].cost);
        }
    }
    
    printf("%ld\n", ans);
    
    free(arr.data);
    free(counts);
}

int main() {
    Solver solver;
    solver.k = 0;
    solver.counts = NULL;
    solver(&solver);
    return 0;
}
