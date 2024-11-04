#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define MAX_SIZE 1024

typedef struct {
    int *data;
    int size;
} IntArrayList;

typedef struct {
    long **data;
    int size;
} LongMatrix;

void fill(LongMatrix *matrix, long value) {
    for (int i = 0; i < matrix->size; i++) {
        for (int j = 0; j < matrix->size; j++) {
            matrix->data[i][j] = value;
        }
    }
}

void makeOne(LongMatrix *current) {
    fill(current, LONG_MAX);
    for (int i = 0; i < current->size; i++) {
        current->data[i][i] = 0;
    }
}

void multiply(LongMatrix *c, LongMatrix *a, LongMatrix *b) {
    for (int i = 0; i < c->size; i++) {
        for (int j = 0; j < c->size; j++) {
            c->data[i][j] = LONG_MAX;
            for (int k = 0; k < c->size; k++) {
                if (a->data[i][k] != LONG_MAX && b->data[k][j] != LONG_MAX) {
                    c->data[i][j] = fmin(c->data[i][j], a->data[i][k] + b->data[k][j]);
                }
            }
        }
    }
}

void power(LongMatrix *base, int exponent, LongMatrix *result, LongMatrix *temp) {
    if (exponent == 0) {
        makeOne(result);
        return;
    }
    if ((exponent & 1) == 0) {
        power(base, exponent >> 1, temp, result);
        multiply(result, temp, temp);
    } else {
        power(base, exponent - 1, temp, result);
        multiply(result, temp, base);
    }
}

void solve(int x, int k, int n, int q, int *c, int *p, int *w) {
    int size = 0;
    int *id = (int *)malloc((1 << k) * sizeof(int));
    int *byId = (int *)malloc((1 << k) * sizeof(int));
    LongMatrix baseMat;
    LongMatrix specMat;
    baseMat.size = size;
    baseMat.data = (long **)malloc(size * sizeof(long *));
    for (int i = 0; i < size; i++) {
        baseMat.data[i] = (long *)malloc(size * sizeof(long));
    }
    fill(&baseMat, LONG_MAX);
    
    specMat.size = q;
    specMat.data = (long ***)malloc(q * sizeof(long **));
    for (int i = 0; i < q; i++) {
        specMat.data[i] = (long **)malloc(size * sizeof(long *));
        for (int j = 0; j < size; j++) {
            specMat.data[i][j] = (long *)malloc(size * sizeof(long));
        }
        fill(&specMat.data[i], LONG_MAX);
    }

    for (int i = 0; i < (1 << k); i++) {
        if (__builtin_popcount(i) == x) {
            id[i] = size;
            byId[size++] = i;
        }
    }

    // Initialize baseMat and specMat
    for (int i = 0; i < size; i++) {
        int ii = byId[i];
        if ((ii & 1) == 0) {
            baseMat.data[id[ii]][id[ii >> 1]] = 0;
            for (int j = 0; j < q; j++) {
                specMat.data[j][id[ii]][id[ii >> 1]] = 0;
            }
        } else {
            int ni = ii >> 1;
            for (int j = 0; j < k; j++) {
                if ((ni >> j & 1) == 0) {
                    baseMat.data[id[ii]][id[ni + (1 << j)]] = c[j];
                    for (int l = 0; l < q; l++) {
                        specMat.data[l][id[ii]][id[ni + (1 << j)]] = c[j] + w[l];
                    }
                }
            }
        }
    }

    LongMatrix current;
    current.size = size;
    current.data = (long **)malloc(size * sizeof(long *));
    for (int i = 0; i < size; i++) {
        current.data[i] = (long *)malloc(size * sizeof(long));
    }
    makeOne(&current);

    LongMatrix temp;
    temp.size = size;
    temp.data = (long **)malloc(size * sizeof(long *));
    for (int i = 0; i < size; i++) {
        temp.data[i] = (long *)malloc(size * sizeof(long));
    }

    LongMatrix temp1;
    temp1.size = size;
    temp1.data = (long **)malloc(size * sizeof(long *));
    for (int i = 0; i < size; i++) {
        temp1.data[i] = (long *)malloc(size * sizeof(long));
    }

    LongMatrix temp2;
    temp2.size = size;
    temp2.data = (long **)malloc(size * sizeof(long *));
    for (int i = 0; i < size; i++) {
        temp2.data[i] = (long *)malloc(size * sizeof(long));
    }

    int start = 0;
    long answer = 0;

    for (int i = 0; i <= q; i++) {
        int stop = n - x;
        if (i < q) {
            stop = fmin(stop, p[i]);
        }
        power(&baseMat, stop - start, &temp1, &temp2);
        multiply(&temp, &current, &temp1);
        if (stop == n - x) {
            current = temp;
            break;
        } else {
            multiply(&current, &temp, specMat.data[i]);
            start = stop + 1;
        }
    }

    answer = current.data[id[(1 << x) - 1]][id[(1 << x) - 1]];
    for (int i = 0; i < q; i++) {
        if (p[i] >= n - x) {
            answer += w[i];
        }
    }

    printf("%ld\n", answer);

    // Free allocated memory
    free(id);
    free(byId);
    for (int i = 0; i < size; i++) {
        free(baseMat.data[i]);
        free(current.data[i]);
        free(temp.data[i]);
        free(temp1.data[i]);
        free(temp2.data[i]);
    }
    free(baseMat.data);
    free(current.data);
    free(temp.data);
    free(temp1.data);
    free(temp2.data);
    for (int i = 0; i < q; i++) {
        for (int j = 0; j < size; j++) {
            free(specMat.data[i][j]);
        }
        free(specMat.data[i]);
    }
    free(specMat.data);
}

int main() {
    int x, k, n, q;
    scanf("%d %d %d %d", &x, &k, &n, &q);
    int *c = (int *)malloc(k * sizeof(int));
    int *p = (int *)malloc(q * sizeof(int));
    int *w = (int *)malloc(q * sizeof(int));

    for (int i = 0; i < k; i++) {
        scanf("%d", &c[i]);
    }
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &p[i], &w[i]);
    }

    solve(x, k, n, q, c, p, w);

    free(c);
    free(p);
    free(w);
    return 0;
}
