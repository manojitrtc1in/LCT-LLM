#include <stdio.h>
#include <stdlib.h>

typedef long long int64;

const int mod = 998244353;

const int64 infll = (1LL << 62) - 1;
const int inf = (1 << 30) - 1;

typedef struct {
    int right, type;
} Node;

typedef struct {
    int num, dom;
} fraction;

typedef struct {
    int x;
} modint;

typedef struct {
    int A[4][4];
} Matrix;

void fraction_init(fraction* f, int n, int d) {
    f->num = n;
    f->dom = d;
}

fraction fraction_add(fraction a, fraction b) {
    fraction res;
    res.num = a.num * b.dom + b.num * a.dom;
    res.dom = a.dom * b.dom;
    return res;
}

fraction fraction_subtract(fraction a, fraction b) {
    fraction res;
    res.num = a.num * b.dom - b.num * a.dom;
    res.dom = a.dom * b.dom;
    return res;
}

fraction fraction_multiply(fraction a, fraction b) {
    fraction res;
    res.num = a.num * b.num;
    res.dom = a.dom * b.dom;
    return res;
}

fraction fraction_divide(fraction a, fraction b) {
    fraction res;
    res.num = a.num * b.dom;
    res.dom = a.dom * b.num;
    return res;
}

fraction fraction_multiply_int(fraction f, int k) {
    fraction res;
    res.num = f.num * k;
    res.dom = f.dom;
    return res;
}

fraction fraction_divide_int(fraction f, int k) {
    fraction res;
    res.num = f.num;
    res.dom = f.dom * k;
    return res;
}

int fraction_compare(fraction a, fraction b) {
    return a.num * b.dom - b.num * a.dom;
}

int fraction_equal(fraction a, fraction b) {
    return a.num * b.dom == b.num * a.dom;
}

int fraction_not_equal(fraction a, fraction b) {
    return a.num * b.dom != b.num * a.dom;
}

int fraction_less_than(fraction a, fraction b) {
    return a.num * b.dom < b.num * a.dom;
}

int fraction_greater_than(fraction a, fraction b) {
    return a.num * b.dom > b.num * a.dom;
}

int fraction_less_than_or_equal(fraction a, fraction b) {
    return a.num * b.dom <= b.num * a.dom;
}

int fraction_greater_than_or_equal(fraction a, fraction b) {
    return a.num * b.dom >= b.num * a.dom;
}

void modint_init(modint* m, int x) {
    m->x = x;
}

modint modint_add(modint a, modint b) {
    modint res;
    res.x = (a.x + b.x) % mod;
    return res;
}

modint modint_subtract(modint a, modint b) {
    modint res;
    res.x = (a.x - b.x + mod) % mod;
    return res;
}

modint modint_multiply(modint a, modint b) {
    modint res;
    res.x = (int64)a.x * b.x % mod;
    return res;
}

modint modint_divide(modint a, modint b) {
    modint res;
    res.x = (int64)a.x * b.x % mod;
    return res;
}

modint modint_pow(modint a, int64 n) {
    modint res;
    res.x = 1;
    while (n > 0) {
        if (n & 1) {
            res = modint_multiply(res, a);
        }
        a = modint_multiply(a, a);
        n >>= 1;
    }
    return res;
}

void matrix_init(Matrix* mat, int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            mat->A[i][j] = 0;
        }
    }
}

void matrix_identity(Matrix* mat, int n) {
    int i;
    matrix_init(mat, n);
    for (i = 0; i < n; i++) {
        mat->A[i][i] = 1;
    }
}

Matrix matrix_multiply(Matrix a, Matrix b, int n) {
    Matrix res;
    int i, j, k;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            res.A[i][j] = 0;
            for (k = 0; k < n; k++) {
                res.A[i][j] = (res.A[i][j] + a.A[i][k] * b.A[k][j]) % mod;
            }
        }
    }
    return res;
}

