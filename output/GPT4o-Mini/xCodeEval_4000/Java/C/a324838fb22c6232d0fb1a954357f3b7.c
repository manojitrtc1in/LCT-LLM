#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int **matrix;
    int size;
} Matrix;

Matrix readMatrix(int n) {
    Matrix m;
    m.size = n;
    m.matrix = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        m.matrix[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            scanf("%d", &m.matrix[i][j]);
        }
    }
    return m;
}

void freeMatrix(Matrix m) {
    for (int i = 0; i < m.size; i++) {
        free(m.matrix[i]);
    }
    free(m.matrix);
}

long calculateSum(Matrix m) {
    long sum = 0;
    int n = m.size;

    for (int i = 0; i < n; i++) {
        sum += m.matrix[i][i]; // Primary diagonal
    }

    for (int i = 0; i < n; i++) {
        sum += m.matrix[n - i - 1][i]; // Secondary diagonal
    }

    for (int i = 0; i < n; i++) {
        sum += m.matrix[(n - 1) / 2][i]; // Middle row
    }

    for (int i = 0; i < n; i++) {
        sum += m.matrix[i][(n - 1) / 2]; // Middle column
    }

    return sum - m.matrix[(n - 1) / 2][(n - 1) / 2] * 3; // Adjust for center element
}

int main() {
    int n;
    scanf("%d", &n);
    Matrix m = readMatrix(n);
    long result = calculateSum(m);
    printf("%ld\n", result);
    freeMatrix(m);
    return 0;
}
