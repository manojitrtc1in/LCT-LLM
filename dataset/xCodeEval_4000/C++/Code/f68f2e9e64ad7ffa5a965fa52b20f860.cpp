
 
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
    const LL inf = 4e18;
 
    int na, nb, nc;
    LL A[maxn];
    LL B[maxn];
    LL C[maxn];
    set<LL> sta;
    set<LL> stb;
    set<LL> stc;
 
    inline LL sqr(LL x) {
        return x * x;
    }
 
    inline void solve() {
        read(na), read(nb), read(nc);
        sta.clear(), stb.clear(), stc.clear();
        for (int i = 1; i <= na; ++i) {
            read(A[i]);
            sta.insert(A[i]);
        }
        for (int i = 1; i <= nb; ++i) {
            read(B[i]);
            stb.insert(B[i]);
        }
        for (int i = 1; i <= nc; ++i) {
            read(C[i]);
            stc.insert(C[i]);
        }
        LL ans = inf;
        for (int i = 1; i <= na; ++i) {
            auto bb = stb.lower_bound(A[i]);
            auto cc = stc.upper_bound(A[i]);
            if (cc != stc.begin()) {
                cc--;
                ans = min(ans, sqr(A[i] - *bb) + sqr(*bb - *cc) + sqr(*cc - A[i]));
            }
            bb = stb.upper_bound(A[i]);
            cc = stc.lower_bound(A[i]);
            if (bb != stb.begin()) {
                bb--;
                ans = min(ans, sqr(A[i] - *bb) + sqr(*bb - *cc) + sqr(*cc - A[i]));
            }
        }


        for (int i = 1; i <= nb; ++i) {
            auto aa = sta.upper_bound(B[i]);
            auto cc = stc.lower_bound(B[i]);
            if (aa != sta.begin()) {
                aa--;
                ans = min(ans, sqr(*aa - B[i]) + sqr(B[i] - *cc) + sqr(*cc -*aa));
            }
            aa = sta.lower_bound(B[i]);
            cc = stc.upper_bound(B[i]);
            if (cc != stc.begin()) {
                cc--;
                ans = min(ans, sqr(*aa - B[i]) + sqr(B[i] - *cc) + sqr(*cc -*aa));
            }
        }
        for (int i = 1; i <= nc; ++i) {
            auto aa = sta.upper_bound(C[i]);
            auto bb = stb.lower_bound(C[i]);
            if (aa != sta.begin()) {
                aa--;
                ans = min(ans, sqr(*aa - *bb) + sqr(*bb - C[i]) + sqr(C[i] -*aa));
            }
            aa = sta.lower_bound(C[i]);
            bb = stb.upper_bound(C[i]);
            if (bb != stb.begin()) {
                bb--;
                ans = min(ans, sqr(*aa - *bb) + sqr(*bb - C[i]) + sqr(C[i] -*aa));
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
 
