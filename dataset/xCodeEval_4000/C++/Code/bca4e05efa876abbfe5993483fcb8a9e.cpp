

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

const int maxn = 100005;

int n;

struct Edge {
    int to, nxt;
} e[maxn << 1];

int first[maxn];
int du[maxn];

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

int fa[maxn];
int vis[maxn];
int dist[maxn];
int siz[maxn];
int rt = 0;

inline int bfs(int x) {
    queue<int> q;
    while (!q.empty()) {
        q.pop();
    }
    q.push(x);
    memset(dist, 0, sizeof(dist));
    memset(fa, 0, sizeof(fa));
    dist[x] = 1;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int i = first[now]; i; i = e[i].nxt) {
            int to = e[i].to;
            if (!dist[to]) {
                dist[to] = dist[now] + 1;
                q.push(to);
                fa[to] = now;
            }
        }
    }
    int rt = 1;
    for (int i = 1; i <= n; ++i) {
        if (dist[i] > dist[rt]) {
            rt = i;
        }
    }
    return rt;
}

int md[maxn];

inline void dfs(int now, int fa) {
    md[now] = 1;
    int cnt = 0;
    for (int i = first[now]; i; i = e[i].nxt) {
        int to = e[i].to;
        if (to != fa) {
            dfs(to, now);
            md[now] = md[to] + 1;
            cnt++;
        }
    }
    if (cnt > 1) {
        md[now] = 0;
    }
}

int Dst[maxn];
int dmd[maxn];

inline bool check(int ans) {
    queue<int> q;
    q.push(ans);
    memset(Dst, 0, sizeof(Dst));
    memset(dmd, 0, sizeof(dmd));
    Dst[ans] = 1;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int i = first[now]; i; i = e[i].nxt) {
            int to = e[i].to;
            if (!Dst[to]) {
                q.push(to);
                Dst[to] = Dst[now] + 1;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (dmd[Dst[i]] && dmd[Dst[i]] != du[i]) {
            return false;
        }
        dmd[Dst[i]] = du[i];
    }
    return true;
}

inline int pa(int x, int y) {
    bool flg = true;
    while (flg) {
        flg = false;
        for (int i = first[y]; i; i = e[i].nxt) {
            int to = e[i].to;
            if (to != x) {
                flg = true;
                x = y;
                y = to;
                break;
            }
        }
    }


    return y;
}

int main() {
    read(n);
    for (int i = 1; i < n; ++i) {
        int u, v;
        read(u), read(v);
        add_edge(u, v);
    }
    int x = bfs(1);
    int y = bfs(x);
    vector<int> dfc;
    dfc.empty();
    dfc.push_back(y);
    while (y != x) {
        dfc.push_back(y = fa[y]);
    }
    if (~dfc.size() & 1) {
        if (check(dfc[0])) {
            writeln(dfc[0]);
        } else if (check(dfc[dfc.size() - 1])) {
            writeln(dfc[dfc.size() - 1]);
        } else {
            puts("-1");
        }
        return 0;
    }








    int l, r;
    for (l = 0, r = dfc.size() - 1; l < r; ++l, --r);
    int ans = dfc[l];


    if (check(ans)) {
        writeln(ans);
        return 0;
    }
    dfs(ans, 0);
    map<int, int> dfcmd;


    for (int i = first[ans]; i; i = e[i].nxt) {
        int to = e[i].to;
        if (md[to]) {




            dfcmd[md[to]]++;
        }
    }
    int xx = 0;
    for (auto x : dfcmd) {
        if (x.second & 1) {
            xx = x.first;
        }
    }


    if (!xx) {
        puts("-1");
        return 0;
    }
    for (int i = first[ans]; i; i = e[i].nxt) {
        int to = e[i].to;
        if (md[to] == xx) {


            ans = pa(ans, to);
        }
    }


    if (check(ans)) {
        writeln(ans);
    } else {
        puts("-1");
    }
    return 0;
}


