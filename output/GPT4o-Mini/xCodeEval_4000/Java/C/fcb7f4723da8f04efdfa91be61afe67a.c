#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

typedef struct {
    int count;
    long cost;
} Count;

typedef struct {
    int *arr;
    int size;
} IntArray;

void increment(Count *count, long cost, int k) {
    if (count->count >= k) return;
    count->cost += cost;
    count->count++;
}

long min(long a, long b) {
    return (a < b) ? a : b;
}

void solver() {
    int n, k;
    scanf("%d %d", &n, &k);
    
    IntArray arr;
    arr.size = n;
    arr.arr = (int *)malloc(n * sizeof(int));
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr.arr[i]);
    }
    
    qsort(arr.arr, n, sizeof(int), (int (*)(const void *, const void *))strcmp);
    
    Count *counts = (Count *)calloc(1000001, sizeof(Count));
    counts[0].count = 0;
    
    for (int i = 0; i < n; i++) {
        int num = arr.arr[i];
        int cost = 0;
        while (num > 0) {
            if (counts[num].count == 0) {
                counts[num].count = 0;
                counts[num].cost = 0;
            }
            increment(&counts[num], cost, k);
            num = num / 2;
            cost++;
        }
        increment(&counts[0], cost, k);
    }
    
    long ans = LONG_MAX;
    for (int i = 0; i <= 1000000; i++) {
        if (counts[i].count >= k) {
            ans = min(ans, counts[i].cost);
        }
    }
    
    printf("%ld\n", ans);
    
    free(arr.arr);
    free(counts);
}

int main() {
    solver();
    return 0;
}
