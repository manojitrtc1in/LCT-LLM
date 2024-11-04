#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#define MOD 998244353

typedef struct {
    int val;
} modint;

modint create_modint(int _val) {
    modint m;
    m.val = (_val % MOD + MOD) % MOD;
    return m;
}

modint modint_add(modint a, modint b) {
    return create_modint(a.val + b.val);
}

modint modint_mul(modint a, modint b) {
    return create_modint((int64_t)a.val * b.val % MOD);
}

modint modint_zero() {
    return create_modint(0);
}

modint modint_one() {
    return create_modint(1);
}

typedef struct {
    int n;
    int **tree;
    modint **dp;
} Solver;

bool is_leaf(Solver *solver, int v) {
    return solver->tree[v][0] == -1;
}

void treedp(Solver *solver, int now, int pre) {
    modint *ndp = solver->dp[now];
    ndp[2] = modint_one();
    
    for (int i = 0; solver->tree[now][i] != -1; i++) {
        int to = solver->tree[now][i];
        if (to == pre) continue;

        treedp(solver, to, now);
        modint *tdp = solver->dp[to];
        modint tmp[3] = {modint_zero(), modint_zero(), modint_zero()};

        for (int j = 0; j < 3; j++) {
            tmp[j] = modint_mul(tdp[2], ndp[j]);
        }

        tmp[0] = modint_add(tmp[0], modint_add(modint_mul(ndp[2], tdp[2]), modint_mul(ndp[1], tdp[2])));
        tmp[0] = modint_add(tmp[0], modint_mul(modint_add(ndp[1], ndp[2]), tdp[1]));
        tmp[0] = modint_add(tmp[0], modint_mul(modint_create(2), modint_mul(ndp[0], tdp[0])));
        tmp[1] = modint_add(tmp[1], modint_mul(modint_add(modint_mul(ndp[1], modint_create(2)), ndp[2]), tdp[0]));
        tmp[2] = modint_add(tmp[2], modint_mul(ndp[2], tdp[0]));

        memcpy(ndp, tmp, sizeof(tmp));
    }
}

void solver_run(Solver *solver) {
    scanf("%d", &solver->n);
    solver->tree = malloc(solver->n * sizeof(int *));
    solver->dp = malloc(solver->n * sizeof(modint *));
    
    for (int i = 0; i < solver->n; i++) {
        solver->tree[i] = malloc((solver->n + 1) * sizeof(int));
        solver->dp[i] = malloc(3 * sizeof(modint));
        memset(solver->tree[i], -1, (solver->n + 1) * sizeof(int));
    }

    for (int i = 1; i < solver->n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--, b--;
        solver->tree[a][i] = b;
        solver->tree[b][i] = a;
    }

    treedp(solver, 0, -1);
    modint *rdp = solver->dp[0];
    printf("%d\n", (rdp[0].val + rdp[2].val) % MOD);
}

int main() {
    Solver solver;
    solver_run(&solver);

    for (int i = 0; i < solver.n; i++) {
        free(solver.tree[i]);
        free(solver.dp[i]);
    }
    free(solver.tree);
    free(solver.dp);
    
    return 0;
}
