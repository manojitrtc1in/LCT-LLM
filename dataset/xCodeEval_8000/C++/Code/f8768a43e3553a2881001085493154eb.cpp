#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

const int N = 5000, M = 10000;

struct edge { int t, l, r; edge *n; } ebf[M], *ec = ebf, *e[N];

inline void add_edge (int s, int t, int l, int r)
{
    *ec = (edge){t, l, r, e[s]}; e[s] = ec++;
    *ec = (edge){s, l, r, e[t]}; e[t] = ec++;
}

int vis[N], n, m;
queue<int> que;
inline bool check (int l, int r)
{
    fill(vis, vis + 1 + n, 0);
    vis[1] = true;
    while (! que.empty()) que.pop();
    que.push(1);
    while (! que.empty())
    {
        int x = que.front(); que.pop();
        for (edge *i = e[x]; i; i = i->n)
            if (i->l <= l && r <= i->r && !vis[i->t])
            {
                vis[i->t] = true;
                que.push(i->t);
            }
    }
    return vis[n];
}

int axis[N * 2], acnt;

int main ()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i)
    {
        int a, b, l, r;
        scanf("%d%d%d%d", &a, &b, &l, &r);
        add_edge(a, b, l, r);
        axis[++acnt] = l;
        axis[++acnt] = r;
    }
    sort(axis + 1, axis + 1 + acnt);
    acnt = unique(axis + 1, axis + 1 + acnt) - (axis + 1);
    axis[0] = -1;
    axis[acnt + 1] = axis[acnt] + 1;
    int res = -1;
    for (int lID = 1; lID <= acnt; ++lID)
    {
        if (! check(axis[lID], axis[lID]))
            continue;
        int lo = lID, hi = acnt + 1; 

        while (lo + 1 != hi)
        {
            int mi = (lo + hi) >> 1;
            if (check(axis[lID], axis[mi]))
                lo = mi;
            else
                hi = mi;
        }
        res = max(res, axis[lo] - axis[lID] + 1);
    }
    if (res == -1) printf("Nice work, Dima!\n");
    else printf("%d\n", res);
}


















































































