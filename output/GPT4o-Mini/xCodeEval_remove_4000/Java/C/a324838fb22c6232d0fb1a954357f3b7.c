#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int **matrix;
    int size;
} Matrix;

typedef struct {
    int *array;
    int size;
} IntArray;

Matrix createMatrix(int n) {
    Matrix m;
    m.size = n;
    m.matrix = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        m.matrix[i] = (int *)malloc(n * sizeof(int));
    }
    return m;
}

void freeMatrix(Matrix m) {
    for (int i = 0; i < m.size; i++) {
        free(m.matrix[i]);
    }
    free(m.matrix);
}

IntArray readIntArray(int n) {
    IntArray arr;
    arr.size = n;
    arr.array = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr.array[i]);
    }
    return arr;
}

void freeIntArray(IntArray arr) {
    free(arr.array);
}

long calculateSum(Matrix ar, int n) {
    long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += ar.matrix[i][i];
    }
    for (int i = 0; i < n; i++) {
        sum += ar.matrix[n - i - 1][i];
    }
    for (int i = 0; i < n; i++) {
        sum += ar.matrix[(n - 1) / 2][i];
    }
    for (int i = 0; i < n; i++) {
        sum += ar.matrix[i][(n - 1) / 2];
    }
    return sum;
}

int main() {
    int test = 1;
    while (test-- > 0) {
        int n;
        scanf("%d", &n);
        Matrix ar = createMatrix(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &ar.matrix[i][j]);
            }
        }

        long sum = calculateSum(ar, n);
        printf("%ld\n", sum - ar[(n - 1) / 2][(n - 1) / 2] * 3);

        freeMatrix(ar);
    }
    return 0;
}
