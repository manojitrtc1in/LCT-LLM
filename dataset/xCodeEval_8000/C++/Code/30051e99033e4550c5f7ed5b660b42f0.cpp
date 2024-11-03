#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <math.h>
#include <map>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
int b[1050], seq[1050], fl[1050], fr[1050], a[1050][1050], u[1050][1050], d[1050][1050], l[1050][1050], r[1050][1050], n, m, q;

void initf(int d) {
    for (int i = 1; i <= d; i++) {
        fl[i] = fr[i] = i;
    }
}

void init() {
    for (int i = 1; i <= n; ++i)
           for (int j = 1; j <= m; ++j)
               if (a[i][j]) {
                   u[i][j] = u[i - 1][j] + 1;
                   l[i][j] = l[i][j - 1] + 1;
               } else u[i][j] = l[i][j] = 0;
       for (int i = n; i > 0; --i)
           for (int j = m; j > 0; --j)
               if (a[i][j]) {
                   d[i][j] = d[i + 1][j] + 1;
                   r[i][j] = r[i][j + 1] + 1;
               } else d[i][j] = r[i][j] = 0;

}

int findl(int x) {
    return fl[x] == x? x : fl[x] = findl(fl[x]);
}

int findr(int x) {
    return fr[x] == x? x : fr[x] = findr(fr[x]);
}

bool cmp(int i, int j) {
    return b[i] < b[j];
}

int calc(int d, int p) {
    for (int i = 1; i <= d; i++) {
        seq[i] = i;
    }
    memset(fl, 0, sizeof fl);
    memset(fr, 0, sizeof fr);
    initf(d);
    sort(seq + 1, seq + d + 1, cmp);
    int result = 0;
    for (int i = d; i > 0; i--) {
        int l = findl(seq[i]), r = findr(seq[i]);
        if (l <= p && p <= r) result = max(result, (r - l + 1) * b[seq[i]]);
        fr[findr(seq[i] - 1)] = findr(seq[i]), fl[findl(seq[i] + 1)] = findl(seq[i]);
    }
    return result;
}

int main() {
    cin >> n >> m >> q;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    init();
    int op, x, y;
    for (int k = 0; k < q; k++) {
        cin >> op >> x >> y;
        if (op == 1) {

            a[x][y] ^= 1;
            for (int i = x; i <= n; ++i)
                if (a[i][y]) u[i][y] = u[i - 1][y] + 1;
                else u[i][y] = 0;
            for (int j = y; j <= m; ++j)
                if (a[x][j]) l[x][j] = l[x][j - 1] + 1;
                else l[x][j] = 0;
            for (int i = x; i > 0; --i)
                if (a[i][y]) d[i][y] = d[i + 1][y] + 1;
                else d[i][y] = 0;
            for (int j = y; j > 0; --j)
                if (a[x][j]) r[x][j] = r[x][j + 1] + 1;
                else r[x][j] = 0;



        } else {
            int ans = 0;
            for (int j = 1; j <= m; ++j) b[j] = u[x][j];
            ans = max(ans, calc(m, y));
            for (int j = 1; j <= m; ++j) b[j] = d[x][j];
            ans = max(ans, calc(m, y));
            for (int j = 1; j <= n; ++j) b[j] = l[j][y];
            ans = max(ans, calc(n, x));
            for (int j = 1; j <= n; ++j) b[j] = r[j][y];
            ans = max(ans, calc(n, x));
            cout << ans << endl;
        }
    }
    return 0;
}






































