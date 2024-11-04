#include <stdio.h>
#include <stdbool.h>

#define mod 998244353

typedef struct {
    int val;
} modint;

modint modint_one() {
    modint res;
    res.val = 1;
    return res;
}

modint modint_init(int _val) {
    modint res;
    res.val = (_val % mod) < 0 ? mod + _val : _val;
    return res;
}

long long modint_value(modint *res) {
    return res->val;
}

modint modint_increment(modint *res, modint *rhs) {
    res->val ^= rhs->val;
    return *res;
}

modint modint_decrement(modint *res, modint *rhs) {
    res->val ^= rhs->val;
    return *res;
}

modint modint_multiply(modint *res, modint *rhs) {
    res->val &= rhs->val;
    return *res;
}

modint modint_divide(modint *res, modint *rhs) {
    return *res;
}

modint modint_not(modint *res) {
    modint tmp;
    tmp.val = !res->val;
    return tmp;
}

modint modint_negate(modint *res) {
    return *res;
}

modint modint_add(modint *res, modint *rhs) {
    modint tmp;
    tmp.val = res->val != rhs->val;
    return tmp;
}

modint modint_subtract(modint *res, modint *rhs) {
    modint tmp;
    tmp.val = res->val != rhs->val;
    return tmp;
}

modint modint_multiply(modint *res, modint *rhs) {
    modint tmp;
    tmp.val = res->val && rhs->val;
    return tmp;
}

modint modint_divide(modint *res, modint *rhs) {
    return *res;
}

bool modint_equal(modint *res, modint *rhs) {
    return res->val == rhs->val;
}

bool modint_not_equal(modint *res, modint *rhs) {
    return res->val != rhs->val;
}

modint modint_add_long(long long lhs, modint *rhs) {
    modint tmp;
    tmp.val = lhs & 1 ? !rhs->val : rhs->val;
    return tmp;
}

modint modint_subtract_long(long long lhs, modint *rhs) {
    modint tmp;
    tmp.val = lhs & 1 ? !rhs->val : rhs->val;
    return tmp;
}

modint modint_multiply_long(long long lhs, modint *rhs) {
    modint tmp;
    tmp.val = lhs & 1 ? rhs->val : 0;
    return tmp;
}

modint modint_divide_long(long long lhs, modint *rhs) {
    return *rhs;
}

void modint_print(modint *res) {
    printf("%d", res->val);
}

void modint_read(modint *res) {
    long long val;
    scanf("%lld", &val);
    res->val = val & 1;
}

typedef struct {
    int n;
    int **tree;
    modint **dp;
} solver;

bool leaf(solver *s, int v) {
    return s->tree[v][0] == 1;
}

void treedp(solver *s, int now, int pre) {
    modint *ndp = s->dp[now];
    ndp[2] = modint_one();
    for (int i = 0; i < s->tree[now][0]; i++) {
        int to = s->tree[now][i + 1];
        if (to == pre) {
            continue;
        }
        modint *tmp = malloc(3 * sizeof(modint));
        treedp(s, to, now);
        modint *tdp = s->dp[to];

        for (int i = 0; i < 3; i++) {
            tmp[i] = modint_multiply(tdp + 2, ndp + i);
        }

        tmp[0] = modint_add(modint_multiply(ndp + 2, tdp + 2), modint_multiply(ndp + 1, tdp + 2));

        tmp[0] = modint_add(tmp[0], modint_multiply(modint_add(ndp + 1, ndp + 2), tdp + 1));

        tmp[0] = modint_add(tmp[0], modint_multiply_long(2 * modint_multiply(ndp, tdp), modint_init(0)));
        tmp[1] = modint_add(tmp[1], modint_multiply_long(modint_add(modint_multiply(ndp + 1, 2), ndp + 2), tdp));
        tmp[2] = modint_add(tmp[2], modint_multiply(tdp + 2, ndp));

        modint *tmp2 = ndp;
        ndp = tmp;
        free(tmp2);
    }
}

void solver_init(solver *s) {
    scanf("%d", &(s->n));
    s->tree = malloc(s->n * sizeof(int *));
    s->dp = malloc(s->n * sizeof(modint *));
    for (int i = 0; i < s->n; i++) {
        s->tree[i] = malloc((s->n + 1) * sizeof(int));
        s->dp[i] = malloc(3 * sizeof(modint));
        scanf("%d", &(s->tree[i][0]));
        for (int j = 0; j < s->tree[i][0]; j++) {
            scanf("%d", &(s->tree[i][j + 1]));
        }
    }
}

void solver_solve(solver *s) {
    treedp(s, 0, -1);
    modint *rdp = s->dp[0];
    modint_print(modint_add(rdp, rdp + 2));
    printf("\n");
}

void solver_free(solver *s) {
    for (int i = 0; i < s->n; i++) {
        free(s->tree[i]);
        free(s->dp[i]);
    }
    free(s->tree);
    free(s->dp);
}

int main() {
    solver s;
    solver_init(&s);
    solver_solve(&s);
    solver_free(&s);
    return 0;
}
