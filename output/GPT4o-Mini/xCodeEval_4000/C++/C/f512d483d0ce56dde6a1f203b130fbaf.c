#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <math.h>
#include <assert.h>

#define MAXN 1000010
#define INF 1011111111
#define F 1001

typedef long long ll;

int vec[MAXN][F];
int vid[MAXN];
int pr[MAXN];
int primes[MAXN];
int used[MAXN];
ll maxh;
int dist[F][F * 2];
bool vis[F * 2];
int dc[F * 2];
int g[F * 2][F];
int w[F][F];
int ans[303][303];

ll calc(int *v, int size) {
    ll res = 0;
    for (int i = 0; i < size; i++) {
        res = res * 30 + v[i];
    }
    return res;
}

int calcd(int *v, int size) {
    int res = 1;
    for (int i = 0; i < size; i++) {
        res *= v[i] + 1;
    }
    return res;
}

void addUsed(int *v, int *t, int size) {
    ll x = calc(t, size);
    if (!used[x]) {
        int sz = 0;
        while (used[sz]) sz++;
        used[x] = sz;
        assert(sz == sizeof(w) / sizeof(w[0]));
        memcpy(w[sz], t, size * sizeof(int));
        dc[sz] = calcd(t, size);
    }
    v[0] = used[x];
}

int solve() {
    memset(used, 0, sizeof(used));
    memset(vec, 0, sizeof(vec));
    memset(pr, 0, sizeof(pr));
    memset(g, 0, sizeof(g));
    memset(w, 0, sizeof(w));
    memset(ans, 0, sizeof(ans));

    w[0][0] = 0;
    used[0] = 0;

    for (int i = 2; i < MAXN; ++i) {
        if (!pr[i]) {
            pr[i] = i;
            primes[i] = i;
        }
        for (int p = 2; p * i < MAXN; p++) {
            if (p > pr[i]) {
                break;
            }
            pr[p * i] = p;
        }
        int cnt = 1;
        int x = i;
        while (pr[x] == pr[x / pr[x]]) {
            cnt++;
            x /= pr[x];
        }
        x /= pr[x];
        vec[i][0] = cnt;
        for (int t = 0; t < vec[x][0]; t++) {
            vec[i][t + 1] = vec[x][t];
        }
        ll h = calc(vec[i], vec[i][0] + 1);
        maxh = fmax(maxh, h);
        int id = used[h];
        if (!id) {
            id = sizeof(w) / sizeof(w[0]);
            memcpy(w[id], vec[i], (vec[i][0] + 1) * sizeof(int));
        }
        vid[i] = id;
    }

    int ws = sizeof(w) / sizeof(w[0]);
    for (int i = 0; i < ws; ++i) {
        int cur[F];
        memcpy(cur, w[i], sizeof(cur));
        for (int j = 0; j < cur[0]; ++j) {
            int t[F];
            memcpy(t, cur, sizeof(t));
            t[j]--;
            addUsed(g[i], t, cur[0]);
            t[j] += 2;
            addUsed(g[i], t, cur[0]);
        }
        cur[cur[0]] = 1;
        addUsed(g[i], cur, cur[0] + 1);
        // Sort and unique g[i] here (not implemented)
        dc[i] = calcd(w[i], w[i][0]);
    }

    for (int i = 0; i < ws; i++) {
        memset(vis, 0, sizeof(vis));
        int q[F];
        q[0] = i;
        int dp[F];
        for (int j = 0; j < sizeof(used) / sizeof(used[0]); j++) {
            dp[j] = INF;
        }
        dp[i] = 0;
        for (int j = 0; j < sizeof(q) / sizeof(q[0]); j++) {
            int cur = q[j];
            int dcur = dp[cur];
            for (int to = 0; to < sizeof(g[cur]) / sizeof(g[cur][0]); to++) {
                if (dp[g[cur][to]] == INF) {
                    dp[g[cur][to]] = dcur + 1;
                    // Add to q here (not implemented)
                }
            }
        }
        for (int j = 0; j < sizeof(used) / sizeof(used[0]); j++) {
            if (dc[j] < F) {
                dist[i][dc[j]] = fmin(dist[i][dc[j]], dp[j]);
            }
        }
    }

    int n;
    scanf("%d", &n);
    while (n--) {
        int a, b;
        scanf("%d %d", &a, &b);
        a = vid[a];
        b = vid[b];
        if (a < b) {
            int temp = a;
            a = b;
            b = temp;
        }
        printf("%d\n", ans[a][b]);
    }
    return 0;
}

int main() {
    solve();
    return 0;
}
