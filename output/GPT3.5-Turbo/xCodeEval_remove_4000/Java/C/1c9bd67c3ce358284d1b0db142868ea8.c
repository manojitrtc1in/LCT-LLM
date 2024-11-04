#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int X;
    int Y;
} PairInt;

PairInt makePairInt(int X, int Y) {
    PairInt pair;
    pair.X = X;
    pair.Y = Y;
    return pair;
}

PairInt addPairInt(PairInt a, PairInt b) {
    return makePairInt(a.X + b.X, a.Y + b.Y);
}

PairInt subPairInt(PairInt a, PairInt b) {
    return makePairInt(a.X - b.X, a.Y - b.Y);
}

int comparePairInt(PairInt a, PairInt b) {
    if (a.X != b.X) {
        return a.X - b.X;
    }
    return a.Y - b.Y;
}

typedef struct {
    int* arr;
    int size;
} IntArray;

IntArray makeIntArray(int size) {
    IntArray array;
    array.arr = (int*)malloc(size * sizeof(int));
    array.size = size;
    return array;
}

void reverseIntArray(IntArray* array) {
    int* temp = (int*)malloc(array->size * sizeof(int));
    int cnt = 0;
    for (int i = array->size - 1; i >= 0; i--) {
        temp[cnt++] = array->arr[i];
    }
    for (int i = 0; i < cnt; i++) {
        array->arr[i] = temp[i];
    }
    free(temp);
}

void swapIntArray(IntArray* array, int a, int b) {
    int temp = array->arr[a];
    array->arr[a] = array->arr[b];
    array->arr[b] = temp;
}

int* getOrder(const int* arr, int size) {
    IntArray order = makeIntArray(size);
    for (int i = 0; i < size; i++) {
        order.arr[i] = i;
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (arr[order.arr[j]] > arr[order.arr[j + 1]]) {
                swapIntArray(&order, j, j + 1);
            }
        }
    }
    return order.arr;
}

bool nextPermutation(int* c, int size) {
    int first = -1;
    for (int i = size - 2; i >= 0; i--) {
        if (c[i] < c[i + 1]) {
            first = i;
            break;
        }
    }
    if (first == -1) {
        return false;
    }
    int toSwap = size - 1;
    while (c[first] >= c[toSwap]) {
        toSwap--;
    }
    int temp = c[first];
    c[first] = c[toSwap];
    c[toSwap] = temp;
    toSwap = size - 1;
    first++;
    while (first < toSwap) {
        temp = c[first];
        c[first] = c[toSwap];
        c[toSwap] = temp;
        first++;
        toSwap--;
    }
    return true;
}

int lowerBound(const int* order, const int* val, int size, int need) {
    int s = 0;
    int e = size;
    while (e - s > 1) {
        int mid = (e + s) / 2;
        if (val[order[mid]] < need) {
            s = mid;
        }
        else {
            e = mid;
        }
    }
    if (val[order[s]] >= need) {
        return s;
    }
    return e;
}

int lowerBoundSingle(const int* val, int size, int need) {
    int s = 0;
    int e = size;
    while (e - s > 1) {
        int mid = (e + s) / 2;
        if (val[mid] < need) {
            s = mid;
        }
        else {
            e = mid;
        }
    }
    if (val[s] >= need) {
        return s;
    }
    return e;
}

int gcd(int a, int b) {
    return b != 0 ? gcd(b, a % b) : a;
}

int fastPow(int a, int b, int m) {
    int ans = 1;
    while (b != 0) {
        if (b & 1) {
            ans = (ans * a) % m;
        }
        a = (a * a) % m;
        b >>= 1;
    }
    return ans;
}

int invMod(int a, int m) {
    int x, y;
    int d = extendedGcd(a, m, &x, &y);
    x = x % m;
    if (x < 0) {
        x = (x + m) % m;
    }
    return x;
}

