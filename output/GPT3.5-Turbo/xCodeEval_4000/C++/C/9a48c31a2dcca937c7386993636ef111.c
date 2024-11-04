#include <stdio.h>
#include <stdlib.h>

#define int long long

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
        ts->S[i].value = src[tl];
    } else {
        int mid = (tl + tr) / 2;
        init(ts, i + 1, tl, mid, src);
        init(ts, i + (mid - tl) * 2, mid, tr, src);
        ts->S[i].value = magic(
            ts->S[i + 1].value,
            ts->S[i + (mid - tl) * 2].value
        );
    }
}

int get_value(TreeSegment *ts, int i, int tl, int tr) {
    if (!ts->S[i].have_mod) return ts->S[i].value;
    return apply_mod(ts->S[i].value, ts->S[i].mod, tl, tr);
}

void recalc_value(TreeSegment *ts, int i, int tl, int tr) {
    if (tl + 1 != tr) {
        int mid = (tl + tr) / 2;
        ts->S[i].value = magic(
            get_value(ts, i + 1, tl, mid),
            get_value(ts, i + (mid - tl) * 2, mid, tr)
        );
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
        if (ql <= mid && mid < qr) {
            return magic(
                query(ts, i + 1, tl, mid, ql, qr),
                query(ts, i + (mid - tl) * 2, mid, tr, ql, qr)
            );
        } else if (ql <= mid) {
            return query(ts, i + 1, tl, mid, ql, qr);
        } else {
            return query(ts, i + (mid - tl) * 2, mid, tr, ql, qr);
        }
    }
}

void find_right(TreeSegment *ts, int i, int tl, int tr, int L, int *result) {
    push(ts, i, tl, tr);
    if (tr <= L) {
        *result = -1;
        return;
    }
    if (tl + 1 == tr) {
        if (ts->S[i].value * 2 >= ts->S[i].value) {
            *result = tl;
        } else {
            *result = -1;
        }
        return;
    }
    int mid = (tl + tr) / 2;
    if (L <= tl) {
        int left = magic(ts->S[i + 1].value, ts->S[i + 1].value);
        if (left * 2 >= ts->S[i].value) {
            find_right(ts, i + 1, tl, mid, L, result);
        } else {
            find_right(ts, i + (mid - tl) * 2, mid, tr, L, result);
        }
    } else {
        int t;
        find_right(ts, i + 1, tl, mid, L, &t);
        if (t != -1) {
            *result = t;
            return;
        }
        find_right(ts, i + (mid - tl) * 2, mid, tr, L, result);
    }
}

void find_left(TreeSegment *ts, int i, int tl, int tr, int R, int *result) {
    push(ts, i, tl, tr);
    if (R < tl) {
        *result = -1;
        return;
    }
    if (tl + 1 == tr) {
        if (ts->S[i].value * 2 >= ts->S[i].value) {
            *result = tl;
        } else {
            *result = -1;
        }
        return;
    }
    int mid = (tl + tr) / 2;
    if (tr <= R + 1) {
        int right = magic(ts->S[i].value, ts->S[i].value);
        if (right * 2 >= ts->S[i].value) {
            find_left(ts, i + (mid - tl) * 2, mid, tr, R, result);
        } else {
            find_left(ts, i + 1, tl, mid, R, result);
        }
    } else {
        int t;
        find_left(ts, i + (mid - tl) * 2, mid, tr, R, &t);
        if (t != -1) {
            *result = t;
            return;
        }
        find_left(ts, i + 1, tl, mid, R, result);
    }
}

int floor_mod(int a, int b) {
    if (a % b == 0) return 0;
    if (a >= 0 && b >= 0) return a % b;
    if (a <= 0 && b <= 0) return a % b;
    return abs(b) - (abs(a) % abs(b));
}

int main() {
    int n, q;
    scanf("%lld %lld", &n, &q);
    int *pos = (int *)malloc(n * sizeof(int));
    int *w = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%lld", &pos[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%lld", &w[i]);
    }

    TreeSegment ts;
    ts.n = n;
    ts.S = (Node *)malloc((2 * n + 1) * sizeof(Node));
    init(&ts, 0, 0, n, w);

    int *subw = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        subw[i] = (w[i] * (i - pos[i])) % MOD;
    }

    TreeSegment resp;
    resp.n = n;
    resp.S = (Node *)malloc((2 * n + 1) * sizeof(Node));
    init(&resp, 0, 0, n, subw);

    for (int i = 0; i < q; i++) {
        int x, y;
        scanf("%lld %lld", &x, &y);
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

    free(pos);
    free(w);
    free(ts.S);
    free(subw);
    free(resp.S);

    return 0;
}
