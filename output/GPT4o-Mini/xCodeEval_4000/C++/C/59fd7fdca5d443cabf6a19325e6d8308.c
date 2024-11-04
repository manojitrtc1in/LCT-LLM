#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAXN 200007

int n, t;
int c[MAXN];
int s[MAXN][MAXN], st[MAXN][MAXN];
int deg[3][MAXN], degt[3][MAXN];
int sz_s[MAXN], sz_st[MAXN];

void remove_leaf(int s[], int deg[], int v) {
    if (sz_s[v] == 0) {
        deg[c[v]]--;
        return;
    }
    int u = s[v][0];

    deg[c[v]]--;
    deg[c[u]]--;
    sz_s[u]--;
    sz_s[v]--;
    deg[c[u]]++;
}

void erase_grey(int s[], int deg[]) {
    while (1) {
        if (deg[0] == 0) break;
        int ret = deg[0];
        if (ret > 1) break;
        remove_leaf(s, deg, ret);
    }
}

int solve(int s[], int deg[], int beg) {
    int res = 0;
    erase_grey(s, deg);
    while (1) {
        if (deg[0] == 0 && deg[1] == 0 && deg[2] == 0) break;
        if (deg[beg] == 0) { beg = 3 - beg; continue; }
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
        for (int i = 1; i < n; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            s[u][sz_s[u]++] = v;
            s[v][sz_s[v]++] = u;
            st[u][sz_st[u]++] = v;
            st[v][sz_st[v]++] = u;
        }
        for (int i = 1; i <= n; i++) {
            deg[c[i]][sz_s[i]]++;
            degt[c[i]][sz_st[i]]++;
        }
        printf("%lld ", (long long)fmax(fmin(solve(s, deg, 1), solve(st, degt, 2)), 1LL));
    }

    return 0;
}
