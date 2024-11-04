#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define N 65536
#define M (int)(1e6) + 9
#define INF 0x3f3f3f3f

int D[N], hd[N], suc[M], to[M], cap[M], cst[M];
int n, m, s, t; long long flow, cost; int mask = 65535;

void add_edge(int x, int y, int c, int w) {
    suc[m] = hd[x]; to[m] = y; cap[m] = c; cst[m] = w; hd[x] = m++;
    suc[m] = hd[y]; to[m] = x; cap[m] = 0; cst[m] = -w; hd[y] = m++;
}

void id11(int x, int y, int c, int w) {
    if (!w) {
        suc[m] = hd[x]; to[m] = y; cap[m] = c; cst[m] = 0; hd[x] = m++;
        suc[m] = hd[y]; to[m] = x; cap[m] = c; cst[m] = 0; hd[y] = m++;
    } else {
        add_edge(x, y, c, w);
        add_edge(y, x, c, w);
    }
}

void id5(int x, int y, int c, int w) {
    id11(x, y, c, 0); id11(x, y, INF, w);
}

int Q[N], F[N], pre[N], cz, op; bool inQ[N];

bool spfa() {
    cz = 0; op = 1; memset(inQ, 0, sizeof(inQ)); memset(D, INF, sizeof(D));
    D[Q[cz] = s] = 0; F[s] = INF; 
    while (cz < op) {
        int u = Q[cz++ & mask]; inQ[u] = 0;
        for (int i = hd[u]; i != -1; i = suc[i]) {
            int v = to[i], c = cap[i], w = cst[i];
            if (c && D[v] > D[u] + w) {
