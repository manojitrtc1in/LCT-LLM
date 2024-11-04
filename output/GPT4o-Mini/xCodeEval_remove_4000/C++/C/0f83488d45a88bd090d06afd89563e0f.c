#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAXN 1000010
#define F 1001
#define INF 0x3f3f3f3f

typedef long long ll;
typedef struct {
    int a, b, c;
} triple;

triple w[1000001];
int used[1000001];
int vid[MAXN];
int pr[MAXN];
int vec[MAXN][F];
int dist[301][F * 2];
bool vis[F * 2];
int dc[F * 2];
int g[F * 2][F * 2];
int ans[303][303];

int calc(int* v, int size) {
    int res = 0;
    for (int i = 0; i < size; i++) {
        res = res * 24 + v[i];
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

void addUsed(int* v, int size, int* t, int t_size) {
    int x = calc(t, t_size);
    if (!used[x]) {
        int sz = 0;
        while (used[sz]) sz++;
        used[x] = sz;
        memcpy(&w[sz], t, sizeof(int) * t_size);
        dc[sz] = calcd(t, t_size);
    }
    v[size++] = used[x];
}

int solve() {
    memset(used, 0, sizeof(used));
    memset(pr, 0, sizeof(pr));
    memset(vec, 0, sizeof(vec));
    memset(dist, INF, sizeof(dist));
    
    w[0].a = 0; // Initialize the first element
    const int N = 1000010;
    for (int i = 2; i < N; ++i) {
        if (!pr[i]) {
            pr[i] = i;
        }
        for (int p = 2; p * i < N && p <= pr[i]; p++) {
            pr[p * i] = p;
        }
        int cnt = 1;
        int x = i;
        while (pr[x] == pr[x / pr[x]]) {
            cnt++;
            x /= pr[x];
        }
        x /= pr[x];
        vec[i][0] = cnt; // Store the count
        int h = calc(vec[i], 1);
        if (!used[h]) {
            used[h] = (int)w[0].a; // Assign id
            w[0].a++;
        }
        vid[i] = used[h];
    }
    
    int ws = (int)w[0].a;
    for (int i = 0; i < ws && i < F; ++i) {
        int* cur = vec[i];
        for (int j = 0; j < cur[0]; ++j) {
            int t[F];
            memcpy(t, cur, sizeof(int) * (cur[0] + 1));
            t[j]--;
            addUsed(g[i], 0, t, cur[0]);
            t[j] += 2;
            addUsed(g[i], 0, t, cur[0]);
        }
        cur[cur[0] + 1] = 1;
        addUsed(g[i], 0, cur, cur[0] + 1);
    }
    
    for (int i = 0; i < ws; ++i) {
        memset(vis, 0, sizeof(vis));
        int q[F * 2], front = 0, back = 0;
        q[back++] = i;
        int dp[F * 2];
        memset(dp, INF, sizeof(dp));
        dp[i] = 0;
        while (front < back) {
            int cur = q[front++];
            int dcur = dp[cur];
            for (int j = 0; j < F * 2; j++) {
                if (g[cur][j] && dp[g[cur][j]] == INF) {
                    dp[g[cur][j]] = dcur + 1;
                    q[back++] = g[cur][j];
                }
            }
        }
        for (int j = 0; j < ws; ++j) {
            if (dc[j] < F) {
                dist[i][dc[j]] = (dist[i][dc[j]] < dp[j]) ? dist[i][dc[j]] : dp[j];
            }
        }
    }
    
    for (int i = 0; i < ws; ++i) {
        dist[i][0] = INF;
        for (int j = 0; j <= i; ++j) {
            int res = INF;
            for (int k = 0; k < F; ++k) {
                res = (res < dist[i][k] + dist[j][k]) ? res : (dist[i][k] + dist[j][k]);
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
    solve();
    return 0;
}
