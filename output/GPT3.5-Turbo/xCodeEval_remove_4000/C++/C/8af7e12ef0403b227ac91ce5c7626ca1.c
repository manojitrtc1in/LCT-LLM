#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 1010101
#define INF 1e9

int vec[MAX_SIZE][20];
int vid[MAX_SIZE];
int pr[MAX_SIZE];
int primes[MAX_SIZE];
int used[MAX_SIZE];
int w[MAX_SIZE][20];
int dc[MAX_SIZE];
int g[MAX_SIZE][20];
int dist[301][10001];
bool vis[10001];
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

void solve() {
    used[0] = 1;
    const int N = 1000010;
    int primesSize = 0;
    for (int i = 2; i < N; i++) {
        if (!pr[i]) {
            pr[i] = i;
            primes[primesSize++] = i;
        }
        for (int j = 0; j < primesSize && primes[j] <= pr[i] && primes[j] * i < N; j++) {
            pr[primes[j] * i] = primes[j];
        }
        int cnt = 1;
        int x = i;
        while (pr[x] == pr[x / pr[x]]) {
            cnt++;
            x /= pr[x];
        }
        x /= pr[x];
        int vecSize = vec[x][0];
        for (int j = 1; j <= vecSize; j++) {
            vec[i][j] = vec[x][j];
        }
        vec[i][vecSize + 1] = cnt;
        int h = calc(vec[i], vecSize + 1);
        maxh = maxh > h ? maxh : h;
        int id = used[h];
        if (!id) {
            id = used[0];
            used[h] = id;
            memcpy(w[id], vec[i], sizeof(int) * (vecSize + 1));
        }
        vid[i] = id;
    }
    int ws = used[0];
    for (int i = 0; i < ws && i < 7000; i++) {
        int curSize = w[i][0];
        for (int j = 1; j <= curSize; j++) {
            int t[curSize];
            memcpy(t, w[i], sizeof(int) * (curSize + 1));
            t[j]--;
            addUsed(g[i], curSize, t, curSize);
            t[j] += 2;
            addUsed(g[i], curSize, t, curSize);
        }
        int cur[curSize + 1];
        memcpy(cur, w[i], sizeof(int) * (curSize + 1));
        cur[curSize + 1] = 1;
        addUsed(g[i], curSize + 1, cur, curSize + 1);
        qsort(g[i], sizeof(g[i]) / sizeof(g[i][0]), sizeof(g[i][0]), (int (*)(const void *, const void *))cmp);
        int gSize = sizeof(g[i]) / sizeof(g[i][0]);
        int k = 0;
        for (int j = 1; j < gSize; j++) {
            if (g[i][j] != g[i][k]) {
                g[i][++k] = g[i][j];
            }
        }
        gSize = k + 1;
        dc[i] = calcd(w[i], curSize + 1);
    }
    for (int i = 0; i < ws; i++) {
        memset(vis, 0, sizeof(vis));
        int q[ws];
        int qSize = 1;
        q[0] = i;
        int dp[ws];
        memset(dp, INF, sizeof(dp));
        dp[i] = 0;
        for (int j = 0; j < qSize; j++) {
            int cur = q[j];
            int dcur = dp[cur];
            int gSize = sizeof(g[cur]) / sizeof(g[cur][0]);
            for (int k = 0; k < gSize; k++) {
                int to = g[cur][k];
                if (dp[to] == INF) {
                    dp[to] = dcur + 1;
                    q[qSize++] = to;
                }
            }
        }
        int dcSize = sizeof(dc) / sizeof(dc[0]);
        for (int j = 0; j < dcSize; j++) {
            if (dc[j] < 10001) {
                dist[i][dc[j]] = dist[i][dc[j]] < dp[j] ? dist[i][dc[j]] : dp[j];
            }
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
        int ans = INF;
        for (int i = 1; i < 3000; i++) {
            ans = ans < dist[a][i] + dist[b][i] ? ans : dist[a][i] + dist[b][i];
        }
        printf("%d\n", ans);
    }
}

int main() {
    solve();
    return 0;
}
