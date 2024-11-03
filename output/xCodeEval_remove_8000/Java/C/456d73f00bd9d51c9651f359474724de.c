#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MOD 1000000007

typedef struct {
    long long* d;
    int size;
} Array;

typedef struct {
    Array* keys;
    Array* values;
} HashMap;

typedef struct {
    int* arr;
    int size;
} List;

typedef struct {
    int** arr;
    int rows;
    int cols;
} Matrix;

typedef struct {
    int y;
    int x;
} Point;

typedef struct {
    long long logP;
    bool id10;
} Prob;

typedef struct {
    char* buf;
    int bufc;
    int bufi;
} IO;

void initArray(Array* array, int size) {
    array->d = (long long*)malloc(size * sizeof(long long));
    array->size = size;
}

void initHashMap(HashMap* hashMap, int size) {
    hashMap->keys = (Array*)malloc(size * sizeof(Array));
    hashMap->values = (Array*)malloc(size * sizeof(Array));
}

void initList(List* list, int size) {
    list->arr = (int*)malloc(size * sizeof(int));
    list->size = size;
}

void initMatrix(Matrix* matrix, int rows, int cols) {
    matrix->arr = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix->arr[i] = (int*)malloc(cols * sizeof(int));
    }
    matrix->rows = rows;
    matrix->cols = cols;
}

void initIO(IO* io) {
    io->buf = (char*)malloc(1 << 15);
    io->bufc = 0;
    io->bufi = 0;
}

void solve();

int main() {
    solve();
    return 0;
}

void solve() {
    long long n, m;
    scanf("%lld %lld", &n, &m);
    if (m < n) {
        long long helper = m;
        m = n;
        n = helper;
    }

    if (n == 1) {
        printf("%lld\n", id17(m));
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

long long id17(long long m) {
    long long ans = 6 * (m / 6);
    if (m % 6 == 5) ans += 4;
    else if (m % 6 == 4) ans += 2;
    return ans;
}
