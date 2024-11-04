#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <assert.h>

typedef long long li;
typedef struct {
    int x, y;
} pt;

typedef struct {
    int s;
    li sum, minsum;
} node;

node t[4 * 100013];
int n;
pt a[100013];
int val[100013];
int len[100013];
int vals[200026];
int vals_size = 0;

li INF64 = 1e18;
int INF = 1e9;
int MOD = INF + 7;
double EPS = 1e-9;

node merge(node a, node b) {
    node c = {0, 0, 0};
    c.sum = a.sum + b.sum;
    c.minsum = fmin(a.minsum, a.sum + b.minsum);
    return c;
}

void build(int v, int l, int r) {
    if (l == r - 1) {
        if (l == 0)
            t[v] = (node){0, INF + 1, 0};
        else
            t[v] = (node){0, 0, 0};
        return;
    }
    int m = (l + r) / 2;
    build(v * 2, l, m);
    build(v * 2 + 1, m, r);
    t[v] = merge(t[v * 2], t[v * 2 + 1]);
}

void upd(int v, int l, int r, int pos, pt val) {
    if (l == r - 1) {
        t[v] = (node){val.x, val.y, val.x < 0 ? val.x * (li)val.y : 0};
        return;
    }
    int m = (l + r) / 2;
    if (pos < m)
        upd(v * 2, l, m, pos, val);
    else
        upd(v * 2 + 1, m, r, pos, val);
    t[v] = merge(t[v * 2], t[v * 2 + 1]);
}

double ask(int v, int l, int r, int L, int R, li *x) {
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
        double res = vals[l] + ((double)(*x) / (double)(-t[v].s));
        *x = 0;
        return res;
    }
    int m = (l + r) / 2;
    double tmp = ask(v * 2, l, m, L, fmin(m, R), x);
    if (*x == 0) return tmp;
    assert(*x > 0);
    return ask(v * 2 + 1, m, r, fmax(m, L), R, x);
}

int read() {
    if (scanf("%d", &n) != 1)
        return 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i].x);
        if (a[i].x == 1) {
            scanf("%d%d", &a[i].y, &a[i].y);
        } else if (a[i].x == 2) {
            scanf("%d", &a[i].y);
        } else if (a[i].x == 3) {
            scanf("%d%d%d", &a[i].y, &a[i].y, &a[i].y);
        }
    }
    return 1;
}

void solve() {
    vals_size = 0;
    for (int i = 0; i < n; i++) if (a[i].x == 1)
        vals[vals_size++] = a[i].y;
    vals[vals_size++] = 0;
    vals[vals_size++] = INF + 1;
    qsort(vals, vals_size, sizeof(int), cmpfunc);
    vals_size = unique(vals, vals + vals_size) - vals;
    
    build(1, 0, vals_size);
    
    val[0] = 0;
    len[0] = INF + 1;
    
    for (int i = 0; i < n; i++) {
        if (a[i].x == 1) {
            int pos = lower_bound(vals, vals + vals_size, a[i].y) - vals;
            val[pos] = a[i].y;
            len[pos] = vals[pos + 1] - vals[pos];
            upd(1, 0, vals_size, pos, (pt){val[pos], len[pos]});
        } else if (a[i].x == 2) {
            int pos = lower_bound(vals, vals + vals_size, a[i].y) - vals;
            val[pos] = len[pos] = 0;
            upd(1, 0, vals_size, pos, (pt){val[pos], len[pos]});
        } else {
            int l = lower_bound(vals, vals + vals_size, a[i].y) - vals;
            int r = a[i].y;
            li x = a[i].y;
            if (x == 0) {
                printf("%.15lf\n", (double)a[i].y);
                continue;
            }
            double res = ask(1, 0, vals_size, l, vals_size, &x);
            if (x == 0 && res < r + EPS)
                printf("%.15lf\n", res);
            else
                puts("-1");
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    while (read()) {
        solve();
    }
    return 0;
}
