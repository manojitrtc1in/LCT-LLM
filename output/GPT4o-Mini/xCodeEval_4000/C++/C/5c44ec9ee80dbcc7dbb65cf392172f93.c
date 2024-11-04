#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <limits.h>

#define MAXN 100005
#define MOD 1000000007

int n;
int pts[MAXN][2];
bool visit[MAXN * 2]; 
int g[MAXN * 2][MAXN * 2]; 
int g_size[MAXN * 2];

typedef struct {
    int first;
    int second;
} Pair;

Pair dfs(int u) { 
    Pair ret = {1, g_size[u]};
    visit[u] = true;
    for (int i = 0; i < g_size[u]; i++) {
        int v = g[u][i];
        if (!visit[v]) {
            Pair p = dfs(v);
            ret.first += p.first;
            ret.second += p.second;
        }
    }
    return ret;
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
    int g = extended_gcd(a, m, &x, &y);
    if (x < 0)
        return x + m;
    return x;
}

int extended_gcd(int a, int b, int *x, int *y) {
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }
    int g = extended_gcd(b, a % b, y, x);
    *y -= (a / b) * (*x);
    return g;
}

int main() {
    scanf("%d", &n);
    
    int trans[2][MAXN * 2] = {0};
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &pts[i][0], &pts[i][1]);
        trans[0][pts[i][0]] = 0;
        trans[1][pts[i][1]] = 0;
    }
    
    int cnt = 0;
    for (int j = 0; j < 2; j++) {
        for (int k = 0; k < MAXN * 2; k++) {
            if (trans[j][k]) {
                trans[j][k] = cnt++;
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
            Pair p = dfs(i);
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
