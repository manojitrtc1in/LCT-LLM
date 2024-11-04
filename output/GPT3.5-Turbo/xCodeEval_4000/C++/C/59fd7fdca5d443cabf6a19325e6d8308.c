#include <stdio.h>
#include <stdlib.h>

#define MAXN 200007
#define MOD 998244353

int n, t;
int c[MAXN];
int s[MAXN][MAXN], st[MAXN][MAXN];
int deg[3][MAXN], degt[3][MAXN];

void remove_leaf(int s[][MAXN], int deg[], int v) {
    if (s[v][0] == 0) {
        deg[c[v]] = 0;
        return;
    }
    int u = s[v][0];

    deg[c[v]]--;
    deg[c[u]]--;
    for (int i = 0; i < s[u][0]; i++) {
        if (s[u][i] == v) {
            for (int j = i; j < s[u][0] - 1; j++) {
                s[u][j] = s[u][j + 1];
            }
            break;
        }
    }
    for (int i = 0; i < s[v][0]; i++) {
        if (s[v][i] == u) {
            for (int j = i; j < s[v][0] - 1; j++) {
                s[v][j] = s[v][j + 1];
            }
            break;
        }
    }
    deg[c[u]]++;
}

void erase_grey(int s[][MAXN], int deg[]) {
    while (1) {
        if (deg[0] == 0) break;
        int ret = deg[0];
        if (ret > 1) break;
        remove_leaf(s, deg, ret);
    }
}

int solve(int s[][MAXN], int deg[], int beg) {
    int res = 0;
    erase_grey(s, deg);
    while (1) {
        if (deg[0] == 0 && deg[1] == 0 && deg[2] == 0) break;
        if (deg[beg] == 0) {
            beg = 3 - beg;
            continue;
        }
        res++;
        while (1) {
            if (deg[beg] == 0) break;
            int ret = deg[beg];
            if (ret > 1) break;
            remove_leaf(s, deg, ret);
            erase_grey(s, deg);
        }
        beg = 3 - beg;
    }
    return res;
}

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &c[i]);
        }
        for (int i = 1; i <= n - 1; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            s[u][s[u][0]++] = v;
            s[v][s[v][0]++] = u;
            st[u][st[u][0]++] = v;
            st[v][st[v][0]++] = u;
        }
        for (int i = 1; i <= n; i++) {
            deg[c[i]][deg[c[i]][0]++] = s[i][0];
            degt[c[i]][degt[c[i]][0]++] = st[i][0];
        }
        printf("%d ", solve(s, deg, 1) > solve(st, degt, 2) ? solve(s, deg, 1) : solve(st, degt, 2));
    }

    return 0;
}