int extendedGcd(int a, int b, int* x, int* y) {
    if (a == 0) {
        *x = 0;
        *y = 1;
        return b;
    }
    int x1, y1;
    int d = extendedGcd(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;
    return d;
}

int* sieve(int n, int* size) {
    int* pr = (int*)malloc((n + 1) * sizeof(int));
    for (int i = 0; i <= n; i++) {
        pr[i] = 1;
    }
    int* prime = (int*)malloc((n + 1) * sizeof(int));
    int cnt = 0;
    pr[0] = pr[1] = 0;
    for (int i = 2; i <= n; i++) {
        if (pr[i] == 1) {
            prime[cnt++] = i;
            if ((long long)i * i <= n) {
                for (long long j = (long long)i * i; j <= n; j += i) {
                    pr[j] = 0;
                }
            }
        }
    }
    *size = cnt;
    return prime;
}

int** generatePas(int n) {
    int** pas = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        pas[i] = (int*)malloc(n * sizeof(int));
    }
    for (int i = 0; i < n; i++) {
        pas[i][0] = 0;
    }
    for (int i = 0; i < n; i++) {
        pas[0][i] = 1;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            pas[i][j] = pas[i][j - 1] + pas[i - 1][j - 1];
        }
    }
    return pas;
}

typedef struct {
    int** arr;
    int size;
} IntMatrix;

IntMatrix makeIntMatrix(int size) {
    IntMatrix matrix;
    matrix.arr = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        matrix.arr[i] = (int*)malloc(size * sizeof(int));
    }
    matrix.size = size;
    return matrix;
}

void freeIntMatrix(IntMatrix* matrix) {
    for (int i = 0; i < matrix->size; i++) {
        free(matrix->arr[i]);
    }
    free(matrix->arr);
}

typedef struct {
    int* arr;
    int size;
} IntArray;

IntArray makeIntArray(int size) {
    IntArray array;
    array.arr = (int*)malloc(size * sizeof(int));
    array.size = size;
    return array;
}

void freeIntArray(IntArray* array) {
    free(array->arr);
}

typedef struct {
    int** arr;
    int size;
} IntMatrix;

IntMatrix makeIntMatrix(int size) {
    IntMatrix matrix;
    matrix.arr = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        matrix.arr[i] = (int*)malloc(size * sizeof(int));
    }
    matrix.size = size;
    return matrix;
}

void freeIntMatrix(IntMatrix* matrix) {
    for (int i = 0; i < matrix->size; i++) {
        free(matrix->arr[i]);
    }
    free(matrix->arr);
}

typedef struct {
    int* arr;
    int size;
} IntArray;

IntArray makeIntArray(int size) {
    IntArray array;
    array.arr = (int*)malloc(size * sizeof(int));
    array.size = size;
    return array;
}

void freeIntArray(IntArray* array) {
    free(array->arr);
}

typedef struct {
    int** arr;
    int size;
} IntMatrix;

IntMatrix makeIntMatrix(int size) {
    IntMatrix matrix;
    matrix.arr = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        matrix.arr[i] = (int*)malloc(size * sizeof(int));
    }
    matrix.size = size;
    return matrix;
}

void freeIntMatrix(IntMatrix* matrix) {
    for (int i = 0; i < matrix->size; i++) {
        free(matrix->arr[i]);
    }
    free(matrix->arr);
}

typedef struct {
    int* arr;
    int size;
} IntArray;

IntArray makeIntArray(int size) {
    IntArray array;
    array.arr = (int*)malloc(size * sizeof(int));
    array.size = size;
    return array;
}

void freeIntArray(IntArray* array) {
    free(array->arr);
}

typedef struct {
    int** arr;
    int size;
} IntMatrix;

IntMatrix makeIntMatrix(int size) {
    IntMatrix matrix;
    matrix.arr = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        matrix.arr[i] = (int*)malloc(size * sizeof(int));
    }
    matrix.size = size;
    return matrix;
}

void freeIntMatrix(IntMatrix* matrix) {
    for (int i = 0; i < matrix->size; i++) {
        free(matrix->arr[i]);
    }
    free(matrix->arr);
}

typedef struct {
    int* arr;
    int size;
} IntArray;

IntArray makeIntArray(int size) {
    IntArray array;
    array.arr = (int*)malloc(size * sizeof(int));
    array.size = size;
    return array;
}

void freeIntArray(IntArray* array) {
    free(array->arr);
}

typedef struct {
    int** arr;
    int size;
} IntMatrix;

