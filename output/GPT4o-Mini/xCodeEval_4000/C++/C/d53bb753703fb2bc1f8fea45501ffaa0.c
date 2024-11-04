#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>
#include <math.h>

#define C 20
#define INF 1000000000
#define LINF 1000000000000000000LL
#define M 1000000007

typedef long long ll;
typedef double db;
typedef struct {
    int st;
    int nd;
} pii;

typedef struct {
    int value;
} mod;

int G[C][C], masks[C];
bool dp[1 << C], vis[C];
int mask;
int cur[C];

void dfs(int v) {
    vis[v] = true;
    mask |= 1 << v;
    cur[mask] = v;

    for (int s = 0; s < C; s++) {
        if (G[v][s] && !vis[s]) {
            dfs(s);
        }
    }
}

int count() {
    int sub[1 << C], res = 0;
    int sub_count = 0;

    for (int m = mask; m; m = (m - 1) & mask) {
        sub[sub_count++] = m;
    }

    for (int i = sub_count - 1; i >= 0; i--) {
        int m = sub[i];
        for (int v = 0; v < C; v++) {
            if (m & (1 << v)) {
                dp[m] |= dp[m ^ (1 << v)] && ((m & masks[v] & mask) == 0);
            }
        }
        if (dp[m]) {
            res = fmax(res, __builtin_popcount(m));
        }
    }
    return res;
}

int solve() {
    int n;
    scanf("%d", &n);
    char s[n + 1], t[n + 1];
    scanf("%s", s);
    scanf("%s", t);

    for (int i = 0; i < n; i++) {
        if (s[i] != t[i]) {
            int a = s[i] - 'a';
            int b = t[i] - 'a';
            G[a][b] = 1;
            G[b][a] = 1;
            masks[a] |= 1 << b;
        }
    }

    int res = 0;
    dp[0] = true;
    for (int i = 0; i < C; i++) {
        if (!vis[i]) {
            mask = 0;
            memset(cur, 0, sizeof(cur));
            dfs(i);
            int tmp = count();
            res += 2 * __builtin_popcount(mask) - 1 - tmp;
        }
    }

    memset(vis, false, sizeof(vis));
    memset(masks, 0, sizeof(masks));
    memset(dp, false, sizeof(dp));
    memset(G, 0, sizeof(G));

    return res;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        printf("%d\n", solve());
    }
    return 0;
}
