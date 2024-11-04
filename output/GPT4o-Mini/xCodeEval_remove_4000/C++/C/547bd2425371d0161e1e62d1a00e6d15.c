#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <math.h>
#include <string.h>

#define MOD 998244353
#define MAX_N 100005

typedef long long int64;
typedef struct {
    int64 num, dom;
} fraction;

typedef struct {
    int right, type;
} Node;

typedef struct {
    int64 A[4][4];
} Matrix;

typedef struct {
    Matrix seg[2 * MAX_N];
    int sz;
} SegmentTree;

fraction create_fraction(int64 n, int64 d) {
    assert(d != 0);
    if (d < 0) {
        n *= -1;
        d *= -1;
    }
    int64 gcd = __gcd(abs(n), abs(d));
    return (fraction){n / gcd, d / gcd};
}

Matrix identity_matrix() {
    Matrix mat = {0};
    for (int i = 0; i < 4; i++) {
        mat.A[i][i] = 1;
    }
    return mat;
}

Matrix matrix_multiply(Matrix a, Matrix b) {
    Matrix c = {0};
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                c.A[i][j] = (c.A[i][j] + a.A[i][k] * b.A[k][j]) % MOD;
            }
        }
    }
    return c;
}

void segment_tree_init(SegmentTree *seg, int n) {
    seg->sz = 1;
    while (seg->sz < n) seg->sz <<= 1;
    memset(seg->seg, 0, sizeof(seg->seg));
}

void segment_tree_set(SegmentTree *seg, int k, Matrix x) {
    seg->seg[k + seg->sz] = x;
}

void segment_tree_build(SegmentTree *seg) {
    for (int k = seg->sz - 1; k > 0; k--) {
        seg->seg[k] = matrix_multiply(seg->seg[2 * k], seg->seg[2 * k + 1]);
    }
}

Matrix segment_tree_query(SegmentTree *seg, int a, int b) {
    Matrix L = {0}, R = {0};
    for (a += seg->sz, b += seg->sz; a < b; a >>= 1, b >>= 1) {
        if (a & 1) L = matrix_multiply(L, seg->seg[a++]);
        if (b & 1) R = matrix_multiply(seg->seg[--b], R);
    }
    return matrix_multiply(L, R);
}

int main() {
    int N;
    scanf("%d", &N);
    int X[MAX_N], V[MAX_N];
    fraction P[MAX_N], Q[MAX_N];
    
    for (int i = 0; i < N; i++) {
        scanf("%d %d %lld", &X[i], &V[i], &P[i].num);
        P[i].dom = 100;
        Q[i] = create_fraction(P[i].dom - P[i].num, P[i].dom);
    }

    Node events[MAX_N * 3];
    int event_count = 0;

    for (int i = 1; i < N; i++) {
        if (V[i - 1] < V[i]) {
            events[event_count++] = (Node){i, 0};
        }
        events[event_count++] = (Node){i, 2};
        if (V[i - 1] > V[i]) {
            events[event_count++] = (Node){i, 1};
        }
    }

    SegmentTree seg;
    segment_tree_init(&seg, N);
    Matrix e = identity_matrix();

    for (int i = 0; i < N; i++) {
        Matrix u = e;
        u.A[0][0] = Q[i].num;
        u.A[1][0] = Q[i].num;
        u.A[2][2] = Q[i].num;
        u.A[3][2] = Q[i].num;
        u.A[0][1] = P[i].num;
        u.A[1][1] = P[i].num;
        u.A[2][3] = P[i].num;
        u.A[3][3] = P[i].num;
        segment_tree_set(&seg, i, u);
    }
    segment_tree_build(&seg);

    int64 ret = 0;

    for (int i = 0; i < event_count; i++) {
        Node tt = events[i];
        Matrix now = seg.seg[tt.right + seg.sz];
        if (tt.type == 0) {
            now.A[0][0] = 0;
            now.A[0][2] = Q[tt.right].num;
        } else if (tt.type == 1) {
            now.A[1][1] = 0;
            now.A[1][3] = P[tt.right].num;
        } else {
            now.A[1][0] = 0;
            now.A[1][2] = Q[tt.right].num;
        }
        segment_tree_set(&seg, tt.right, now);
    }

    printf("%lld\n", ret);
    return 0;
}
