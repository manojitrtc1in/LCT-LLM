#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 1010101
#define MAX_F 3001
#define INF 1011111111

int vec[MAX_SIZE][20];
int vid[MAX_SIZE];
int pr[MAX_SIZE];
int primes[MAX_SIZE];
int used[MAX_SIZE];
int dc[MAX_SIZE];
int dist[MAX_SIZE][MAX_F * 2];
bool vis[MAX_F * 2];
int g[MAX_F * 2][MAX_F * 2];
int ans[MAX_SIZE][MAX_SIZE];
int w[MAX_SIZE][20];
int maxh;

int calc(int v[], int size) {
    int res = 0;
    for (int i = 0; i < size; i++) {
        res = res * 30 + v[i];
    }
    return res;
}

int calcd(int v[], int size) {
    int res = 1;
    for (int i = 0; i < size; i++) {
        res *= v[i] + 1;
    }
    return res;
}

void addUsed(int v[], int size, int t[], int tSize) {
    int x = calc(t, tSize);
    if (!used[x]) {
        int sz = used[0];
        used[x] = sz;
        memcpy(w[sz], t, sizeof(int) * tSize);
        dc[sz] = calcd(t, tSize);
    }
    v[size] = used[x];
}

void reunique(int v[], int size) {
    int j = 0;
    for (int i = 0; i < size; i++) {
        if (v[i] != v[j]) {
            j++;
            v[j] = v[i];
        }
    }
    size = j + 1;
}

void solve() {
    int ws = used[0];
    for (int i = 0; i < ws; i++) {
        for (int j = 0; j < w[i][0]; j++) {
            int t[20];
            memcpy(t, w[i], sizeof(int) * w[i][0]);
            t[j + 1]--;
            addUsed(g[i], sizeof(g[i]) / sizeof(g[i][0]), t, sizeof(t) / sizeof(t[0]));
            t[j + 1] += 2;
            addUsed(g[i], sizeof(g[i]) / sizeof(g[i][0]), t, sizeof(t) / sizeof(t[0]));
        }
        w[i][0]++;
        addUsed(g[i], sizeof(g[i]) / sizeof(g[i][0]), w[i], sizeof(w[i]) / sizeof(w[i][0]));
        qsort(g[i], sizeof(g[i]) / sizeof(g[i][0]), sizeof(g[i][0]), (int (*)(const void *, const void *))cmp);
        reunique(g[i], sizeof(g[i]) / sizeof(g[i][0]));
        dc[i] = calcd(w[i], sizeof(w[i]) / sizeof(w[i][0]));
    }
    for (int i = 0; i < ws; i++) {
        memset(vis, 0, sizeof(vis));
        int q[MAX_SIZE];
        int qSize = 0;
        q[qSize++] = i;
        int dp[MAX_F * 2];
        memset(dp, INF, sizeof(dp));
        dp[i] = 0;
        for (int j = 0; j < qSize; j++) {
            int cur = q[j];
            int dcur = dp[cur];
            for (int k = 0; k < sizeof(g[cur]) / sizeof(g[cur][0]); k++) {
                int to = g[cur][k];
                if (dp[to] == INF) {
                    dp[to] = dcur + 1;
                    q[qSize++] = to;
                }
            }
        }
        for (int j = 0; j < ws; j++) {
            if (dc[j] < MAX_F) {
                dist[i][dc[j]] = min(dist[i][dc[j]], dp[j]);
            }
        }
    }
    for (int i = 0; i < ws; i++) {
        dist[i][0] = INF;
        for (int j = 0; j < i + 1; j++) {
            int res = INF;
            for (int k = 0; k < MAX_F; k++) {
                res = min(res, dist[i][k] + dist[j][k]);
            }
            ans[i][j] = res;
        }
    }
    int n;
    scanf("%d", &n);
    while (n--) {
        int a, b;
        scanf("%d%d", &a, &b);
        a = vid[a];
        b = vid[b];
        if (a < b) {
            int temp = a;
            a = b;
            b = temp;
        }
        printf("%d\n", ans[a][b]);
    }
}

int main() {
    memset(used, 0, sizeof(used));
    memset(pr, 0, sizeof(pr));
    memset(primes, 0, sizeof(primes));
    memset(vec, 0, sizeof(vec));
    memset(vid, 0, sizeof(vid));
    memset(ans, 0, sizeof(ans));
    memset(w, 0, sizeof(w));
    memset(dist, 0, sizeof(dist));
    memset(vis, 0, sizeof(vis));
    memset(g, 0, sizeof(g));
    memset(dc, 0, sizeof(dc));
    maxh = 0;

    for (int i = 2; i < MAX_SIZE; i++) {
        if (!pr[i]) {
            pr[i] = i;
            primes[i] = i;
        }
        for (int j = 0; j < sizeof(primes) / sizeof(primes[0]); j++) {
            int p = primes[j];
            if (p * i >= MAX_SIZE || p > pr[i]) {
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
        memcpy(vec[i], vec[x], sizeof(vec[x]));
        vec[i][sizeof(vec[i]) / sizeof(vec[i][0])] = cnt;
        int h = calc(vec[i], sizeof(vec[i]) / sizeof(vec[i][0]));
        maxh = max(maxh, h);
        if (!used[h]) {
            used[h] = used[0];
            used[0]++;
            memcpy(w[used[h]], vec[i], sizeof(vec[i]));
        }
        vid[i] = used[h];
    }
    solve();
    return 0;
}
