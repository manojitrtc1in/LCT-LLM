#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <limits.h>
#include <assert.h>
#include <string.h>

#define MAXN 100005
#define MOD 1000000007

typedef struct {
    int first;
    int second;
} Pair;

int n;
int pts[MAXN][2];
bool visit[MAXN * 2];
int g[MAXN * 2][MAXN * 2];
int g_size[MAXN * 2];

void dfs(int u, Pair *ret) {
    ret->first = 1;
    ret->second = g_size[u];
    visit[u] = true;
    for (int i = 0; i < g_size[u]; i++) {
        int v = g[u][i];
        if (!visit[v]) {
            Pair p;
            dfs(v, &p);
            ret->first += p.first;
            ret->second += p.second;
        }
    }
}

int gcd(int a, int b) {
    while (a != 0) {
        b %= a;
        if (b == 0)
            return a;
        a %= b;
    }
    return b;
}

int mul_mod(int a, int b, int m) {
    return (int)(((int64_t)a * b) % m);
}

int pow_mod(int a, int p, int m) {
    int r = 1;
    a %= m;
    while (p) {
        if (p & 1) r = mul_mod(r, a, m);
        a = mul_mod(a, a, m);
        p >>= 1;
    }
    return r;
}

int inv_mod(int a, int m) {
    int x, y;
    int g = gcd(a, m);
    assert(g == 1); // Ensure a and m are coprime
    if (g != 1) return -1; // No modular inverse exists
    // Extended Euclidean Algorithm to find x
    if (m == 0) {
        x = 1; y = 0;
        return a;
    }
    int g1 = inv_mod(m, a);
    x = (g1 - (a / m) * x) % a;
    return (x + a) % a;
}

int main() {
    scanf("%d", &n);
    
    int trans[2][MAXN * 2] = {0};
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &pts[i][0], &pts[i][1]);
        for (int j = 0; j < 2; j++) {
            if (trans[j][pts[i][j]] == 0) {
                trans[j][pts[i][j]] = ++cnt;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        int x = trans[0][pts[i][0]];
        int y = trans[1][pts[i][1]];
        g[x][g_size[x]++] = y;
        g[y][g_size[y]++] = x;
    }

    int ans = 1;

    for (int i = 0; i < cnt; i++) {
        if (!visit[i]) {
            Pair p;
            dfs(i, &p);
            int vers = p.first;
            int edgs = p.second / 2;
            if (edgs == vers - 1) {
                ans = mul_mod(ans, (pow_mod(2, vers, MOD) - 1 + MOD) % MOD, MOD);
            } else {
                ans = mul_mod(ans, pow_mod(2, vers, MOD), MOD);
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}
