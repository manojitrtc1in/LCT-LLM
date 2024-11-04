

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

typedef long long LL;

const int maxn = 2005;
const int mod = 1000000007;

int n, m;
int f[maxn][maxn][2];
char c[maxn][maxn];
int yy[maxn][maxn];
int xx[maxn][maxn];
int sy[maxn][maxn][2];
int sx[maxn][maxn][2];

inline void add(int& x, int y) {
	x += y;
	if (x >= mod) {
		x -= mod;
	} else if (x < 0) {
		x += mod;
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%s", c[i] + 1);
	}
	if (c[n][m] == 'R') {
		puts("0");
		return 0;
	}
	for (int i = n; i; --i) {
		for (int j = m; j; --j) {
			if (c[i][j] == 'R') {
				yy[i][j]++;
				xx[i][j]++;
			}
			yy[i][j] += yy[i][j + 1];
			xx[i][j] += xx[i + 1][j];
		}
	}
	f[n][m][0] = f[n][m][1] = sy[n][m][0] = sy[n][m][1] = sx[n][m][0] = sx[n][m][1] = 1;
	for (int i = n - 1; i; --i) {
		f[i][m][0] = f[i][m][1] = (f[i + 1][m][0] && (c[i][m] != 'R'));
		sy[i][m][0] = sy[i][m][1] = f[i][m][0];
		sx[i][m][0] = sx[i][m][1] = sx[i + 1][m][0] + f[i][m][0];
	}
	for (int i = m - 1; i; --i) {
		f[n][i][0] = f[n][i][1] = (f[n][i + 1][0] && (c[n][i] != 'R'));
		sy[n][i][0] = sy[n][i][1] = sy[n][i + 1][0] + f[n][i][0];
		sx[n][i][0] = sx[n][i][1] = f[n][i][0];
	}
	for (int i = n - 1; i; --i) {
		for (int j = m - 1; j; --j) {
			if (c[i][j] == 'R') {
				int yyy = yy[i][j];
				int xxx = xx[i][j] - 1;
				int zyy = m - yyy;
				int zxx = n - xxx;


				if (j + yy[i][j] <= m) {
					add(f[i][j][0], (sy[i + 1][j + 1][1] - sy[i + 1][zyy + 1][1]) % mod);
					add(f[i][j][0], (sx[i + 1][j + 1][0] - sx[zxx + 1][j + 1][0]) % mod);
				}
				yyy = yy[i][j] - 1;
				xxx = xx[i][j];
				zyy = m - yyy;
				zxx = n - xxx;
				if (i + xx[i][j] <= n) {
					add(f[i][j][1], (sy[i + 1][j + 1][1] - sy[i + 1][zyy + 1][1]) % mod);
					add(f[i][j][1], (sx[i + 1][j + 1][0] - sx[zxx + 1][j + 1][0]) % mod);
				}
			} else {
				int yyy = yy[i][j];
				int xxx = xx[i][j];
				int zyy = m - yyy;
				int zxx = n - xxx;
				add(f[i][j][0], (sy[i + 1][j + 1][1] - sy[i + 1][zyy + 1][1]) % mod);
				add(f[i][j][0], (sx[i + 1][j + 1][0] - sx[zxx + 1][j + 1][0]) % mod);
				f[i][j][1] = f[i][j][0];
			}
			sx[i][j][0] = (sx[i + 1][j][0] + f[i][j][0]) % mod;
			sx[i][j][1] = (sx[i + 1][j][1] + f[i][j][1]) % mod;
			sy[i][j][0] = (sy[i][j + 1][0] + f[i][j][0]) % mod;
			sy[i][j][1] = (sy[i][j + 1][1] + f[i][j][1]) % mod;
		}
	}




























	printf("%d\n", (f[1][1][0] + mod) % mod);
	return 0;
}