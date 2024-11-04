#include <stdio.h>
#include <stdlib.h>

#define len(v) ((int)v.size())
#define f(i, n) for (int i = 0; i < (n); i++)
#define mp make_pair

typedef long long ll;

typedef struct {
    int have_mod;
    int value;
    int mod;
} Node;

typedef struct {
    int *S;
    int n;
} TreeSegment;

int magic(int a, int b) {
    return a + b;
}

int apply_mod(int value, int mod, int tl, int tr) {
    return mod;
}

int merge_mods(int old, int _new, int tl, int tr) {
    return _new;
}

void init(TreeSegment *ts, int i, int tl, int tr, int *src) {
    if (tl + 1 == tr) {
        ts->S[i] = src[tl];
    } else {
        int mid = (tl + tr) / 2;
        init(ts, i + 1, tl, mid, src);
        init(ts, i + (mid - tl) * 2, mid, tr, src);
        int value = magic(ts->S[i + 1], ts->S[i + (mid - tl) * 2]);
        ts->S[i] = value;
    }
}

int get_value(TreeSegment *ts, int i, int tl, int tr) {
    if (!ts->S[i].have_mod) return ts->S[i].value;
    return apply_mod(ts->S[i].value, ts->S[i].mod, tl, tr);
}

void recalc_value(TreeSegment *ts, int i, int tl, int tr) {
    if (tl + 1 != tr) {
        int mid = (tl + tr) / 2;
        int value = magic(get_value(ts, i + 1, tl, mid), get_value(ts, i + (mid - tl) * 2, mid, tr));
        ts->S[i].value = value;
    }
}

void add_mod(TreeSegment *ts, int i, int tl, int tr, int sub) {
    if (ts->S[i].have_mod) {
        ts->S[i].mod = merge_mods(ts->S[i].mod, sub, tl, tr);
    } else {
        ts->S[i].mod = sub;
        ts->S[i].have_mod = 1;
    }
}

void push(TreeSegment *ts, int i, int tl, int tr) {
    if (ts->S[i].have_mod) {
        ts->S[i].value = apply_mod(ts->S[i].value, ts->S[i].mod, tl, tr);
        if (tl + 1 != tr) {
            int mid = (tl + tr) / 2;
            add_mod(ts, i + 1, tl, mid, ts->S[i].mod);
            add_mod(ts, i + (mid - tl) * 2, mid, tr, ts->S[i].mod);
        }
        ts->S[i].have_mod = 0;
    }
}

void update(TreeSegment *ts, int i, int tl, int tr, int ql, int qr, int mod) {
    push(ts, i, tl, tr);
    if (ql <= tl && tr <= qr) {
        add_mod(ts, i, tl, tr, mod);
    } else {
        int mid = (tl + tr) / 2;
        if (ql <= mid) {
            update(ts, i + 1, tl, mid, ql, qr, mod);
        }
        if (mid < qr) {
            update(ts, i + (mid - tl) * 2, mid, tr, ql, qr, mod);
        }
        recalc_value(ts, i, tl, tr);
    }
}

int query(TreeSegment *ts, int i, int tl, int tr, int ql, int qr) {
    push(ts, i, tl, tr);
    if (ql <= tl && tr <= qr) {
        return ts->S[i].value;
    } else {
        int mid = (tl + tr) / 2;
        int value = 0;
        if (ql <= mid && mid < qr) {
            value = magic(query(ts, i + 1, tl, mid, ql, qr), query(ts, i + (mid - tl) * 2, mid, tr, ql, qr));
        } else if (ql <= mid) {
            value = query(ts, i + 1, tl, mid, ql, qr);
        } else {
            value = query(ts, i + (mid - tl) * 2, mid, tr, ql, qr);
        }
        return value;
    }
}

void find_right(TreeSegment *ts, int i, int tl, int tr, int L, int *rez) {
    push(ts, i, tl, tr);
    if (tr <= L) {
        *rez = -1;
        return;
    }
    if (tl + 1 == tr) {
        if (ts->S[i] * 2 >= ts->S[0]) {
            *rez = tl;
        } else {
            *rez = -1;
        }
        return;
    }
    int mid = (tl + tr) / 2;
    if (L <= tl) {
        find_right(ts, i + 1, tl, mid, L, rez);
    } else {
        find_right(ts, i + (mid - tl) * 2, mid, tr, L, rez);
    }
}

void find_left(TreeSegment *ts, int i, int tl, int tr, int R, int *rez) {
    push(ts, i, tl, tr);
    if (R < tl) {
        *rez = -1;
        return;
    }
    if (tl + 1 == tr) {
        if (ts->S[i] * 2 >= ts->S[0]) {
            *rez = tl;
        } else {
            *rez = -1;
        }
        return;
    }
    int mid = (tl + tr) / 2;
    if (tr <= R + 1) {
        find_left(ts, i + (mid - tl) * 2, mid, tr, R, rez);
    } else {
        find_left(ts, i + 1, tl, mid, R, rez);
    }
}

void solve(int n, int q, int *pos, int *w) {
    TreeSegment ts;
    ts.n = n;
    ts.S = (int *)malloc((2 * n + 1) * sizeof(Node));
    init(&ts, 0, 0, n, w);

    int *subw = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        subw[i] = (w[i] * (i - pos[i])) % MOD;
    }

    TreeSegment resp;
    resp.n = n;
    resp.S = (int *)malloc((2 * n + 1) * sizeof(Node));
    init(&resp, 0, 0, n, subw);

    for (int i = 0; i < q; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        if (x < 0) {
            int ind = -x;
            int _new = y;
            ind--;
            update(&ts, 0, 0, n, ind, ind + 1, _new);
            update(&resp, 0, 0, n, ind, ind + 1, (_new * (ind - pos[ind])) % MOD);
        } else {
            int l = x, r = y;
            l--;

            int sm = query(&ts, 0, 0, n, l, r);

            int bestL;
            find_right(&ts, 0, 0, n, l, &bestL);

            int x = pos[bestL] - bestL + l;

            int left = 0;
            if (l < bestL) {
                left = query(&resp, 0, 0, n, l, bestL) + query(&ts, 0, 0, n, l, bestL) * (x - l);
            }
            int right = 0;
            if (bestL < r) {
                right = query(&resp, 0, 0, n, bestL, r) + query(&ts, 0, 0, n, bestL, r) * (x - l);
            }
            printf("%lld\n", floor_mod(left - right, MOD));
        }
    }

    free(ts.S);
    free(subw);
    free(resp.S);
}

int main(int argc, char *argv[]) {
    int n, q;
    scanf("%d %d", &n, &q);
    int *pos = (int *)malloc(n * sizeof(int));
    int *w = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &pos[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
    }
    solve(n, q, pos, w);
    free(pos);
    free(w);
    return 0;
}
