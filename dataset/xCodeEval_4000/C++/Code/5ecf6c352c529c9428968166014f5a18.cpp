

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

const int maxn = 2666;
const int jd = 2333;
const int mod = 998244353;

int n, k;
int aa[maxn];
int bb[maxn];

inline int nxt(int x) {
	x++;
	if (x > n) {
		x = 1;
	}
	return x;
}

inline int pre(int x) {
	x--;
	if (x < 1) {
		x = n;
	}
	return x;
}

inline void add(int& x, int y) {
	x += y;
	if (x >= mod) {
		x -= mod;
	}
}

int f[maxn][maxn * 2];

int main() {
	read(n), read(k);
	for (int i = 1; i <= n; ++i) {
		read(aa[i]);
		bb[pre(i)] = aa[i];
	}
	f[0][jd] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = jd - n; j <= jd + n; ++j) {
			if (aa[i] == bb[i]) {
				f[i][j] = (LL) f[i - 1][j] * k % mod;
			} else {
				f[i][j] = (LL) f[i - 1][j] * (k - 2) % mod;
				add(f[i][j], f[i - 1][j - 1]);
				add(f[i][j], f[i - 1][j + 1]);
			}
		}
	}
	int ans = 0;
	for (int i = jd + 1; i <= jd + n; ++i) {
		add(ans, f[n][i]);
	}
	writeln(ans);
	return 0;
}
