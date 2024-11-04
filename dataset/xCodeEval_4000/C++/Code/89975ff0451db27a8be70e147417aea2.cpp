

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

    const int maxn = 100005;
    const int inf = 0x3f3f3f3f;

    int n1, n2, m, R, B, S, T, SS, TT;

    char s1[maxn];
    char s2[maxn];
    
    struct Edge {
        int to, nxt, cap, cost;
    } e[maxn << 1];

    int first[maxn];

    inline int add_edge(int from, int to, int cap, int cost) {
        

        static int cnt = -1;
        e[++cnt].nxt = first[from];
        first[from] = cnt;
        e[cnt].to = to;
        e[cnt].cap = cap;
        e[cnt].cost = cost;
        e[++cnt].nxt = first[to];
        first[to] = cnt;
        e[cnt].to = from;
        e[cnt].cap = 0;
        e[cnt].cost = -cost;
        return cnt;
    }

    inline void add(int from, int to, int L, int R, int cost) {
        if (R - L > 0) {
            add_edge(from, to, R - L, cost);
        }
        if (L > 0) {
            

            add_edge(from, TT, L, 0);
            add_edge(SS, to, L, 0);
        }
    }

    inline void add_left(int u) {
        if (s1[u] == 'R') {
            add(S, u, 1, inf, 0);
        } else if (s1[u] == 'B') {
            add(u, T, 1, inf, 0);
        } else {
            add(S, u, 0, inf, 0);
            add(u, T, 0, inf, 0);
        }
    }

    inline void add_right(int u) {
        if (s2[u] == 'B') {
            add(S, u + n1, 1, inf, 0);
        } else if (s2[u] == 'R') {
            add(u + n1, T, 1, inf, 0);
        } else {
            add(S, u + n1, 0, inf, 0);
            add(u + n1, T, 0, inf, 0);
        }
    }

    int dist[maxn];
    int inq[maxn];
    int fa[maxn];
    int ans;

    inline bool bfs(int S, int T) {
        queue<int> q;
        while (!q.empty()) {
            q.pop();
        }
        for (int i = 1; i <= T; ++i) {
            dist[i] = inf;
            inq[i] = 0;
        }
        q.push(S);
        dist[S] = 0;
        inq[S] = 1;
        fa[S] = -1;
        while (!q.empty()) {
            int now = q.front();
            q.pop();
            inq[now] = 0;
            

            for (int i = first[now]; ~i; i = e[i].nxt) {
                int to = e[i].to;
                

                if (e[i].cap && dist[to] > dist[now] + e[i].cost) {
                    fa[to] = i;
                    dist[to] = dist[now] + e[i].cost;
                    if (!inq[to]) {
                        inq[to] = 1;
                        q.push(to);
                    }
                }
            }
        }
        if (dist[T] >= inf) {
            return false;
        }
        ans += dist[T];
        for (int i = fa[T]; ~i; i = fa[e[i ^ 1].to]) {
            e[i].cap--;
            e[i ^ 1].cap++;
        }
        return true;
    }

    int id1[maxn], id2[maxn];

    int Main() {
        memset(first, 0xff, sizeof(first));
        scanf("%d%d%d%d%d", &n1, &n2, &m, &R, &B);
        scanf("%s%s", s1 + 1, s2 + 1);
        for (int i = 1; i <= m; ++i) {
            int u, v;
            read(u), read(v);
            id1[i] = add_edge(u, v + n1, 1, R);
            id2[i] = add_edge(v + n1, u, 1, B);
        }
        S = n1 + n2 + 1, T = S + 1, SS = T + 1, TT = SS + 1;
        

        for (int i = 1; i <= n1; ++i) {
            add_left(i);
        }
        for (int i = 1; i <= n2; ++i) {
            add_right(i);
        }
        add(T, S, 0, inf, 0);
        while (bfs(SS, TT));
        string Ans = "";
        for (int i = first[SS]; ~i; i = e[i].nxt) {
            

            if (e[i].cap) {
                puts("-1");
                return 0;
            }
        }
        writeln(ans);
        for (int i = 1; i <= m; ++i) {
            if (e[id1[i]].cap) {
                putchar('R');
            } else if (e[id2[i]].cap) {
                putchar('B');
            } else {
                putchar('U');
            }
        }
        puts("");
        return 0;
    }
}

int main() {
    return pufanyi::Main();
}