IntMatrix makeIntMatrix(int size) {
    IntMatrix matrix;
    matrix.arr = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        matrix.arr[i] = (int*)malloc(size * sizeof(int));
    }
    matrix.size = size;
    return matrix;
}

void freeIntMatrix(IntMatrix* matrix) {
    for (int i = 0; i < matrix->size; i++) {
        free(matrix->arr[i]);
    }
    free(matrix->arr);
}

typedef struct {
    int* arr;
    int size;
} IntArray;

IntArray makeIntArray(int size) {
    IntArray array;
    array.arr = (int*)malloc(size * sizeof(int));
    array.size = size;
    return array;
}

void freeIntArray(IntArray* array) {
    free(array->arr);
}

typedef struct {
    int** arr;
    int size;
} IntMatrix;

IntMatrix makeIntMatrix(int size) {
    IntMatrix matrix;
    matrix.arr = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        matrix.arr[i] = (int*)malloc(size * sizeof(int));
    }
    matrix.size = size;
    return matrix;
}

void freeIntMatrix(IntMatrix* matrix) {
    for (int i = 0; i < matrix->size; i++) {
        free(matrix->arr[i]);
    }
    free(matrix->arr);
}

typedef struct {
    int* arr;
    int size;
} IntArray;

IntArray makeIntArray(int size) {
    IntArray array;
    array.arr = (int*)malloc(size * sizeof(int));
    array.size = size;
    return array;
}

void freeIntArray(IntArray* array) {
    free(array->arr);
}

typedef struct {
    int** arr;
    int size;
} IntMatrix;

IntMatrix makeIntMatrix(int size) {
    IntMatrix matrix;
    matrix.arr = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        matrix.arr[i] = (int*)malloc(size * sizeof(int));
    }
    matrix.size = size;
    return matrix;
}

void freeIntMatrix(IntMatrix* matrix) {
    for (int i = 0; i < matrix->size; i++) {
        free(matrix->arr[i]);
    }
    free(matrix->arr);
}

typedef struct {
    int* arr;
    int size;
} IntArray;

IntArray makeIntArray(int size) {
    IntArray array;
    array.arr = (int*)malloc(size * sizeof(int));
    array.size = size;
    return array;
}

void freeIntArray(IntArray* array) {
    free(array->arr);
}

typedef struct {
    int** arr;
    int size;
} IntMatrix;

IntMatrix makeIntMatrix(int size) {
    IntMatrix matrix;
    matrix.arr = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        matrix.arr[i] = (int*)malloc(size * sizeof(int));
    }
    matrix.size = size;
    return matrix;
}

void freeIntMatrix(IntMatrix* matrix) {
    for (int i = 0; i < matrix->size; i++) {
        free(matrix->arr[i]);
    }
    free(matrix->arr);
}

typedef struct {
    int* arr;
    int size;
} IntArray;

IntArray makeIntArray(int size) {
    IntArray array;
    array.arr = (int*)malloc(size * sizeof(int));
    array.size = size;
    return array;
}

void freeIntArray(IntArray* array) {
    free(array->arr);
}

typedef struct {
    int** arr;
    int size;
} IntMatrix;

IntMatrix makeIntMatrix(int size) {
    IntMatrix matrix;
    matrix.arr = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        matrix.arr[i] = (int*)malloc(size * sizeof(int));
    }
    matrix.size = size;
    return matrix;
}

void freeIntMatrix(IntMatrix* matrix) {
    for (int i = 0; i < matrix->size; i++) {
        free(matrix->arr[i]);
    }
    free(matrix->arr);
}

typedef struct {
    int* arr;
    int size;
} IntArray;

IntArray makeIntArray(int size) {
    IntArray array;
    array.arr = (int*)malloc(size * sizeof(int));
    array.size = size;
    return array;
}

void freeIntArray(IntArray* array) {
    free(array->arr);
}

typedef struct {
    int** arr;
    int size;
} IntMatrix;

IntMatrix makeIntMatrix(int size) {
    IntMatrix matrix;
    matrix.arr = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        matrix.arr[i] = (int*)malloc(size * sizeof(int));
    }
    matrix.size = size;
    return matrix;
}

