#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX_SIZE 100000

typedef struct {
    long long *arr;
    int size;
    int capacity;
} DynamicArray;

DynamicArray* createDynamicArray() {
    DynamicArray *array = (DynamicArray*)malloc(sizeof(DynamicArray));
    array->arr = (long long*)malloc(MAX_SIZE * sizeof(long long));
    array->size = 0;
    array->capacity = MAX_SIZE;
    return array;
}

void destroyDynamicArray(DynamicArray *array) {
    free(array->arr);
    free(array);
}

void addElement(DynamicArray *array, long long element) {
    if (array->size == array->capacity) {
        array->capacity *= 2;
        array->arr = (long long*)realloc(array->arr, array->capacity * sizeof(long long));
    }
    array->arr[array->size++] = element;
}

long long getElement(DynamicArray *array, int index) {
    return array->arr[index];
}

typedef struct {
    DynamicArray *d;
} Solver;

void solve(Solver *solver);

Solver* createSolver() {
    Solver *solver = (Solver*)malloc(sizeof(Solver));
    solver->d = createDynamicArray();
    return solver;
}

void destroySolver(Solver *solver) {
    destroyDynamicArray(solver->d);
    free(solver);
}

void solve(Solver *solver) {
    long long n, m;
    scanf("%lld %lld", &n, &m);
    if (m < n) {
        long long helper = m;
        m = n;
        n = helper;
    }

    if (n == 1) {
        printf("%lld\n", brute1(m));
        return;
    }
    if (n == 2) {
        if (m < 3) printf("0\n");
        else if (m == 3) printf("4\n");
        else if (m == 7) printf("12\n");
        else printf("%lld\n", 2 * m);
        return;
    }

    printf("%lld\n", 2 * (n * m / 2));
}

long long brute1(long long m) {
    long long ans = 6 * (m / 6);
    if (m % 6 == 5) ans += 4;
    else if (m % 6 == 4) ans += 2;
    return ans;
}

bool closeToZero(double v) {
    return fabs(v) <= 0.0000000000001;
}

int main() {
    Solver *solver = createSolver();
    solve(solver);
    destroySolver(solver);
    return 0;
}
