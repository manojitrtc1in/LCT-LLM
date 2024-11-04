#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <math.h>
#include <assert.h>

#define MAXN 1000010
#define F 30001
#define INF 1011111111

typedef long long ll;

int vec[1010101][F];
int vid[1010101];
int pr[1010101];
int primes[100000]; // Adjust size as needed
int prime_count = 0;
ll maxh;
int dist[301][F];
bool vis[F];
int dc[F];
int g[F][F];
int w[100000][F]; // Adjust size as needed
int w_count = 0;
int ans[300][300];

ll calc(int* v, int size) {
    ll res = 0;
    for (int i = 0; i < size; i++) {
        res = res * 30 + v[i];
    }
    return res;
}

int calcd(int* v, int size) {
    int res = 1;
    for (int i = 0; i < size; i++) {
        res *= v[i] + 1;
    }
    return res;
}

void addUsed(int* v, int* t, int size_t) {
    ll x = calc(t, size_t);
    int id = -1;
    for (int i = 0; i < w_count; i++) {
        if (calc(w[i], F) == x) {
            id = i;
            break;
        }
    }
    if (id == -1) {
        id = w_count++;
        memcpy(w[id], t, sizeof(int) * size_t);
        dc[id] = calcd(t, size_t);
    }
    v[0] = id; // Assuming v is a pointer to an array
}

int solve() {
    memset(pr, 0, sizeof(pr));
    w_count = 1;
    memset(w, 0, sizeof(w));
    memset(vid, 0, sizeof(vid));
    memset(dc, 0, sizeof(dc));
    memset(g, 0, sizeof(g));
    memset(dist, INF, sizeof(dist));

    for (int i = 2; i < MAXN; ++i) {
        if (!pr[i]) {
            pr[i] = i;
            primes[prime_count++] = i;
        }
        for (int j = 0; j < prime_count; j++) {
            int p = primes[j];
            if (p * i > MAXN || p > pr[i]) {
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
        memcpy(vec[i], vec[x], sizeof(int) * (F - 1));
        vec[i][F - 1] = cnt;
        ll h = calc(vec[i], F);

        maxh = fmax(maxh, h);
        int id = -1;
        for (int j = 0; j < w_count; j++) {
            if (calc(w[j], F) == h) {
                id = j;
                break;
            }
        }
        if (id == -1) {
            id = w_count++;
            memcpy(w[id], vec[i], sizeof(int) * F);
        }
        vid[i] = id;
    }

    int ws = w_count;
    for (int i = 0; i < fmin(ws, 20000); ++i) {
        int* cur = w[i];
        for (int j = 0; j < F; ++j) {
            int t[F];
            memcpy(t, cur, sizeof(int) * F);
            t[j]--;
            addUsed(g[i], t, F);
            t[j] += 2;
            addUsed(g[i], t, F);
        }
        cur[F - 1] = 1;
        addUsed(g[i], cur, F);
        // Sort and reunique g[i] here if needed
        dc[i] = calcd(w[i], F);
    }

    for (int i = 0; i < ws; ++i) {
        memset(vis, 0, sizeof(vis));
        int q[F];
        int q_size = 0;
        q[q_size++] = i;
        int dp[F];
        memset(dp, INF, sizeof(dp));
        dp[i] = 0;
        for (int j = 0; j < q_size; ++j) {
            int cur = q[j];
            int dcur = dp[cur];
            for (int k = 0; k < F; ++k) {
                if (g[cur][k] && dp[g[cur][k]] == INF) {
                    dp[g[cur][k]] = dcur + 1;
                    q[q_size++] = g[cur][k];
                }
            }
        }
        for (int j = 0; j < ws; ++j) {
            if (dc[j] < F) {
                dist[i][dc[j]] = fmin(dist[i][dc[j]], dp[j]);
            }
        }
    }

    for (int i = 0; i < ws; ++i) {
        dist[i][0] = INF;
        for (int j = 0; j <= i; ++j) {
            int res = INF;
            for (int k = 0; k < F; ++k) {
                res = fmin(res, dist[i][k] + dist[j][k]);
            }
            ans[i][j] = res;
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
    return solve();
}
