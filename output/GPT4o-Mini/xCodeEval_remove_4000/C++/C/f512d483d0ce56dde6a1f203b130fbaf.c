#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAXN 1000010
#define F 1001
#define INF 1000000000

typedef long long ll;
typedef struct {
    int a, b, c;
} triple;

triple w[1010101];
int vid[1010101];
int pr[MAXN];
int dist[301][F * 2];
bool vis[F * 2];
int dc[F * 2];
int g[F * 2][F * 2];
int ans[303][303];
ll maxh;
int used[1010101];

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

void addUsed(int *v, int size, int *t, int t_size) {
    ll x = calc(t, t_size);
    if (!used[x]) {
        int sz = 0;
        while (used[sz]) sz++;
        used[x] = sz;
        w[sz] = (triple){.a = t[0], .b = t[1], .c = t[2]}; // Assuming t has at least 3 elements
        dc[sz] = calcd(t, t_size);
    }
    v[size++] = used[x];
}

int solve() {
    memset(pr, 0, sizeof(pr));
    memset(used, 0, sizeof(used));
    memset(dist, INF, sizeof(dist));
    memset(g, 0, sizeof(g));

    w[0] = (triple){0, 0, 0};
    used[0] = 0;

    for (int i = 2; i < MAXN; ++i) {
        if (!pr[i]) {
            pr[i] = i;
        }
        for (int p = 2; p * i < MAXN; p++) {
            if (p > pr[i]) break;
            pr[p * i] = p;
        }
        int cnt = 1;
        int x = i;
        while (pr[x] == pr[x / pr[x]]) {
            cnt++;
            x /= pr[x];
        }
        x /= pr[x];

        int vec[100]; // Adjust size as needed
        vec[0] = cnt; // Assuming vec is filled appropriately
        ll h = calc(vec, 1); // Adjust size as needed

        maxh = (maxh > h) ? maxh : h;
        int id = used[h];
        if (!id) {
            id = (int)sizeof(w) / sizeof(w[0]);
            w[id] = (triple){.a = vec[0], .b = 0, .c = 0}; // Assuming vec has at least 1 element
        }
        vid[i] = id;
    }

    int ws = (int)sizeof(w) / sizeof(w[0]);
    for (int i = 0; i < ws; ++i) {
        int cur[100]; // Adjust size as needed
        for (int j = 0; j < sizeof(cur) / sizeof(cur[0]); ++j) {
            int t[100]; // Adjust size as needed
            t[j] = cur[j] - 1;
            addUsed(g[i], sizeof(g[i]) / sizeof(g[i][0]), t, sizeof(t) / sizeof(t[0]));
            t[j] += 2;
            addUsed(g[i], sizeof(g[i]) / sizeof(g[i][0]), t, sizeof(t) / sizeof(t[0]));
        }
        cur[sizeof(cur) / sizeof(cur[0])] = 1;
        addUsed(g[i], sizeof(g[i]) / sizeof(g[i][0]), cur, sizeof(cur) / sizeof(cur[0]));
    }

    for (int i = 0; i < ws; ++i) {
        memset(vis, 0, sizeof(vis));
        int q[100]; // Adjust size as needed
        q[0] = i;
        int dp[F * 2];
        memset(dp, INF, sizeof(dp));
        dp[i] = 0;

        for (int j = 0; j < sizeof(q) / sizeof(q[0]); ++j) {
            int cur = q[j];
            int dcur = dp[cur];
            for (int k = 0; k < sizeof(g[cur]) / sizeof(g[cur][0]); ++k) {
                if (dp[g[cur][k]] == INF) {
                    dp[g[cur][k]] = dcur + 1;
                    q[sizeof(q) / sizeof(q[0])] = g[cur][k];
                }
            }
        }

        for (int j = 0; j < ws; ++j) {
            if (dc[j] < F) {
                dist[i][dc[j]] = (dist[i][dc[j]] < dp[j]) ? dist[i][dc[j]] : dp[j];
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
