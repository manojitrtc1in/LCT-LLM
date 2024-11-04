#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>
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
} InputData;

typedef struct {
    Mat a[2 * (MAX_N - 1) - 1];
    Mat id2[MAX_N - 1];
} MatrixData;

double mod_inv(int a, int m) {
    int u = 0, v = 1;
    while (a != 0) {
        int t = m / a;
        m -= t * a;
        int temp = a; a = m; m = temp;
        u -= t * v;
        temp = u; u = v; v = temp;
    }
    assert(m == 1);
    return u < 0 ? u + MOD : u;
}

void init_matrix(MatrixData *data, int n) {
    for (int i = 0; i < n - 1; i++) {
        data->id2[i].m[0][1] = (int)(data->p[i + 1] * MOD);
    }
}

Mat mat_mult(Mat a, Mat b) {
    Mat c = {0};
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                c.m[i][j] += a.m[i][k] * b.m[k][j];
            }
        }
    }
    return c;
}

void build(MatrixData *data, int l, int r, int n) {
    if (l == r) {
        data->a[2 * l] = data->id2[l];
        return;
    }
    int mid = (l + r) / 2;
    build(data, l, mid, n);
    build(data, mid + 1, r, n);
    data->a[(l + r) | (l != r)] = mat_mult(data->a[(l + mid)], data->a[(mid + 1 + r)]);
}

void modify(MatrixData *data, int l, int r, int k, int n) {
    if (l == r) {
        data->a[2 * l] = data->id2[k];
        return;
    }
    int mid = (l + r) / 2;
    if (k <= mid) {
        modify(data, l, mid, k, n);
    } else {
        modify(data, mid + 1, r, k, n);
    }
    data->a[(l + r) | (l != r)] = mat_mult(data->a[(l + mid)], data->a[(mid + 1 + r)]);
}

double get_prob(MatrixData *data, double to_right, int n) {
    return to_right * (data->a[1].m[0][0] + data->a[1].m[0][1]) + 
           (1 - to_right) * (data->a[0].m[0][0] + data->a[0].m[0][1]);
}

int main() {
    InputData input;
    MatrixData data;
    int n;

    FILE *in = fopen("in.txt", "r");
    fscanf(in, "%d", &n);
    if (n == 1) {
        printf("0\n");
        return 0;
    }

    for (int i = 0; i < n; i++) {
        fscanf(in, "%d %d %lf", &input.x[i], &input.v[i], &input.p[i]);
        input.p[i] /= 100.0;
    }
    fclose(in);

    init_matrix(&data, n);
    build(&data, 0, n - 2, n);

    double prev_prob = get_prob(&data, input.p[0], n);
    double ans = 0;

    // Event processing and probability calculation would go here

    printf("%lf\n", ans);
    return 0;
}
