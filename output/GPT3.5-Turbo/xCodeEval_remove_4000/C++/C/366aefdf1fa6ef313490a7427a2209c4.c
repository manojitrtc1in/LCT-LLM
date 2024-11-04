#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 1010101
#define INF 1000000000

typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef struct { int a; int b; int c; } triple;
typedef struct { int first; int second; } pair;
typedef struct { int a; int b; int c; } triple;

int vec[MAX_SIZE][1010101];
int vid[MAX_SIZE];
int pr[MAX_SIZE];
int primes[MAX_SIZE];
int calc(int v[], int size) {
    int res = 0;
    for (int i = 0; i < size; i++) {
        res = res * 30 + v[i];
    }
    return res;
}
int calcd(const int v[], int size) {
    int res = 1;
    for (int i = 0; i < size; i++) {
        res *= v[i] + 1;
    }
    return res;
}
int used[1010101];
int maxh;
int w[1010101][1010101];
void addUsed(int v[], int size, int t[], int t_size) {
    int x = calc(t, t_size);
    if (!used[x]) {
        int sz = used.size();
        used[x] = sz;
        assert(w.size() == sz);
        for (int i = 0; i < t_size; i++) {
            w[sz][i] = t[i];
        }
        dc[sz] = calcd(t, t_size);
    }
    v[size] = used[x];
}
int ans[300][300];
int solve() {
    int ws = 1;
    w[0][0] = 0;
    used[0] = 0;
    const int N = 1000010;
    for (int i = 2; i < N; ++i) {
        if (!pr[i]) {
            pr[i] = i;
            primes[ws++] = i;
        }
        for (int j = 0; j < ws && primes[j] <= pr[i] && primes[j] * i < N; ++j) {
            pr[primes[j] * i] = primes[j];
        }
        int cnt = 1;
        int x = i;
        while (pr[x] == pr[x / pr[x]]) {
            cnt++;
            x /= pr[x];
        }
        x /= pr[x];
        memcpy(vec[i], vec[x], sizeof(vec[x]));
        vec[i][vec[x][0]] = cnt;
        int h = calc(vec[i], vec[x][0] + 1);
        maxh = max(maxh, h);
        int id = used[h];
        if (!id) {
            id = ws++;
            for (int j = 0; j < vec[i][0] + 1; j++) {
                w[id][j] = vec[i][j];
            }
        }
        vid[i] = id;
    }
    int ws = used.size();
    for (int i = 0; i < min(w.size(), 20000); ++i) {
        vector<int> cur = w[i];
        for (int j = 0; j < cur.size(); ++j) {
            vector<int> t = cur;
            t[j]--;
            addUsed(g[i], t);
            t[j] += 2;
            addUsed(g[i], t);
        }
        cur.push_back(1);
        addUsed(g[i], cur);
        sort(all(g[i]));
        reunique(g[i]);
        dc[i] = calcd(w[i]);
    }
    DBN(used.size());
    FI(ws) FJ(F) dist[i][j] = INF;
    for (int i = 0; i < ws; ++i) {
        memset(vis, 0, sizeof(vis));
        vector<int> q;
        q.push_back(i);
        int dp[F];
        FI(used.size()) dp[i] = INF;
        dp[i] = 0;
        for (int j = 0; j < q.size(); ++j) {
            int cur = q[j];
            int dcur = dp[cur];
            for (int to : g[cur]) {
                if (dp[to] == INF) {
                    dp[to] = dcur + 1;
                    q.push_back(to);
                }
            }
        }
        FJ(used.size()) {
            if (dc[j] < F) {
                dist[i][dc[j]] = min(dist[i][dc[j]], dp[j]);
            }
        }
    }
    CURTIME();
    FI(ws) {
        dist[i][0] = INF;
        FJ(i + 1) {
            int res = INF;
            for (int k = 0; k < F; ++k) {
                res = min(res, dist[i][k] + dist[j][k]);
            }
            ans[i][j] = res;
        }
    }
    int n;
    cin >> n;
    while (n--) {
        int a, b;
        cin >> a >> b;
        a = vid[a];
        b = vid[b];
        if (a < b) swap(a, b);
        cout << ans[a][b] << '\n';
    }
    return 0;
}

int main(int argc, char** argv) {
    solve();
    return 0;
}
