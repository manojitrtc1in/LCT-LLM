#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#define MOD 998244353
#define MAX_N 100000

typedef struct {
    int64_t val;
} modint;

modint modint_init(int64_t _val) {
    modint m;
    m.val = (_val % MOD + MOD) % MOD;
    return m;
}

modint modint_add(modint a, modint b) {
    return modint_init(a.val + b.val);
}

modint modint_mul(modint a, modint b) {
    return modint_init(a.val * b.val);
}

modint modint_pow(modint base, int64_t exp) {
    modint result = modint_init(1);
    while (exp) {
        if (exp & 1) result = modint_mul(result, base);
        base = modint_mul(base, base);
        exp >>= 1;
    }
    return result;
}

typedef struct {
    int *edges[MAX_N];
    int size[MAX_N];
    int n;
} Tree;

Tree tree;

modint dp[MAX_N][3];

void init_tree(int n) {
    tree.n = n;
    for (int i = 0; i < n; i++) {
        tree.size[i] = 0;
    }
}

void add_edge(int a, int b) {
    tree.edges[a][tree.size[a]++] = b;
    tree.edges[b][tree.size[b]++] = a;
}

bool is_leaf(int v) {
    return tree.size[v] == 1;
}

void treedp(int now, int pre) {
    dp[now][2] = modint_init(1).val;
    for (int i = 0; i < tree.size[now]; i++) {
        int to = tree.edges[now][i];
        if (to == pre) continue;

        treedp(to, now);
        modint tmp[3] = {0};

        for (int j = 0; j < 3; j++) {
            tmp[j] = modint_mul(dp[to][2], dp[now][j]);
        }

        tmp[0] = modint_add(tmp[0], modint_add(modint_mul(dp[now][2], dp[to][2]), modint_mul(dp[now][1], dp[to][2])));
        tmp[0] = modint_add(tmp[0], modint_mul(modint_add(dp[now][1], dp[now][2]), dp[to][1]));
        tmp[0] = modint_add(tmp[0], modint_mul(modint_init(2), modint_mul(dp[now][0], dp[to][0])));
        tmp[1] = modint_add(tmp[1], modint_mul(modint_add(modint_mul(dp[now][1], modint_init(2)), dp[now][2]), dp[to][0]));
        tmp[2] = modint_add(tmp[2], modint_mul(dp[now][2], dp[to][0]));

        for (int j = 0; j < 3; j++) {
            dp[now][j] = tmp[j];
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    init_tree(n);
    
    for (int i = 1; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;
        add_edge(a, b);
    }

    treedp(0, -1);
    modint result = modint_add(dp[0][0], dp[0][2]);
    printf("%lld\n", result.val);
    
    return 0;
}