void freeIntMatrix(IntMatrix* matrix) {
    for (int i = 0; i < matrix->size; i++) {
        free(matrix->arr[i]);
    }
    free(matrix->arr);
}

typedef struct {
    int* arr;
    int size;
} IntArray;

IntArray makeIntArray(int size) {
    IntArray array;
    array.arr = (int*)malloc(size * sizeof(int));
    array.size = size;
    return array;
}

void freeIntArray(IntArray* array) {
    free(array->arr);
}

typedef struct {
    int** arr;
    int size;
} IntMatrix;

IntMatrix makeIntMatrix(int size) {
    IntMatrix matrix;
    matrix.arr = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        matrix.arr[i] = (int*)malloc(size * sizeof(int));
    }
    matrix.size = size;
    return matrix;
}

void freeIntMatrix(IntMatrix* matrix) {
    for (int i = 0; i < matrix->size; i++) {
        free(matrix->arr[i]);
    }
    free(matrix->arr);
}

typedef struct {
    int* arr;
    int size;
} IntArray;

IntArray makeIntArray(int size) {
    IntArray array;
    array.arr = (int*)malloc(size * sizeof(int));
    array.size = size;
    return array;
}

void freeIntArray(IntArray* array) {
    free(array->arr);
}

typedef struct {
    int** arr;
    int size;
} IntMatrix;

IntMatrix makeIntMatrix(int size) {
    IntMatrix matrix;
    matrix.arr = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        matrix.arr[i] = (int*)malloc(size * sizeof(int));
    }
    matrix.size = size;
    return matrix;
}

void freeIntMatrix(IntMatrix* matrix) {
    for (int i = 0; i < matrix->size; i++) {
        free(matrix->arr[i]);
    }
    free(matrix->arr);
}

typedef struct {
    int* arr;
    int size;
} IntArray;

IntArray makeIntArray(int size) {
    IntArray array;
    array.arr = (int*)malloc(size * sizeof(int));
    array.size = size;
    return array;
}

void freeIntArray(IntArray* array) {
    free(array->arr);
}

typedef struct {
    int** arr;
    int size;
} IntMatrix;

IntMatrix makeIntMatrix(int size) {
    IntMatrix matrix;
    matrix.arr = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        matrix.arr[i] = (int*)malloc(size * sizeof(int));
    }
    matrix.size = size;
    return matrix;
}

void freeIntMatrix(IntMatrix* matrix) {
    for (int i = 0; i < matrix->size; i++) {
        free(matrix->arr[i]);
    }
    free(matrix->arr);
}

typedef struct {
    int* arr;
    int size;
} IntArray;

IntArray makeIntArray(int size) {
    IntArray array;
    array.arr = (int*)malloc(size * sizeof(int));
    array.size = size;
    return array;
}

void freeIntArray(IntArray* array) {
    free(array->arr);
}

typedef struct {
    int** arr;
    int size;
} IntMatrix;

IntMatrix makeIntMatrix(int size) {
    IntMatrix matrix;
    matrix.arr = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        matrix.arr[i] = (int*)malloc(size * sizeof(int));
    }
    matrix.size = size;
    return matrix;
}

void freeIntMatrix(IntMatrix* matrix) {
    for (int i = 0; i < matrix->size; i++) {
        free(matrix->arr[i]);
    }
    free(matrix->arr);
}

typedef struct {
    int* arr;
    int size;
} IntArray;

IntArray makeIntArray(int size) {
    IntArray array;
    array.arr = (int*)malloc(size * sizeof(int));
    array.size = size;
    return array;
}

void freeIntArray(IntArray* array) {
    free(array->arr);
}

typedef struct {
    int** arr;
    int size;
} IntMatrix;

IntMatrix makeIntMatrix(int size) {
    IntMatrix matrix;
    matrix.arr = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        matrix.arr[i] = (int*)malloc(size * sizeof(int));
    }
    matrix.size = size;
    return matrix;
}

void freeIntMatrix(IntMatrix* matrix) {
    for (int i = 0; i < matrix->size; i++) {
        free(matrix->arr[i]);
    }
    free(matrix->arr);
}

typedef struct {
    int* arr;
    int size;
} IntArray;

