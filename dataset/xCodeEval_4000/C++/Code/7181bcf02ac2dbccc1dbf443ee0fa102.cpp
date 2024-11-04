

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

namespace pufanyi {

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
            x = (x << 1) + (x << 3) + (c ^ 48);
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

    const int maxn = 4000005;

    typedef long long LL;

    LL aa[maxn];
    LL bb[maxn];
    LL sl[maxn];
    LL sr[maxn];

    int Main() {
        int n, k;
        read(n), read(k);
        for (int i = 1; i <= n; ++i) {
            read(aa[i]);
        }
        int m = 0, tl = 0, tr = 0;
        for (int i = 1, j = 1; i <= n; i = j + 1, j = i) {


            while (j <= n && aa[j + 1] >= aa[j]) {
                ++j;
            }








            while (tl && aa[i] <= sl[tl]) {
                bb[++m] = sr[tr--] - sl[tl--];
            }
            sl[++tl] = aa[i];
            while (tr && aa[j] >= sr[tr]) {
                bb[++m] = sr[tr--] - sl[tl--];
            }
            sr[++tr] = aa[j];
        }
        while (tl) {
            bb[++m] = sr[tr--] - sl[tl--];
        }
        k = min(k, m);
        nth_element(bb + 1, bb + k, bb + m + 1, greater<LL>());
        LL ans = 0;










        for (int i = 1; i <= k; ++i) {
            if (bb[i] > 0) {
                ans += bb[i];
            }
        }
        writeln(ans);
        return 0;
    }
}

int main() {
    return pufanyi::Main();
}
