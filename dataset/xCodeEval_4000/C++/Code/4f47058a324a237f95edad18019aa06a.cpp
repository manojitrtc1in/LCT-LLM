

#define _CRT_SECURE_NO_WARNINGS

#include <map>
#include <set>
#include <stack>
#include <ctime>
#include <cmath>
#include <queue>
#include <cstdio>
#include <cctype>
#include <vector>
#include <bitset>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

inline char gc() {
    static const int L = 233333;
    static char sxd[L], *sss = sxd, *ttt = sxd;
    if (sss == ttt) {
        ttt = (sss = sxd) + fread(sxd, 1, L, stdin);
        if (sss == ttt) {
            return EOF;
        }
    }
    return *sss++;
}

#ifndef _AT_HOME
#define dd c = gc()
#else
#define dd c = getchar()
#endif
inline char readalpha() {
    char dd;
    for (; !isalpha(c); dd);
    return c;
}

inline char readchar() {
    char dd;
    for (; c == ' '; dd);
    return c;
}

template <class T>
inline bool read(T& x) {
    bool flg = false;
    char dd;
    x = 0;
    for (; !isdigit(c); dd) {
        if (c == '-') {
            flg = true;
        } else if(c == EOF) {
            return false;
        }
    }
    for (; isdigit(c); dd) {
        x = (x * 10) + (c ^ 48);
    }
    if (flg) {
        x = -x;
    }
    return true;
}
#undef dd

template <class T>
inline void write(T x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x < 10) {
        putchar(x | 48);
        return;
    }
    write(x / 10);
    putchar((x % 10) | 48);
}

template <class T>
inline void writesp(T x) {
    write(x);
    putchar(' ');
}

template <class T>
inline void writeln(T x) {
    write(x);
    puts("");
}

const int mod = 1000000007;

typedef long long LL;

const int maxn = 66;

int n, m;
char s[maxn][maxn];
int xx[maxn][maxn];
int r[maxn];
int c[maxn];

inline void solve() {
    scanf("%d%d", &n, &m);
    bool all = true, hv = false;
    memset(r, 0, sizeof(r));
    memset(c, 0, sizeof(c));
    for (int i = 1; i <= n; ++i) {
        scanf("%s", s[i] + 1);
        for (int j = 1; j <= m; ++j) {
            xx[i][j] = (s[i][j] == 'A');
            r[i] += xx[i][j];
            c[j] += xx[i][j];
            hv |= xx[i][j];
            all &= xx[i][j];
        }
    }
    if (all) {
        puts("0");
        return;
    }
    if (!hv) {
        puts("MORTAL");
        return;
    }
    if (r[1] == m || r[n] == m || c[1] == n || c[m] == n) {
        puts("1");
        return;
    }
    if (xx[1][1] || xx[n][1] || xx[1][m] || xx[n][m]) {
        puts("2");
        return;
    }
    for (int i = 1; i <= n; ++i) {
        if (r[i] == m) {
            puts("2");
            return;
        }
    }
    for (int i = 1; i <= m; ++i) {
        if (c[i] == n) {
            puts("2");
            return;
        }
    }
    for (int i = 1; i <= m; ++i) {
        if (xx[1][i] || xx[n][i]) {
            puts("3");
            return;
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (xx[i][1] || xx[i][m]) {
            puts("3");
            return;
        }
    }
    puts("4");
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        solve();
    }
    return 0;
}