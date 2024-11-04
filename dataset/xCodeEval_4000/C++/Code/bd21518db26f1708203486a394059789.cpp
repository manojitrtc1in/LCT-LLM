

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

namespace dfcmd {

    const int maxn = 3005;
    const int mod = 998244353;

    inline void add(int& x, int y) {
        x += y;
        if (x >= mod) {
            x -= mod;
        }
    }

    string s, t;
    int n, m;

    inline bool myh(int x, int y) {
        if (y < m) {
            return s[x] == t[y];
        } else {
            return true;
        }
    }

    int dp[maxn][maxn];

    int Main() {
        cin >> s >> t;
        n = s.length(), m = t.length();
        for (int i = 0; i < n; ++i) {
            dp[i][i] = myh(0, i);
        }
        int ans = 0;
        if (m == 1) {
            ans = dp[0][0];
        }
        for (int i = 1; i < n; ++i) {
            int l = 0, r = i - 1;
            while (r < n) {
                if (l && myh(i, l - 1)) {
                    add(dp[l - 1][r], dp[l][r]);
                }
                if (r < n - 1 && myh(i, r + 1)) {
                    add(dp[l][r + 1], dp[l][r]);
                }
                ++l, ++r;
            }
            if (i >= m - 1) {
                add(ans, dp[0][i]);
            }
        }
        ans <<= 1;
        if (ans >= mod) {
            ans -= mod;
        }
        writeln(ans);
        return 0;
    }

}

int main() {
    return dfcmd::Main();
}

