#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <assert.h>
#include <string.h>

#define MOD 998244353
#define MAX_N 100000

typedef long long int64;
typedef struct {
    int64 num, dom;
} fraction;

typedef struct {
    int x;
} ModInt;

typedef struct {
    ModInt A[4][4];
} Matrix;

typedef struct {
    int right, type;
} Node;

typedef struct {
    Node nodes[MAX_N];
    int size;
} EventMap;

ModInt modint(int64 y) {
    ModInt res;
    res.x = (y >= 0 ? y % MOD : (MOD - (-y) % MOD) % MOD);
    return res;
}

ModInt modint_add(ModInt a, ModInt b) {
    a.x += b.x;
    if (a.x >= MOD) a.x -= MOD;
    return a;
}

ModInt modint_sub(ModInt a, ModInt b) {
    a.x += MOD - b.x;
    if (a.x >= MOD) a.x -= MOD;
    return a;
}

ModInt modint_mul(ModInt a, ModInt b) {
    unsigned long long x = (unsigned long long) a.x * b.x;
    return modint(x % MOD);
}

ModInt modint_div(ModInt a, ModInt b) {
    // Implement modular inverse here
    // For simplicity, we assume b is not zero
    return modint_mul(a, modint_inverse(b));
}

ModInt modint_inverse(ModInt a) {
    int a_val = a.x, b = MOD, u = 1, v = 0, t;
    while (b > 0) {
        t = a_val / b;
        int temp = a_val; a_val -= t * b; b = temp;
        temp = u; u -= t * v; v = temp;
    }
    return modint(u);
}

Matrix matrix_identity() {
    Matrix mat = {0};
    for (int i = 0; i < 4; i++) {
        mat.A[i][i].x = 1;
    }
    return mat;
}

Matrix matrix_multiply(Matrix a, Matrix b) {
    Matrix res = {0};
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                res.A[i][j] = modint_add(res.A[i][j], modint_mul(a.A[i][k], b.A[k][j]));
            }
        }
    }
    return res;
}

void event_map_insert(EventMap *ev, fraction key, Node node) {
    // Implement insertion logic for event map
}

int main() {
    int N;
    scanf("%d", &N);
    int X[MAX_N], V[MAX_N];
    ModInt P[MAX_N], Q[MAX_N];

    for (int i = 0; i < N; i++) {
        scanf("%d %d", &X[i], &V[i]);
        scanf("%lld", &P[i].x);
        P[i] = modint_div(P[i], modint(100));
        Q[i] = modint_sub(modint(1), P[i]);
    }

    EventMap ev = {0};

    for (int i = 1; i < N; i++) {
        if (V[i - 1] < V[i]) {
            fraction key = {X[i - 1] - X[i], V[i - 1] - V[i]};
            event_map_insert(&ev, key, (Node){i, 0});
        }

        fraction key = {X[i] - X[i - 1], V[i - 1] + V[i]};
        event_map_insert(&ev, key, (Node){i, 2});

        if (V[i - 1] > V[i]) {
            fraction key = {X[i - 1] - X[i], V[i] - V[i - 1]};
            event_map_insert(&ev, key, (Node){i, 1});
        }
    }

    Matrix seg[MAX_N];
    for (int i = 0; i < N; i++) {
        Matrix u = matrix_identity();
        u.A[0][0] = Q[i];
        u.A[1][0] = Q[i];
        u.A[2][2] = Q[i];
        u.A[3][2] = Q[i];
        u.A[0][1] = P[i];
        u.A[1][1] = P[i];
        u.A[2][3] = P[i];
        u.A[3][3] = P[i];
        seg[i] = u;
    }

    ModInt ret = {0};

    // Process events
    for (int i = 0; i < ev.size; i++) {
        Node tt = ev.nodes[i];
        Matrix now = seg[tt.right];
        if (tt.type == 0) {
            now.A[0][0] = modint(0);
            now.A[0][2] = Q[tt.right];
        } else if (tt.type == 1) {
            now.A[1][1] = modint(0);
            now.A[1][3] = P[tt.right];
        } else {
            now.A[1][0] = modint(0);
            now.A[1][2] = Q[tt.right];
        }
        seg[tt.right] = now;
    }

    // Final calculation
    for (int i = 0; i < ev.size; i++) {
        Node tt = ev.nodes[i];
        Matrix now = seg[tt.right];
        if (tt.type == 0) {
            now.A[0][2] = modint(0);
            now.A[2][2] = modint(0);
        } else if (tt.type == 1) {
            now.A[1][3] = modint(0);
            now.A[3][3] = modint(0);
        } else {
            now.A[1][2] = modint(0);
            now.A[3][2] = modint(0);
        }
        seg[tt.right] = now;
    }

    printf("%lld\n", ret.x);
    return 0;
}
