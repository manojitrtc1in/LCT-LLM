
 
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
 
const int maxn = 200005;
 
#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)
 
struct Tree {
	int no[maxn << 2];
 
	inline void build_tree() {
		memset(no, 0, sizeof(no));
	}
 
	inline void add(int l, int r, int k, int K) {
		no[k]++;
		

		if (l == r) {
			return;
		}
		int mid = (l + r) >> 1;
		if (K <= mid) {
			add(l, mid, ls(k), K);
		} else {
			add(mid + 1, r, rs(k), K);
		}
	}
 
	inline int query(int l, int r, int k, int K) {
		

		if (l == r) {
			return l;
		}
		int mid = (l + r) >> 1;
		if (K <= no[ls(k)]) {
			return query(l, mid, ls(k), K);
		} else {
			return query(mid + 1, r, rs(k), K - no[ls(k)]);
		}
	}
} tr;
 
struct Pair {
	int x, y;
 
	friend bool operator < (const Pair& a, const Pair& b) {
		return a.x > b.x || (a.x == b.x && a.y < b.y);
	}
} p[maxn];
 
int n, m;
 
struct ASK {
	int pos, k, id;
 
	friend bool operator < (const ASK& a, const ASK& b) {
		return a.k < b.k;
	}
} ask[maxn];
 
int ans[maxn];
int aa[maxn];
 
int main() {
	tr.build_tree();
	read(n);
	for (int i = 1; i <= n; ++i) {
		read(aa[i]);
		p[i].x = aa[i];
		p[i].y = i;
	}
	sort(p + 1, p + n + 1);
	read(m);
	for (int i = 1; i <= m; ++i) {
		read(ask[i].k);
		read(ask[i].pos);
		ask[i].id = i;
	}
	sort(ask + 1, ask + m + 1);
	int now = 1;
	for (int i = 1; i <= n; ++i) {
		tr.add(1, n, 1, p[i].y);
		

		while (now <= m && ask[now].k == i) {
			

			ans[ask[now].id] = tr.query(1, n, 1, ask[now].pos);
			now++;
		}
	}
	for (int i = 1; i <= m; ++i) {
		writeln(aa[ans[i]]);
	}
	return 0;
}