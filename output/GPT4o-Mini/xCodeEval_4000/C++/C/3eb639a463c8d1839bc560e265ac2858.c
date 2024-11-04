#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define INF (int)(1e9)
#define INF64 (long long)(1e18)
#define MOD (INF + 7)
#define EPS 1e-9
#define PI acos(-1.0)

#define N (100 * 1000 + 13)

typedef struct {
    int x, y;
} pt;

typedef struct {
    int s;
    long long sum, minsum;
} node;

int n;
pt a[N];
long long vals[N];
node t[4 * N];
int val[N], len[N];
int cur[N];

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
        t[v] = (node){val.x, val.y, (val.x < 0 ? val.x * (long long)(val.y) : 0)};
        return;
    }
    int m = (l + r) / 2;
    if (pos < m)
        upd(v * 2, l, m, pos, val);
    else
        upd(v * 2 + 1, m, r, pos, val);
    t[v] = merge(t[v * 2], t[v * 2 + 1]);
}

long double ask(int v, int l, int r, int L, int R, long long *x) {
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
        long double res = vals[l] + ((long double)(*x) / (long double)(-t[v].s));
        *x = 0;
        return res;
    }
    int m = (l + r) / 2;
    long double tmp = ask(v * 2, l, m, L, fmin(m, R), x);
    if (*x == 0) return tmp;
    return ask(v * 2 + 1, m, r, fmax(m, L), R, x);
}

void solve() {
    int vals_size = 0;
    for (int i = 0; i < n; i++) if (a[i].x == 1)
        vals[vals_size++] = a[i].y;
    vals[vals_size++] = 0;
    vals[vals_size++] = INF + 1;
    qsort(vals, vals_size, sizeof(long long), cmp);
    vals_size = unique(vals, vals + vals_size) - vals;
    
    build(1, 0, vals_size);
    
    val[0] = 0;
    len[0] = INF + 1;
    
    for (int i = 0; i < n; i++) {
        if (a[i].x == 1) {
            int pos = lower_bound(vals, vals + vals_size, a[i].y) - vals;
            int pos2 = lower_bound(cur, cur + vals_size, pos) - cur;
            val[pos] = a[i].y; 
            --pos2;
            len[cur[pos2]] = vals[pos] - vals[cur[pos2]];
            upd(1, 0, vals_size, cur[pos2], (pt){val[cur[pos2]], len[cur[pos2]]});
            ++pos2;
            len[pos] = vals[cur[pos2]] - vals[pos];
            upd(1, 0, vals_size, pos, (pt){val[pos], len[pos]});
            cur[pos] = pos;
        } else if (a[i].x == 2) {
            int pos = lower_bound(vals, vals + vals_size, a[i].y) - vals;
            int pos2 = lower_bound(cur, cur + vals_size, pos) - cur;
            val[cur[pos2]] = len[cur[pos2]] = 0;
            upd(1, 0, vals_size, cur[pos2], (pt){val[cur[pos2]], len[cur[pos2]]});
            pos2 = erase(cur, cur + vals_size, pos2);
            int l = vals[cur[pos2]];
            --pos2;
            l -= vals[cur[pos2]];
            len[cur[pos2]] = l;
            upd(1, 0, vals_size, cur[pos2], (pt){val[cur[pos2]], len[cur[pos2]]});
        } else {
            int l = lower_bound(vals, vals + vals_size, a[i].y) - vals;
            int lit = lower_bound(cur, cur + vals_size, l) - cur;
            int r = a[i].y;
            long long x = a[i].y;
            if (x == 0) {
                printf("%.15Lf\n", (long double)(a[i].y));
                continue;
            }
            long double res = ask(1, 0, vals_size, cur[lit], vals_size, &x);
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
}
