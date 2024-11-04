

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

    typedef long long LL;

    const int maxn = 100005;
    const LL inf = 0x3f3f3f3f3f3f3f3fLL;
    const int Inf = 0x3f3f3f3f;

    int na, nb, nc;
    LL A[maxn];
    LL B[maxn];
    LL C[maxn];

    inline LL sqr(LL x) {
        return x * x;
    }

    inline void solve() {
        read(na), read(nb), read(nc);
        for (int i = 1; i <= na; ++i) {
            read(A[i]);
        }
        for (int i = 1; i <= nb; ++i) {
            read(B[i]);
        }
        for (int i = 1; i <= nc; ++i) {
            read(C[i]);
        }
        sort(A + 1, A + na + 1);
        sort(B + 1, B + nb + 1);
        sort(C + 1, C + nc + 1);
        LL ans = inf;

        for (int i = 1, bb = 1, cc = 1; i <= na; ++i) {
            while (bb < nb && B[bb + 1] <= A[i]) {
                bb++;
            }
            while (cc < nc && C[cc] < A[i]) {
                cc++;
            }
            if (B[bb] <= A[i] && A[i] <= C[cc]) {
                ans = min(sqr(A[i] - B[bb]) + sqr(B[bb] - C[cc]) + sqr(C[cc] - A[i]), ans);
            }
        }
        for (int i = 1, bb = 1, cc = 1; i <= na; ++i) {
            while (bb < nb && B[bb] < A[i]) {
                bb++;
            }
            while (cc < nc && C[cc + 1] <= A[i]) {
                cc++;
            }
            if (B[bb] >= A[i] && A[i] >= C[cc]) {
                ans = min(sqr(A[i] - B[bb]) + sqr(B[bb] - C[cc]) + sqr(C[cc] - A[i]), ans);
            }
        }

        for (int i = 1, aa = 1, cc = 1; i <= nb; ++i) {
            while (aa < na && A[aa + 1] <= B[i]) {
                aa++;
            }
            while (cc < nc && C[cc] < B[i]) {
                cc++;
            }
            if (A[aa] <= B[i] && B[i] <= C[cc]) {
                ans = min(sqr(A[aa] - B[i]) + sqr(B[i] - C[cc]) + sqr(C[cc] - A[aa]), ans);
            }
        }
        for (int i = 1, aa = 1, cc = 1; i <= nb; ++i) {
            while (aa < na && A[aa] < B[i]) {
                aa++;
            }
            while (cc < nc && C[cc + 1] <= B[i]) {
                cc++;
            }
            if (A[aa] >= B[i] && B[i] >= C[cc]) {
                ans = min(sqr(A[aa] - B[i]) + sqr(B[i] - C[cc]) + sqr(C[cc] - A[aa]), ans);
            }
        }

        for (int i = 1, aa = 1, bb = 1; i <= nc; ++i) {
            while (aa < na && A[aa + 1] <= C[i]) {
                aa++;
            }
            while (bb < nb && B[bb] < C[i]) {
                bb++;
            }
            if (A[aa] <= C[i] && C[i] <= B[bb]) {
                ans = min(sqr(A[aa] - B[bb]) + sqr(B[bb] - C[i]) + sqr(C[i] - A[aa]), ans);






            }
        }
        for (int i = 1, aa = 1, bb = 1; i <= nc; ++i) {
            while (aa < na && A[aa] < C[i]) {
                aa++;
            }
            while (bb < nb && B[bb + 1] <= C[i]) {
                bb++;
            }
            if (A[aa] >= C[i] && C[i] >= B[bb]) {
                ans = min(sqr(A[aa] - B[bb]) + sqr(B[bb] - C[i]) + sqr(C[i] - A[aa]), ans);
            }
        }
        writeln(ans);
    }

    int Main() {






        int T;
        read(T);
        while (T--) {
            solve();
        }
        return 0;
    }

}

int main() {
    return dfcmd::Main();
}

