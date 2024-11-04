#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

#define N 1010
int U[N + 1][N + 1], D[N + 1][N + 1], L[N + 1][N + 1], R[N + 1][N + 1];
int n, m, q, a[N + 1][N + 1], b[N + 1], seq[N + 1];

struct DS {
    int f[N + 1];

    void init(int n) {
        for (int i = 0; i <= n + 1; ++i) f[i] = i;
    }
    int find(int x) {
        return x == f[x] ? x : f[x] = find(f[x]);
    }
    void merge(int x, int y) {
        f[find(x)] = find(y);
    }
} lf, rf;

inline bool cmp(int x, int y) {
    return b[x] < b[y];
}

int calc(int n, int x) {
    for (int i = 1; i <= n; ++i) seq[i] = i;
    sort(seq + 1, seq + n + 1, cmp);
    lf.init(n), rf.init(n);
    int ret = 0;
    for (int i = n; i > 0; --i) {
        int l = lf.find(seq[i]), r = rf.find(seq[i]);
        if (l <= x && x <= r) ret = max(ret, (r - l + 1) * b[seq[i]]);
        rf.merge(seq[i] - 1, seq[i]), lf.merge(seq[i] + 1, seq[i]);
    }
    return ret;
}

int main(int argc, char *argv[]) {
#ifdef KANARI
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios :: sync_with_stdio(false);
    cin >> n >> m >> q;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> a[i][j];

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (a[i][j]) {
                U[i][j] = U[i - 1][j] + 1;
                L[i][j] = L[i][j - 1] + 1;
            } else U[i][j] = L[i][j] = 0;
    for (int i = n; i > 0; --i)
        for (int j = m; j > 0; --j)
            if (a[i][j]) {
                D[i][j] = D[i + 1][j] + 1;
                R[i][j] = R[i][j + 1] + 1;
            } else D[i][j] = R[i][j] = 0;

    while (q--) {
        int op, x, y;
        cin >> op >> x >> y;
        if (op == 1) {
            a[x][y] ^= 1;
            for (int i = x; i <= n; ++i)
                if (a[i][y]) U[i][y] = U[i - 1][y] + 1;
                else U[i][y] = 0;
            for (int j = y; j <= m; ++j)
                if (a[x][j]) L[x][j] = L[x][j - 1] + 1;
                else L[x][j] = 0;
            for (int i = x; i > 0; --i)
                if (a[i][y]) D[i][y] = D[i + 1][y] + 1;
                else D[i][y] = 0;
            for (int j = y; j > 0; --j)
                if (a[x][j]) R[x][j] = R[x][j + 1] + 1;
                else R[x][j] = 0;
        } else {
            int ans = 0;
            for (int i = 1; i <= m; ++i) b[i] = U[x][i];
            ans = max(ans, calc(m, y));
            for (int i = 1; i <= m; ++i) b[i] = D[x][i];
            ans = max(ans, calc(m, y));
            for (int i = 1; i <= n; ++i) b[i] = L[i][y];
            ans = max(ans, calc(n, x));
            for (int i = 1; i <= n; ++i) b[i] = R[i][y];
            ans = max(ans, calc(n, x));
            cout << ans << endl;
        }
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}





































