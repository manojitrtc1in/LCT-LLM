#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int val;
} modint;

modint modint_one() {
    modint result;
    result.val = 1;
    return result;
}

modint modint_init() {
    modint result;
    result.val = 0;
    return result;
}

modint modint_add(modint a, modint b) {
    modint result;
    result.val = (a.val + b.val) % 998244353;
    return result;
}

modint modint_sub(modint a, modint b) {
    modint result;
    result.val = (a.val - b.val + 998244353) % 998244353;
    return result;
}

modint modint_mul(modint a, modint b) {
    modint result;
    result.val = (a.val * b.val) % 998244353;
    return result;
}

modint modint_div(modint a, modint b) {
    modint result;
    result.val = (a.val / b.val) % 998244353;
    return result;
}

modint modint_inverse(modint a) {
    modint result;
    result.val = 1;
    int m = 998244353, u = 0, v = 1;
    while (a.val != 0) {
        int t = m / a.val;
        int r = m - t * a.val;
        int s = u - t * v;
        m = a.val;
        a.val = r;
        u = v;
        v = s;
    }
    if (u < 0) {
        u += 998244353;
    }
    result.val = u;
    return result;
}

modint modint_pow(modint a, int e) {
    modint result;
    result.val = 1;
    while (e > 0) {
        if (e % 2 == 1) {
            result = modint_mul(result, a);
        }
        a = modint_mul(a, a);
        e /= 2;
    }
    return result;
}

typedef struct {
    int n;
    int** tree;
    modint** dp;
} solver;

solver* solver_init(int n) {
    solver* s = (solver*)malloc(sizeof(solver));
    s->n = n;
    s->tree = (int**)malloc(n * sizeof(int*));
    s->dp = (modint**)malloc(n * sizeof(modint*));
    for (int i = 0; i < n; i++) {
        s->tree[i] = (int*)malloc(n * sizeof(int));
        s->dp[i] = (modint*)malloc(3 * sizeof(modint));
        for (int j = 0; j < 3; j++) {
            s->dp[i][j] = modint_init();
        }
    }
    return s;
}

void solver_free(solver* s) {
    for (int i = 0; i < s->n; i++) {
        free(s->tree[i]);
        free(s->dp[i]);
    }
    free(s->tree);
    free(s->dp);
    free(s);
}

void solver_treedp(solver* s, int now, int pre) {
    modint* ndp = s->dp[now];
    ndp[2] = modint_one();
    for (int i = 0; i < s->n; i++) {
        int to = s->tree[now][i];
        if (to == pre) {
            continue;
        }
        modint* tdp = s->dp[to];

        modint tmp[3];
        for (int j = 0; j < 3; j++) {
            tmp[j] = modint_mul(tdp[2], ndp[j]);
        }

        tmp[0] = modint_add(tmp[0], modint_mul(ndp[2], tdp[2]));
        tmp[0] = modint_add(tmp[0], modint_mul(ndp[1], tdp[2]));

        tmp[0] = modint_add(tmp[0], modint_mul(modint_add(ndp[1], ndp[2]), tdp[1]));

        tmp[0] = modint_add(tmp[0], modint_mul(modint_mul(modint_init(2), ndp[0]), tdp[0]));
        tmp[1] = modint_add(tmp[1], modint_mul(modint_add(modint_mul(modint_init(2), ndp[1]), ndp[2]), tdp[0]));
        tmp[2] = modint_add(tmp[2], modint_mul(ndp[2], tdp[0]));

        for (int j = 0; j < 3; j++) {
            ndp[j] = tmp[j];
        }
    }
}

void solver_solve(solver* s) {
    solver_treedp(s, 0, -1);
    modint* rdp = s->dp[0];
    printf("%d\n", modint_add(rdp[0], rdp[2]).val);
}

int main() {
    int n = 0;
    scanf("%d", &n);
    solver* s = solver_init(n);
    for (int i = 1; i < n; i++) {
        int a = 0, b = 0;
        scanf("%d %d", &a, &b);
        s->tree[a - 1][b - 1] = 1;
        s->tree[b - 1][a - 1] = 1;
    }
    solver_solve(s);
    solver_free(s);
    return 0;
}