IntArray makeIntArray(int size) {
    IntArray array;
    array.arr = (int*)malloc(size * sizeof(int));
    array.size = size;
    return array;
}

void freeIntArray(IntArray* array) {
    free(array->arr);
}

typedef struct {
    int** arr;
    int size;
} IntMatrix;

IntMatrix makeIntMatrix(int size) {
    IntMatrix matrix;
    matrix.arr = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        matrix.arr[i] = (int*)malloc(size * sizeof(int));
    }
    matrix.size = size;
    return matrix;
}

void freeIntMatrix(IntMatrix* matrix) {
    for (int i = 0; i < matrix->size; i++) {
        free(matrix->arr[i]);
    }
    free(matrix->arr);
}

typedef struct {
    int* arr;
    int size;
} IntArray;

IntArray makeIntArray(int size) {
    IntArray array;
    array.arr = (int*)malloc(size * sizeof(int));
    array.size = size;
    return array;
}

void freeIntArray(IntArray* array) {
    free(array->arr);
}

typedef struct {
    int** arr;
    int size;
} IntMatrix;

IntMatrix makeIntMatrix(int size) {
    IntMatrix matrix;
    matrix.arr = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        matrix.arr[i] = (int*)malloc(size * sizeof(int));
    }
    matrix.size = size;
    return matrix;
}

void freeIntMatrix(IntMatrix* matrix) {
    for (int i = 0; i < matrix->size; i++) {
        free(matrix->arr[i]);
    }
    free(matrix->arr);
}

typedef struct {
    int* arr;
    int size;
} IntArray;

IntArray makeIntArray(int size) {
    IntArray array;
    array.arr = (int*)malloc(size * sizeof(int));
    array.size = size;
    return array;
}

void freeIntArray(IntArray* array) {
    free(array->arr);
}

typedef struct {
    int** arr;
    int size;
} IntMatrix;

IntMatrix makeIntMatrix(int size) {
    IntMatrix matrix;
    matrix.arr = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        matrix.arr[i] = (int*)malloc(size * sizeof(int));
    }
    matrix.size = size;
    return matrix;
}

void freeIntMatrix(IntMatrix* matrix) {
    for (int i = 0; i < matrix->size; i++) {
        free(matrix->arr[i]);
    }
    free(matrix->arr);
}

typedef struct {
    int* arr;
    int size;
} IntArray;

IntArray makeIntArray(int size) {
    IntArray array;
    array.arr = (int*)malloc(size * sizeof(int));
    array.size = size;
    return array;
}

void freeIntArray(IntArray* array) {
    free(array->arr);
}

typedef struct {
    int** arr;
    int size;
} IntMatrix;

IntMatrix makeIntMatrix(int size) {
    IntMatrix matrix;
    matrix.arr = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        matrix.arr[i] = (int*)malloc(size * sizeof(int));
    }
    matrix.size = size;
    return matrix;
}

void freeIntMatrix(IntMatrix* matrix) {
    for (int i = 0; i < matrix->size; i++) {
        free(matrix->arr[i]);
    }
    free(matrix->arr);
}

typedef struct {
    int* arr;
    int size;
} IntArray;

IntArray makeIntArray(int size) {
    IntArray array;
    array.arr = (int*)malloc(size * sizeof(int));
    array.size = size;
    return array;
}

void freeIntArray(IntArray* array) {
    free(array->arr);
}

typedef struct {
    int** arr;
    int size;
} IntMatrix;

IntMatrix makeIntMatrix(int size) {
    IntMatrix matrix;
    matrix.arr = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        matrix.arr[i] = (int*)malloc(size * sizeof(int));
    }
    matrix.size = size;
    return matrix;
}

void freeIntMatrix(IntMatrix* matrix) {
    for (int i = 0; i < matrix->size; i++) {
        free(matrix->arr[i]);
    }
    free(matrix->arr);
}

typedef struct {
    int* arr;
    int size;
} IntArray;

IntArray makeIntArray(int size) {
    IntArray array;
    array.arr = (int*)malloc(size * sizeof(int));
    array.size = size;
    return array;
}

void freeIntArray(IntArray* array) {
    free(array->arr);
}

