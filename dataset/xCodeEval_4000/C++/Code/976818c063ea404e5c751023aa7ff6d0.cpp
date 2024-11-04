

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

typedef long long LL;

inline char gc() {
    static const LL L = 233333;
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

const int maxn = 2000005;
const int mod = 1000000007;

typedef long long LL;

int n;
LL k;
int ch[maxn][2];
int a[maxn];
int b[maxn];
LL qz[maxn];
int siz[maxn];

int tot = 0;
inline int get(int x) {
    if (!x) {
        x = ++tot;
    }
    return x;
}

int main() {
    read(n), read(k);
    for (int i = 2, fa; i <= n; ++i) {
        LL x;
        read(fa), read(x);
        qz[i] = qz[fa] ^ x;
    }










    LL ans = 0;
    for (int i = 63; ~i; --i) {
        memset(ch, 0, sizeof(ch));
        memset(siz, 0, sizeof(siz));
        tot = 0;
        for (int j = 1; j <= n; ++j) {
            siz[a[j] = ch[a[j]][(qz[j] >> i) & 1] = get(ch[a[j]][(qz[j] >> i) & 1])]++;
        }
        LL s = 0;
        for (int j = 1; j <= n; ++j) {
            s += siz[ch[b[j]][(qz[j] >> i) & 1]];
        }


        int t = 0;
        if (s < k) {
            ans |= (1LL << i);
            t = 1;
            k -= s;
        }
        for (int j = 1; j <= n; ++j) {
            b[j] = get(ch[b[j]][((qz[j] >> i) & 1) ^ t]);
        }
    }
    writeln(ans);
    return 0;
}