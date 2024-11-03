#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF 0x3f3f3f3f

typedef long long LL;

int n, m, s, t;
LL flow, cost;
int mask = 65535;

int D[65536], hd[65536], suc[1000009], to[1000009], cap[1000009], cst[1000009];

void add_edge(int x, int y, int c, int w) {
    suc[m] = hd[x], to[m] = y, cap[m] = c, cst[m] = w, hd[x] = m++;
    suc[m] = hd[y], to[m] = x, cap[m] = 0, cst[m] = -w, hd[y] = m++;
}

void id11(int x, int y, int c, int w) {
    if (!w) {
        suc[m] = hd[x], to[m] = y, cap[m] = c, cst[m] = 0, hd[x] = m++;
        suc[m] = hd[y], to[m] = x, cap[m] = c, cst[m] = 0, hd[y] = m++;
    } else {
        add_edge(x, y, c, w);
        add_edge(y, x, c, w);
    }
}

bool spfa() {
    int cz = 0, op = 1;
    int inQ[65536] = {0};
    memset(D, INF, sizeof(D));
    D[Q[cz] = s] = 0;
    F[s] = INF;
    while (cz < op) {
        int u = Q[cz++ & mask];
        inQ[u] = 0;
        for (int i = hd[u]; ~i; i = suc[i]) {
            int v = to[i], c = cap[i], w = cst[i];
            if (c && D[v] > D[u] + w) {
                D[v] = D[u] + w;
                F[v] = F[u] < c ? F[u] : c;
                pre[v] = i;
                if (!inQ[v]) {
                    Q[op++ & mask] = v;
                    inQ[v] = 1;
                }
            }
        }
    }
    return D[t] != INF;
}