typedef struct {
    int** arr;
    int size;
} IntMatrix;

IntMatrix makeIntMatrix(int size) {
    IntMatrix matrix;
    matrix.arr = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        matrix.arr[i] = (int*)malloc(size * sizeof(int));
    }
    matrix.size = size;
    return matrix;
}

void freeIntMatrix(IntMatrix* matrix) {
    for (int i = 0; i < matrix->size; i++) {
        free(matrix->arr[i]);
    }
    free(matrix->arr);
}

typedef struct {
    int* arr;
    int size;
} IntArray;

IntArray makeIntArray(int size) {
    IntArray array;
    array.arr = (int*)malloc(size * sizeof(int));
    array.size = size;
    return array;
}

void freeIntArray(IntArray* array) {
    free(array->arr);
}

typedef struct {
    int** arr;
    int size;
} IntMatrix;

IntMatrix makeIntMatrix(int size) {
    IntMatrix matrix;
    matrix.arr = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        matrix.arr[i] = (int*)malloc(size * sizeof(int));
    }
    matrix.size = size;
    return matrix;
}

void freeIntMatrix(IntMatrix* matrix) {
    for (int i = 0; i < matrix->size; i++) {
        free(matrix->arr[i]);
    }
    free(matrix->arr);
}

typedef struct {
    int* arr;
    int size;
} IntArray;

IntArray makeIntArray(int size) {
    IntArray array;
    array.arr = (int*)malloc(size * sizeof(int));
    array.size = size;
    return array;
}

void freeIntArray(IntArray* array) {
    free(array->arr);
}

typedef struct {
    int** arr;
    int size;
} IntMatrix;

IntMatrix makeIntMatrix(int size) {
    IntMatrix matrix;
    matrix.arr = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        matrix.arr[i] = (int*)malloc(size * sizeof(int));
    }
    matrix.size = size;
    return matrix;
}

void freeIntMatrix(IntMatrix* matrix) {
    for (int i = 0; i < matrix->size; i++) {
        free(matrix->arr[i]);
    }
    free(matrix->arr);
}

typedef struct {
    int* arr;
    int size;
} IntArray;

IntArray makeIntArray(int size) {
    IntArray array;
    array.arr = (int*)malloc(size * sizeof(int));
    array.size = size;
    return array;
}

void freeIntArray(IntArray* array) {
    free(array->arr);
}

typedef struct {
    int** arr;
    int size;
} IntMatrix;

IntMatrix makeIntMatrix(int size) {
    IntMatrix matrix;
    matrix.arr = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        matrix.arr[i] = (int*)malloc(size * sizeof(int));
    }
    matrix.size = size;
    return matrix;
}

void freeIntMatrix(IntMatrix* matrix) {
    for (int i = 0; i < matrix->size; i++) {
        free(matrix->arr[i]);
    }
    free(matrix->arr);
}

typedef struct {
    int* arr;
    int size;
} IntArray;

IntArray makeIntArray(int size) {
    IntArray array;
    array.arr = (int*)malloc(size * sizeof(int));
    array.size = size;
    return array;
}

void freeIntArray(IntArray* array) {
    free(array->arr);
}

typedef struct {
    int** arr;
    int size;
} IntMatrix;

IntMatrix makeIntMatrix(int size) {
    IntMatrix matrix;
    matrix.arr = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        matrix.arr[i] = (int*)malloc(size * sizeof(int));
    }
    matrix.size = size;
    return matrix;
}

void freeIntMatrix(IntMatrix* matrix) {
    for (int i = 0; i < matrix->size; i++) {
        free(matrix->arr[i]);
    }
    free(matrix->arr);
}

typedef struct {
    int* arr;
    int size;
} IntArray;

IntArray makeIntArray(int size) {
    IntArray array;
    array.arr = (int*)malloc(size * sizeof(int));
    array.size = size;
    return array;
}

void freeIntArray(IntArray* array) {
    free(array->arr);
}

typedef struct {
    int** arr;
    int size;
} IntMatrix;

IntMatrix makeIntMatrix(int size) {
    IntMatrix matrix;
    matrix.arr = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        matrix.arr[i] = (int*)malloc(size * sizeof(int));
    }
    matrix.size = size;
    return matrix;
}