Matrix matrix_pow(Matrix a, int64 n, int m) {
    Matrix res;
    matrix_identity(&res, m);
    while (n > 0) {
        if (n & 1) {
            res = matrix_multiply(res, a, m);
        }
        a = matrix_multiply(a, a, m);
        n >>= 1;
    }
    return res;
}

void matrix_print(Matrix mat, int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        printf("[");
        for (j = 0; j < n; j++) {
            printf("%d", mat.A[i][j]);
            if (j + 1 != n) {
                printf(" ");
            }
        }
        printf("]\n");
    }
}

int main() {
    int N;
    scanf("%d", &N);
    int* X = (int*)malloc(N * sizeof(int));
    int* V = (int*)malloc(N * sizeof(int));
    modint* P = (modint*)malloc(N * sizeof(modint));
    modint* Q = (modint*)malloc(N * sizeof(modint));
    int i;
    for (i = 0; i < N; i++) {
        scanf("%d %d %d", &X[i], &V[i], &P[i].x);
        P[i].x /= 100;
        Q[i].x = 1 - P[i].x;
    }

    fraction* ev = (fraction*)malloc(N * sizeof(fraction));
    int ev_size = 0;
    for (i = 1; i < N; i++) {
        if (V[i - 1] < V[i]) {
            fraction f;
            fraction_init(&f, X[i - 1] - X[i], V[i - 1] - V[i]);
            ev[ev_size].num = f.num;
            ev[ev_size].dom = f.dom;
            ev_size++;
        }
        fraction f;
        fraction_init(&f, X[i] - X[i - 1], V[i - 1] + V[i]);
        ev[ev_size].num = f.num;
        ev[ev_size].dom = f.dom;
        ev_size++;
        if (V[i - 1] > V[i]) {
            fraction f;
            fraction_init(&f, X[i - 1] - X[i], V[i] - V[i - 1]);
            ev[ev_size].num = f.num;
            ev[ev_size].dom = f.dom;
            ev_size++;
        }
    }

    Matrix e;
    matrix_identity(&e, 4);

    Matrix* seg = (Matrix*)malloc(N * sizeof(Matrix));
    for (i = 0; i < N; i++) {
        Matrix u;
        matrix_init(&u, 4);
        u.A[0][0] = Q[i].x;
        u.A[1][0] = Q[i].x;
        u.A[2][2] = Q[i].x;
        u.A[3][2] = Q[i].x;
        u.A[0][1] = P[i].x;
        u.A[1][1] = P[i].x;
        u.A[2][3] = P[i].x;
        u.A[3][3] = P[i].x;
        seg[i] = u;
    }

    modint ret;
    modint_init(&ret, 0);

    for (i = 0; i < ev_size; i++) {
        fraction f = ev[i];
        int j;
        for (j = 0; j < N; j++) {
            Matrix now = seg[j];
            if (f.num == 0) {
                now.A[0][0] = 0;
                now.A[0][2] = Q[j].x;
            }
            else if (f.num == 1) {
                now.A[1][1] = 0;
                now.A[1][3] = P[j].x;
            }
            else {
                now.A[1][0] = 0;
                now.A[1][2] = Q[j].x;
            }
            seg[j] = now;
        }

        Matrix uku = matrix_pow(seg[0], f.num, 4);
        modint sum = modint_add(uku.A[0][2], uku.A[0][3]);
        ret = modint_add(ret, modint_divide_int(sum, f.dom));

        for (j = 0; j < N; j++) {
            Matrix now = seg[j];
            if (f.num == 0) {
                now.A[0][2] = 0;
                now.A[2][2] = 0;
            }
            else if (f.num == 1) {
                now.A[1][3] = 0;
                now.A[3][3] = 0;
            }
            else {
                now.A[1][2] = 0;
                now.A[3][2] = 0;
            }
            seg[j] = now;
        }
    }

    printf("%d\n", ret.x);

    free(X);
    free(V);
    free(P);
    free(Q);
    free(ev);
    free(seg);

    return 0;
}
