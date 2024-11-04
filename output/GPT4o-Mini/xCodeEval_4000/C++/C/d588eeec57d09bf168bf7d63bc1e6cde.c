#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

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
Pair g[MAXN * 2][MAXN]; // Adjacency list
int g_size[MAXN * 2]; // Size of each adjacency list
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
    
    int trans[2][MAXN]; // Transformation map
    int trans_size[2] = {0}; // Size of each transformation map

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &pts[i][0], &pts[i][1]);
        for (int j = 0; j < 2; j++) {
            bool found = false;
            for (int k = 0; k < trans_size[j]; k++) {
                if (trans[j][k] == pts[i][j]) {
                    pts[i][j] = k;
                    found = true;
                    break;
                }
            }
            if (!found) {
                trans[j][trans_size[j]] = pts[i][j];
                pts[i][j] = trans_size[j]++;
            }
        }
    }

    x_start = now; now += trans_size[0];
    y_start = now; now += trans_size[1];

    for (int i = 0; i < n; i++) {
        int x = x_start + pts[i][0];
        int y = y_start + pts[i][1];
        g[x][g_size[x]++] = (Pair){y, i};
        g[y][g_size[y]++] = (Pair){x, i};
    }

    int ans = 1;
    for (int i = 0; i < now; i++) {
        if (!visit[i]) {
            Pair p = dfs(i);
            int k = p.first;
            if (p.second < p.first) {
                ans = mul_mod(ans, pow_mod(2, k, MOD) - 1, MOD);
            } else {
                ans = mul_mod(ans, pow_mod(2, k, MOD), MOD);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
