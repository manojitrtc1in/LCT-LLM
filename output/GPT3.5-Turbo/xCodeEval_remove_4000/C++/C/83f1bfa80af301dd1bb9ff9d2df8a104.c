#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 1010101
#define INF 1000000000

typedef long long ll;

int vec[MAX_SIZE][20];
int vid[MAX_SIZE];
int pr[MAX_SIZE];
int primes[MAX_SIZE];
int pr_size = 0;
ll maxh = 0;
int used[MAX_SIZE];
int w[MAX_SIZE][20];
int dc[MAX_SIZE];
int g[MAX_SIZE][MAX_SIZE];
int dist[MAX_SIZE][6002];
bool vis[MAX_SIZE];
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

void addUsed(int v[], int size, int t[], int t_size) {
    int x = calc(t, t_size);
    if (used[x] == 0) {
        int sz = used_size;
        used[x] = sz;
        for (int i = 0; i < t_size; i++) {
            w[sz][i] = t[i];
        }
        dc[sz] = calcd(t, t_size);
    }
    v[size] = used[x];
}

int gcd(int a, int b) {
    while (b) {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

bool isPrime(int x) {
    if (x <= 4 || x % 2 == 0 || x % 3 == 0) {
        return x == 2 || x == 3;
    }
    for (int i = 5; i * i <= x; i += 6) {
        if (x % i == 0 || x % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

void solve() {
    int used_size = 0;
    w[0][0] = 0;
    used[0] = 0;
    for (int i = 2; i < MAX_SIZE; i++) {
        if (pr[i] == 0) {
            pr[i] = i;
            primes[pr_size++] = i;
        }
        for (int j = 0; j < pr_size && primes[j] <= pr[i] && primes[j] * i < MAX_SIZE; j++) {
            pr[primes[j] * i] = primes[j];
        }
        int cnt = 1;
        int x = i;
        while (pr[x] == pr[x / pr[x]]) {
            cnt++;
            x /= pr[x];
        }
        x /= pr[x];
        int size = 0;
        for (int j = 0; j < vec[x][0]; j++) {
            vec[i][size++] = vec[x][j];
        }
        vec[i][size++] = cnt;
        int h = calc(vec[i], size);
        maxh = max(maxh, h);
        int id = used[h];
        if (id == 0) {
            id = used_size;
            used[h] = id;
            for (int j = 0; j < size; j++) {
                w[id][j] = vec[i][j];
            }
        }
        vid[i] = id;
    }
    int ws = used_size;
    for (int i = 0; i < min(used_size, 3001); i++) {
        int cur[20];
        int cur_size = 0;
        for (int j = 0; j < w[i][0]; j++) {
            cur[cur_size++] = w[i][j];
        }
        for (int j = 0; j < cur_size; j++) {
            int t[20];
            int t_size = 0;
            for (int k = 0; k < cur_size; k++) {
                t[t_size++] = cur[k];
            }
            t[j]--;
            addUsed(g[i], cur_size, t, t_size);
            t[j] += 2;
            addUsed(g[i], cur_size, t, t_size);
        }
        cur[cur_size++] = 1;
        addUsed(g[i], cur_size, cur, cur_size);
        qsort(g[i], cur_size, sizeof(int), compare);
        int g_size = removeDuplicates(g[i], cur_size);
        dc[i] = calcd(w[i], cur_size);
    }
    for (int i = 0; i < used_size; i++) {
        for (int j = 0; j < used_size; j++) {
            dist[i][j] = INF;
        }
    }
    for (int i = 0; i < used_size; i++) {
        memset(vis, 0, sizeof(vis));
        int q[MAX_SIZE];
        int q_size = 0;
        q[q_size++] = i;
        int dp[MAX_SIZE];
        for (int j = 0; j < used_size; j++) {
            dp[j] = INF;
        }
        dp[i] = 0;
        for (int j = 0; j < q_size; j++) {
            int cur = q[j];
            int dcur = dp[cur];
            for (int k = 0; k < g[cur][0]; k++) {
                int to = g[cur][k];
                if (dp[to] == INF) {
                    dp[to] = dcur + 1;
                    q[q_size++] = to;
                }
            }
        }
        for (int j = 0; j < used_size; j++) {
            if (dc[j] < 3001) {
                dist[i][dc[j]] = min(dist[i][dc[j]], dp[j]);
            }
        }
    }
    for (int i = 0; i < used_size; i++) {
        dist[i][0] = INF;
        for (int j = 0; j < i + 1; j++) {
            int res = INF;
            for (int k = 0; k < 3001; k++) {
                res = min(res, dist[i][k] + dist[j][k]);
            }
            ans[i][j] = res;
        }
    }
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
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
