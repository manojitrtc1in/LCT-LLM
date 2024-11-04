
 
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
 
    int T;
 
    int f[100];
 
    inline void solve() {
        memset(f, 0, sizeof(f));
        int d, m;
        read(d), read(m);
        if (m == 1) {
            puts("0");
            return;
        }
        f[0] = 1;


        for (int i = 1, nowx = 2; nowx <= d; nowx <<= 1, i++) {
            f[i] = 1;
            for (int j = 0; j < i; ++j) {
                (f[i] += f[j]) %= m;
            }
            if ((nowx << 1) > d) {
                f[i] = (LL) f[i] * (d - nowx + 1) % m;
            } else {
                f[i] = (LL) f[i] * nowx % m;
            }
        }








        int ans = 0;
        for (int i = 0; i < 55; ++i) {
            (ans += f[i]) %= m;
        }
        writeln(ans);
    }
 
    int main() {
        read(T);
        while (T--) {
            solve();
        }
        return 0;
    }
}
 
int main() {
    return dfcmd::main();
}