#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <stdint.h>
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
bool ve[MAXN * 2];
Pair g[MAXN * 2][MAXN];
int g_size[MAXN * 2];
int x_start, y_start, now = 0;

int gcd(int a, int b) {
    while (a != 0) {
        b %= a;
        if (b == 0)
            return a;
        a %= b;
    }
    return b;
}

int inv_mod(int a, int m) {
    int x, y;
    if (m == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int g = inv_mod(m, a % m);
    y -= (a / m) * x;
    return g;
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

Pair dfs(int u) {
    Pair ret = {1, 0};
    visit[u] = true;
    for (int i = 0; i < g_size[u]; i++) {
        Pair vv = g[u][i];
        if (ve[vv.second]) continue;
        ++ret.second;
        ve[vv.second] = true;
        if (visit[vv.first]) continue;
        Pair p = dfs(vv.first);
        ret.first += p.first;
        ret.second += p.second;
    }
    return ret;
}

int main() {
    scanf("%d", &n);
    
    int trans[2][MAXN] = {0};
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &pts[i][0], &pts[i][1]);
        for (int j = 0; j < 2; j++) {
            if (trans[j][pts[i][j]] == 0) {
                trans[j][pts[i][j]] = now + 1;
                now++;
            }
            pts[i][j] = trans[j][pts[i][j]] - 1;
        }
    }

    x_start = now; now += trans[0][0];
    y_start = now; now += trans[1][0];
    assert(now < MAXN * 2);

    for (int i = 0; i < n; i++) {
        int x = x_start + pts[i][0];
        int y = y_start + pts[i][1];
        g[x][g_size[x]].first = y;
        g[x][g_size[x]].second = i;
        g_size[x]++;
        g[y][g_size[y]].first = x;
        g[y][g_size[y]].second = i;
        g_size[y]++;
    }

    int ans = 1;
    for (int i = 0; i < now; i++) {
        if (!visit[i]) {
            Pair p = dfs(i);
            int k = p.first;
            if (p.second < p.first) {
                ans = mul_mod(ans, (pow_mod(2, k, MOD) - 1 + MOD) % MOD);
            } else {
                ans = mul_mod(ans, pow_mod(2, k, MOD));
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
