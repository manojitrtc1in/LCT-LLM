#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INF 1000000000
#define MAXN 100

int D[MAXN], hd[MAXN], suc[MAXN*MAXN], to[MAXN*MAXN], cap[MAXN*MAXN], cst[MAXN*MAXN];
int n, m, s, t;
long long flow, cost;
int mask = 65535;

void add_edge(int x, int y, int c, int w){
    suc[m] = hd[x], to[m] = y, cap[m] = c, cst[m] =  w, hd[x] = m++;
    suc[m] = hd[y], to[m] = x, cap[m] = 0, cst[m] = -w, hd[y] = m++;
}

void id11(int x, int y, int c, int w){
    if (!w){
        suc[m] = hd[x], to[m] = y, cap[m] = c, cst[m] = 0, hd[x] = m++;
        suc[m] = hd[y], to[m] = x, cap[m] = c, cst[m] = 0, hd[y] = m++;
    } else {
        add_edge(x, y, c, w);
        add_edge(y, x, c, w);
    }
}

void id5(int x, int y, int c, int w){
    id11(x, y, c, 0), id11(x, y, INF, w);
}

bool spfa(){
    int cz = 0, op = 1;
    bool inQ[MAXN];
    for (int i = 0; i < n; i++) {
        inQ[i] = false;
        D[i] = INF;
    }
    D[s] = 0;
    int Q[MAXN];
    Q[cz] = s;
    inQ[s] = true;
    while (cz < op) {
        int u = Q[cz++ & mask];
        inQ[u] = false;
        for (int i = hd[u]; i != -1; i = suc[i]) {
            int v = to[i];
            int c = cap[i];
            int w = cst[i];
            if (c && D[v] > D[u] + w) {
                D[v] = D[u] + w;
                pre[v] = i;
