#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    long *data;
    int size;
} LongArray;

typedef struct {
    int *data;
    int size;
} IntArray;

typedef struct {
    bool *used;
    int size;
} BoolArray;

typedef struct {
    long result;
    IntArray *B;
    LongArray *A;
    BoolArray *used;
} Solver;

LongArray readLongArray(int size) {
    LongArray array;
    array.size = size;
    array.data = (long *)malloc(size * sizeof(long));
    for (int i = 0; i < size; i++) {
        scanf("%ld", &array.data[i]);
    }
    return array;
}

IntArray readIntArray(int size) {
    IntArray array;
    array.size = size;
    array.data = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        scanf("%d", &array.data[i]);
    }
    return array;
}

void freeLongArray(LongArray *array) {
    free(array->data);
}

void freeIntArray(IntArray *array) {
    free(array->data);
}

void freeBoolArray(BoolArray *array) {
    free(array->used);
}

void solve(Solver *solver, int n) {
    long *A = solver->A->data;
    int *B = solver->B->data;
    bool *used = solver->used->used;
    long res = 0;

    for (int idx = 0; idx < n; ) {
        int to = idx;
        while (to + 1 < n && A[to + 1] == A[idx]) {
            to++;
        }
        bool valid = to > idx;
        if (!valid) {
            for (int i = 0; i < idx; i++) {
                if (used[i] && (A[i] & A[idx]) == A[idx]) {
                    valid = true;
                }
            }
        }
        if (valid) {
            for (int i = idx; i <= to; i++) {
                res += B[i];
                used[i] = true;
            }
        }
        idx = to + 1;
    }
    printf("%ld\n", res);
}

int main() {
    int n;
    scanf("%d", &n);

    LongArray A = readLongArray(n);
    IntArray B = readIntArray(n);
    
    BoolArray used;
    used.size = n;
    used.used = (bool *)calloc(n, sizeof(bool));

    Solver solver = {0, &B, &A, &used};
    solve(&solver, n);

    freeLongArray(&A);
    freeIntArray(&B);
    freeBoolArray(&used);
    
    return 0;
}
