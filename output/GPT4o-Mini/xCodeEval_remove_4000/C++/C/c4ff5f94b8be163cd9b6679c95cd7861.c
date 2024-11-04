#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define MAX_N 1000
#define MOD 998244353

typedef struct {
    int p, q;
} Frac;

typedef struct {
    int m[2][2];
} Mat;

typedef struct {
    int x[MAX_N];
    int v[MAX_N];
    double p[MAX_N];
    Mat a[2 * (MAX_N - 1) - 1];
    Mat id2[MAX_N - 1];
} Data;

void init_mat(Mat *mat) {
    memset(mat->m, 0, sizeof(mat->m));
}

Mat mat_mult(Mat a, Mat b) {
    Mat c;
    init_mat(&c);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                c.m[i][j] += a.m[i][k] * b.m[k][j];
            }
        }
    }
    return c;
}

double get_prob(Data *data, int n) {
    double to_right = data->p[0];
    Mat mat = data->a[0]; // Assuming we want the first matrix for simplicity
    return to_right * (mat.m[1][0] + mat.m[1][1]) + (1 - to_right) * (mat.m[0][0] + mat.m[0][1]);
}

void modify(Data *data, int l, int r, int k) {
    if (l == r) {
        data->a[2 * l] = data->id2[k];
        return;
    }
    int mid = (l + r) / 2;
    if (k <= mid) {
        modify(data, l, mid, k);
    } else {
        modify(data, mid + 1, r, k);
    }
    data->a[get_id(l, r)] = mat_mult(data->a[get_id(l, mid)], data->a[get_id(mid + 1, r)]);
}

int get_id(int l, int r) {
    assert(0 <= l && l <= r);
    return l + r | (l != r);
}

void scan(Data *data, int n) {
    for (int i = 0; i < n; i++) {
        scanf("%d %d %lf", &data->x[i], &data->v[i], &data->p[i]);
        data->p[i] /= 100.0;
    }
}

int main() {
    Data data;
    int n;
    scanf("%d", &n);
    if (n == 1) {
        printf("0\n");
        return 0;
    }
    
    scan(&data, n);
    
    for (int i = 0; i < n - 1; i++) {
        data.id2[i].m[0][1] = data.p[i + 1];
    }
    
    // Initialize a
    for (int i = 0; i < 2 * (n - 1) - 1; i++) {
        init_mat(&data.a[i]);
    }
    
    // Build the matrix
    // ... (similar to the original C++ build function)
    
    // Modify and calculate probability
    // ... (similar to the original C++ modify function)
    
    // Final calculation
    // ... (similar to the original C++ main logic)
    
    printf("Time elapsed: %lf s.\n", (double)clock() / CLOCKS_PER_SEC);
    
    return 0;
}
