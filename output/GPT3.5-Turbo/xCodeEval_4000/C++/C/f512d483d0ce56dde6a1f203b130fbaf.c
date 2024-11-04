#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 1010101
#define MAX_F 1001
#define INF 1011111111

int vec[MAX_SIZE][20];
int vid[MAX_SIZE];
int pr[MAX_SIZE];
int primes[MAX_SIZE];
int prSize = 0;
int maxh = 0;
int used[MAX_SIZE];
int w[MAX_SIZE][20];
int dc[MAX_SIZE];
int g[MAX_F * 2][MAX_SIZE];
int dist[MAX_F * 2][MAX_F * 2];
bool vis[MAX_F * 2];
int ans[303][303];

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
    if (used[x] == 0) {
        int sz = used[0];
        used[x] = sz;
        memcpy(w[sz], t, sizeof(int) * tSize);
        dc[sz] = calcd(t, tSize);
        used[0]++;
    }
    v[size] = used[x];
}

void reunique(int v[], int size) {
    int j = 0;
    for (int i = 0; i < size; i++) {
        if (i == 0 || v[i] != v[i - 1]) {
            v[j++] = v[i];
        }
    }
}

void solve() {
    used[0] = 1;
    w[0][0] = 0;
    used[0]++;
    for (int i = 2; i < MAX_SIZE; i++) {
        if (pr[i] == 0) {
            pr[i] = i;
            primes[prSize++] = i;
        }
        for (int j = 0; j < prSize && primes[j] <= pr[i] && primes[j] * i < MAX_SIZE; j++) {
            pr[primes[j] * i] = primes[j];
        }
        int cnt = 1;
        int x = i;
        while (pr[x] == pr[x / pr[x]]) {
            cnt++;
            x /= pr[x];
        }
        x /= pr[x];
        memcpy(vec[i], vec[x], sizeof(int) * (vec[x][0] + 1));
        vec[i][vec[x][0] + 1] = cnt;
        int h = calc(vec[i], vec[i][0] + 1);
        maxh = maxh > h ? maxh : h;
        if (used[h] == 0) {
            int sz = used[0];
            used[h] = sz;
            memcpy(w[sz], vec[i], sizeof(int) * (vec[i][0] + 1));
            used[0]++;
        }
        vid[i] = used[h];
    }
    int ws = used[0];
    for (int i = 0; i < ws && i < MAX_F; i++) {
        int cur[20];
        memcpy(cur, w[i], sizeof(int) * (w[i][0] + 1));
        for (int j = 0; j < cur[0]; j++) {
            int t[20];
            memcpy(t, cur, sizeof(int) * (cur[0] + 1));
            t[j + 1]--;
            addUsed(g[i], g[i][0], t, cur[0] + 1);
            t[j + 1] += 2;
            addUsed(g[i], g[i][0], t, cur[0] + 1);
        }
        cur[cur[0] + 1] = 1;
        addUsed(g[i], g[i][0], cur, cur[0] + 2);
        reunique(g[i], g[i][0]);
        dc[i] = calcd(w[i], w[i][0] + 1);
    }
    for (int i = 0; i < ws; i++) {
        for (int j = 0; j < MAX_F * 2; j++) {
            dist[i][j] = INF;
        }
    }
    for (int i = 0; i < ws; i++) {
        memset(vis, 0, sizeof(vis));
        int q[MAX_F * 2];
        int qSize = 0;
        q[qSize++] = i;
        int dp[MAX_F * 2];
        for (int j = 0; j < used[0]; j++) {
            dp[j] = INF;
        }
        dp[i] = 0;
        for (int j = 0; j < qSize; j++) {
            int cur = q[j];
            int dcur = dp[cur];
            for (int k = 1; k <= g[cur][0]; k++) {
                int to = g[cur][k];
                if (dp[to] == INF) {
                    dp[to] = dcur + 1;
                    q[qSize++] = to;
                }
            }
        }
        for (int j = 1; j <= used[0]; j++) {
            if (dc[j] < MAX_F) {
                dist[i][dc[j]] = dist[i][dc[j]] < dp[j] ? dist[i][dc[j]] : dp[j];
            }
        }
    }
    for (int i = 0; i < ws; i++) {
        dist[i][0] = INF;
        for (int j = 0; j < i; j++) {
            int res = INF;
            for (int k = 0; k < MAX_F; k++) {
                res = res < dist[i][k] + dist[j][k] ? res : dist[i][k] + dist[j][k];
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
}

int main() {
    solve();
    return 0;
}
