#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define N (100 * 1000 + 13)

typedef long long li;
typedef long double ld;

typedef struct {
    int x;
    int y;
} pt;

typedef struct {
    int s;
    li sum;
    li minsum;
} node;

int n;
pt a[N];

bool read() {
    if (scanf("%d", &n) != 1)
        return false;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i].x);
        if (a[i].x == 1) {
            scanf("%d%d", &a[i].y, &a[i + 1].x);
        } else if (a[i].x == 2) {
            scanf("%d", &a[i].y);
        } else if (a[i].x == 3) {
            scanf("%d%d%d", &a[i].y, &a[i + 1].x, &a[i + 1].y);
        }
    }
    return true;
}

int vals[N];

node t[4 * N];

node merge(node a, node b) {
    node c;
    c.s = 0;
    c.sum = a.sum + b.sum;
    c.minsum = fmin(a.minsum, a.sum + b.minsum);
    return c;
}

void build(int v, int l, int r) {
    if (l == r - 1) {
        if (l == 0)
            t[v] = (node) {0, INF + 1, INF + 1};
        else
            t[v] = (node) {0, 0, 0};
        return;
    }
    int m = (l + r) / 2;
    build(v * 2, l, m);
    build(v * 2 + 1, m, r);
    t[v] = merge(t[v * 2], t[v * 2 + 1]);
}

void upd(int v, int l, int r, int pos, pt val) {
    if (l == r - 1) {
        t[v] = (node) {val.x, val.y, val.y};
        return;
    }
    int m = (l + r) / 2;
    if (pos < m)
        upd(v * 2, l, m, pos, val);
    else
        upd(v * 2 + 1, m, r, pos, val);
    t[v] = merge(t[v * 2], t[v * 2 + 1]);
}

int val[N];
int len[N];

ld ask(int v, int l, int r, int L, int R, li *x) {
    if (L >= R)
        return 2 * INF;
    if (l == L && r == R) {
        if (t[v].minsum + *x > 0) {
            *x += t[v].sum;
            return 2 * INF;
        }
        while (l < r - 1) {
            int m = (l + r) / 2;
            if (t[v * 2].minsum + *x <= 0) {
                r = m;
                v = v * 2;
            } else {
                *x += t[v * 2].sum;
                l = m;
                v = v * 2 + 1;
            }
        }
        if (*x == 0)
            return vals[l];
        assert(t[v].minsum + *x <= 0);
        assert(t[v].s < 0);
        ld res = vals[l] + (*x / ld(-t[v].s));
        *x = 0;
        return res;
    }
    int m = (l + r) / 2;
    ld tmp = ask(v * 2, l, m, L, fmin(m, R), x);
    if (*x == 0)
        return tmp;
    assert(*x > 0);
    return ask(v * 2 + 1, m, r, fmax(m, L), R, x);
}

void solve() {
    int vals_size = 0;
    for (int i = 0; i < n; i++)
        if (a[i].x == 1)
            vals[vals_size++] = a[i].y;
    vals[vals_size++] = 0;
    vals[vals_size++] = INF + 1;
    qsort(vals, vals_size, sizeof(int), cmpfunc);
    int vals_new_size = 1;
    for (int i = 1; i < vals_size; i++)
        if (vals[i] != vals[i - 1])
            vals[vals_new_size++] = vals[i];
    int cur_size = 0;
    int cur[vals_new_size];
    build(1, 0, vals_new_size);
    val[0] = 0;
    len[0] = INF + 1;
    cur[cur_size++] = 0;
    cur[cur_size++] = vals_new_size - 1;
    for (int i = 0; i < n; i++) {
        if (a[i].x == 1) {
            int pos = lower_bound(vals, vals + vals_new_size, a[i].y) - vals;
            int pos2 = lower_bound(cur, cur + cur_size, pos) - cur;
            val[pos] = a[i + 1].x;
            pos2--;
            len[cur[pos2]] = vals[pos] - vals[cur[pos2]];
            upd(1, 0, vals_new_size, cur[pos2], (pt) {val[cur[pos2]], len[cur[pos2]]});
            pos2++;
            len[pos] = vals[cur[pos2]] - vals[pos];
            upd(1, 0, vals_new_size, pos, (pt) {val[pos], len[pos]});
            cur[cur_size++] = pos;
        } else if (a[i].x == 2) {
            int pos = lower_bound(vals, vals + vals_new_size, a[i].y) - vals;
            int pos2 = lower_bound(cur, cur + cur_size, pos) - cur;
            val[cur[pos2]] = len[cur[pos2]] = 0;
            upd(1, 0, vals_new_size, cur[pos2], (pt) {val[cur[pos2]], len[cur[pos2]]});
            pos2 = cur[pos2];
            pos2--;
            int l = vals[cur[pos2]];
            pos2++;
            l -= vals[cur[pos2]];
            len[cur[pos2]] = l;
            upd(1, 0, vals_new_size, cur[pos2], (pt) {val[cur[pos2]], len[cur[pos2]]});
            cur_size--;
        } else {
            int l = lower_bound(vals, vals + vals_new_size, a[i].y) - vals;
            int *lit = lower_bound(cur, cur + cur_size, l);
            int r = a[i].x;
            li x = a[i].y;
            if (x == 0) {
                printf("%.15Lf\n", (ld) a[i].y);
                continue;
            }
            ld res = ask(1, 0, vals_new_size, *lit, vals_new_size, &x);
            if (x == 0 && res < r + EPS)
                printf("%.15Lf\n", res);
            else
                puts("-1");
        }
    }
}

int main() {
    while (read()) {
        solve();
    }
    return 0;
}
