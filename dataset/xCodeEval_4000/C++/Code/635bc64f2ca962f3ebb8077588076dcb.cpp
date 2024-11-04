

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
    const int inf = 0x3f3f3f3f;
    
    int n;
    
    struct Edge {
        int to, nxt;
    } e[maxn << 1];
    
    int du[maxn];
    int first[maxn];
    
    inline void add_edge(int u, int v) {
        static int cnt = 0;
        du[u]++, du[v]++;
        e[++cnt].nxt = first[u];
        first[u] = cnt;
        e[cnt].to = v;
        e[++cnt].nxt = first[v];
        first[v] = cnt;
        e[cnt].to = u;
    }
    
    int ansalb = 0;
    int flg = 1;
    
    inline int dfs(int now, int fa) {
        int alb = 0;
        int nowans = -1;
        for (int i = first[now]; i; i = e[i].nxt) {
            int to = e[i].to;
            if (to != fa) {
                int albb = dfs(to, now);
                if (du[to] == 1) {
                    alb++;
                }
                albb ^= 1;
                if (nowans == -1) {
                    nowans = albb;
                } else if (nowans != albb) {
                    flg = 3;
                }
            }
        }
        if (alb) {
            alb--;
        }
        ansalb += alb;
        if (nowans == -1) {
            nowans = 0;
        }
        return nowans;
    }
    
    int main() {
        read(n);
        for (int i = 1, u, v; i < n; ++i) {
            read(u), read(v);
            add_edge(u, v);
        }
        int rt = 1;
        for (int i = 1; i <= n; ++i) {
            if (du[i] >= 2) {
                rt = i;
                break;
            }
        }
        dfs(rt, 0);
        writesp(flg);
        writeln(n - ansalb - 1);
        return 0;
    }
}

int main() {
    return dfcmd::main();
}