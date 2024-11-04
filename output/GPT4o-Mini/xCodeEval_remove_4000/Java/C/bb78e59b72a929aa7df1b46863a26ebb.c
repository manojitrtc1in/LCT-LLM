#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define MODULO 1000000007
#define MAX_T 1000000000

typedef struct {
    int *data;
    int size;
    int capacity;
} DynamicArray;

void initArray(DynamicArray *arr, int capacity) {
    arr->data = (int *)malloc(capacity * sizeof(int));
    arr->size = 0;
    arr->capacity = capacity;
}

void addValue(DynamicArray *arr, int value) {
    if (arr->size == arr->capacity) {
        arr->capacity *= 2;
        arr->data = (int *)realloc(arr->data, arr->capacity * sizeof(int));
    }
    arr->data[arr->size++] = value;
}

int getId(DynamicArray *arr, int key) {
    for (int i = 0; i < arr->size; i++) {
        if (arr->data[i] == key) {
            return i;
        }
    }
    return -1;
}

typedef struct {
    long *sums;
    long *mins;
    int size;
} SegmentTree;

void initSegmentTree(SegmentTree *tree, int n) {
    tree->size = n;
    tree->sums = (long *)malloc(4 * n * sizeof(long));
    tree->mins = (long *)malloc(4 * n * sizeof(long));
    memset(tree->sums, 0, 4 * n * sizeof(long));
    memset(tree->mins, 0, 4 * n * sizeof(long));
}

void updateIndex(SegmentTree *tree, int index, long value) {
    // Implementation of updateIndex
}

long binpow(long base, long power) {
    if (power == 0) return 1;
    if (power % 2 == 0) {
        long half = binpow(base, power / 2);
        return (half * half) % MODULO;
    } else {
        return (base * binpow(base, power - 1)) % MODULO;
    }
}

long add(long a, long b) {
    return (a + b) % MODULO;
}

long subtract(long a, long b) {
    return add(a, MODULO - (b % MODULO));
}

long mult(long a, long b) {
    return (a * b) % MODULO;
}

void solve() {
    int q;
    scanf("%d", &q);
    DynamicArray queries;
    initArray(&queries, q);

    for (int i = 0; i < q; ++i) {
        int type;
        scanf("%d", &type);
        if (type == 1) {
            int time, speed;
            scanf("%d %d", &time, &speed);
            addValue(&queries, 1);
            addValue(&queries, time);
            addValue(&queries, speed);
        } else if (type == 2) {
            int time;
            scanf("%d", &time);
            addValue(&queries, 2);
            addValue(&queries, time);
        } else {
            int start, end, value;
            scanf("%d %d %d", &start, &end, &value);
            addValue(&queries, 3);
            addValue(&queries, start);
            addValue(&queries, end);
            addValue(&queries, value);
        }
    }

    // Further implementation of the solve function
}

int main() {
    solve();
    return 0;
}
