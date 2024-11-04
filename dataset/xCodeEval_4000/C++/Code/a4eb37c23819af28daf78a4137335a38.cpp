
 
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
 
const int maxn = 2005;
 
vector<pair<int, int> > ans;
int n, k;
char s[maxn];
char to[maxn];
 
inline void rev(int x, int y) {
	for (int i = x, j = y; i < j; ++i, --j) {
		swap(s[i], s[j]);
	}
	if (x != y) {
		ans.emplace_back(x, y);
	}
}
 
inline void solve() {
	scanf("%d%d", &n, &k);
	scanf("%s", s + 1);
	ans.clear();
	int now = 0;
	for (int i = 1; i < k; ++i) {
		to[++now] = '(';
		to[++now] = ')';
	}
	

	for (int i = now + 1; i <= (now + n) >> 1; ++i) {
		to[i] = '(';
	}
	for (int i = ((now + n) >> 1) + 1; i <= n; ++i) {
		to[i] = ')';
	}
	
	for (int i = 1; i <= n; ++i) {
		for (int j = i; j <= n; ++j) {
			if (s[j] == to[i]) {
				rev(i, j);
				break;
			}
		}
	}
	writeln(ans.size());
	for (auto x : ans) {
		writesp(x.first), writeln(x.second);
	}
}
 
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		solve();
	}
	return 0;
}