void freeIntMatrix(IntMatrix* matrix) {
    for (int i = 0; i < matrix->size; i++) {
        free(matrix->arr[i]);
    }
    free(matrix->arr);
}

typedef struct {
    int* arr;
    int size;
} IntArray;

IntArray makeIntArray(int size) {
    IntArray array;
    array.arr = (int*)malloc(size * sizeof(int));
    array.size = size;
    return array;
}

void freeIntArray(IntArray* array) {
    free(array->arr);
}

typedef struct {
    int** arr;
    int size;
} IntMatrix;

IntMatrix makeIntMatrix(int size) {
    IntMatrix matrix;
    matrix.arr = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        matrix.arr[i] = (int*)malloc(size * sizeof(int));
    }
    matrix.size = size;
    return matrix;
}

void freeIntMatrix(IntMatrix* matrix) {
    for (int i = 0; i < matrix->size; i++) {
        free(matrix->arr[i]);
    }
    free(matrix->arr);
}

typedef struct {
    int* arr;
    int size;
} IntArray;

IntArray makeIntArray(int size) {
    IntArray array;
    array.arr = (int*)malloc(size * sizeof(int));
    array.size = size;
    return array;
}

void freeIntArray(IntArray* array) {
    free(array->arr);
}

typedef struct {
    int** arr;
    int size;
} IntMatrix;

IntMatrix makeIntMatrix(int size) {
    IntMatrix matrix;
    matrix.arr = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        matrix.arr[i] = (int*)malloc(size * sizeof(int));
    }
    matrix.size = size;
    return matrix;
}

void freeIntMatrix(IntMatrix* matrix) {
    for (int i = 0; i < matrix->size; i++) {
        free(matrix->arr[i]);
    }
    free(matrix->arr);
}

typedef struct {
    int* arr;
    int size;
} IntArray;

IntArray makeIntArray(int size) {
    IntArray array;
    array.arr = (int*)malloc(size * sizeof(int));
    array.size = size;
    return array;
}

void freeIntArray(IntArray* array) {
    free(array->arr);
}

typedef struct {
    int** arr;
    int size;
} IntMatrix;

IntMatrix makeIntMatrix(int size) {
    IntMatrix matrix;
    matrix.arr = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        matrix.arr[i] = (int*)malloc(size * sizeof(int));
    }
    matrix.size = size;
    return matrix;
}

void freeIntMatrix(IntMatrix* matrix) {
    for (int i = 0; i < matrix->size; i++) {
        free(matrix->arr[i]);
    }
    free(matrix->arr);
}

typedef struct {
    int* arr;
    int size;
} IntArray;

IntArray makeIntArray(int size) {
    IntArray array;
    array.arr = (int*)malloc(size * sizeof(int));
    array.size = size;
    return array;
}

void freeIntArray(IntArray* array) {
    free(array->arr);
}

typedef struct {
    int** arr;
    int size;
} IntMatrix;

IntMatrix makeIntMatrix(int size) {
    IntMatrix matrix;
    matrix.arr = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        matrix.arr[i] = (int*)malloc(size * sizeof(int));
    }
    matrix.size = size;
    return matrix;
}

void freeIntMatrix(IntMatrix* matrix) {
    for (int i = 0; i < matrix->size; i++) {
        free(matrix->arr[i]);
    }
    free(matrix->arr);
}

typedef struct {
    int* arr;
    int size;
} IntArray;

IntArray makeIntArray(int size) {
    IntArray array;
    array.arr = (int*)malloc(size * sizeof(int));
    array.size = size;
    return array;
}

void freeIntArray(IntArray* array) {
    free(array->arr);
}

typedef struct {
    int** arr;
    int size;
} IntMatrix;

IntMatrix makeIntMatrix(int size) {
    IntMatrix matrix;
    matrix.arr = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        matrix.arr[i] = (int*)malloc(size * sizeof(int));
    }
    matrix.size = size;
    return matrix;
}

void freeIntMatrix(IntMatrix* matrix) {
    for (int i = 0; i < matrix->size; i++) {
        free(matrix->arr[i]);
    }
    free(matrix->arr);
}

int main() {
    return 0;
}
