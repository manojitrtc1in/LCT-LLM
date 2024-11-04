#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX_SIZE 1010101
#define MAX_F 5001
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
int ans[303][303];
int w[MAX_SIZE][20];

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
        for (int i = 0; i < tSize; i++) {
            w[sz][i] = t[i];
        }
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
    int maxh = 0;
    int N = 1000010;
    for (int i = 2; i < N; i++) {
        if (!pr[i]) {
            pr[i] = i;
            primes[i] = i;
        }
        for (int j = 2; j * i < N; j++) {
            if (!pr[j * i]) {
                pr[j * i] = i;
            }
        }
        int cnt = 1;
        int x = i;
        while (pr[x] == pr[x / pr[x]]) {
            cnt++;
            x /= pr[x];
        }
        x /= pr[x];
        int size = 0;
        for (int j = 0; j < size; j++) {
            vec[i][j] = vec[x][j];
        }
        vec[i][size++] = cnt;
        int h = calc(vec[i], size);
        maxh = fmax(maxh, h);
        int id = used[h];
        if (!id) {
            id = used[0];
            used[h] = id;
            for (int j = 0; j < size; j++) {
                w[id][j] = vec[i][j];
            }
            used[0]++;
        }
        vid[i] = id;
    }

    int ws = used[0];
    for (int i = 0; i < fmin(used[0], MAX_F); i++) {
        int cur[20];
        int curSize = 0;
        for (int j = 0; j < 20; j++) {
            cur[j] = w[i][j];
            if (cur[j] != 0) {
                curSize++;
            }
        }
        for (int j = 0; j < curSize; j++) {
            int t[20];
            int tSize = 0;
            for (int k = 0; k < curSize; k++) {
                t[k] = cur[k];
                if (k == j) {
                    t[k]--;
                }
                tSize++;
            }
            addUsed(g[i], curSize, t, tSize);
            tSize = 0;
            for (int k = 0; k < curSize; k++) {
                t[k] = cur[k];
                if (k == j) {
                    t[k]++;
                }
                tSize++;
            }
            addUsed(g[i], curSize, t, tSize);
        }
        cur[curSize++] = 1;
        addUsed(g[i], curSize, cur, curSize);
        int gSize = 0;
        for (int j = 0; j < curSize; j++) {
            g[i][gSize++] = g[i][j];
        }
        reunique(g[i], gSize);
        dc[i] = calcd(w[i], curSize);
    }

    for (int i = 0; i < ws; i++) {
        for (int j = 0; j < MAX_F * 2; j++) {
            dist[i][j] = INF;
        }
    }

    for (int i = 0; i < ws; i++) {
        for (int j = 0; j < MAX_F * 2; j++) {
            vis[j] = false;
        }
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
            for (int k = 0; k < used[0]; k++) {
                int to = g[cur][k];
                if (dp[to] == INF) {
                    dp[to] = dcur + 1;
                    q[qSize++] = to;
                }
            }
        }
        for (int j = 0; j < used[0]; j++) {
            if (dc[j] < MAX_F) {
                dist[i][dc[j]] = fmin(dist[i][dc[j]], dp[j]);
            }
        }
    }

    for (int i = 0; i < ws; i++) {
        dist[i][0] = INF;
        for (int j = 0; j < i + 1; j++) {
            int res = INF;
            for (int k = 0; k < MAX_F; k++) {
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
}

int main() {
    solve();
    return 0;
}
