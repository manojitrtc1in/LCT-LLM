#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define len(arr) (sizeof(arr) / sizeof(arr[0]))

typedef struct {
    bool have_mod;
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
    return value + mod;
}

int merge_mods(int old, int _new, int tl, int tr) {
    return _new;
}

bool __intersects(int tl, int tr, int ql, int qr) {
    return !(tr <= ql || qr <= tl);
}

int __get_value(int *S, int i, int tl, int tr) {
    if (!S[i * 2].have_mod) {
        return S[i * 2].value;
    }
    return apply_mod(S[i * 2].value, S[i * 2].mod, tl, tr);
}

void __recalc_value(int *S, int i, int tl, int tr) {
    if (tl + 1 != tr) {
        int mid = (tl + tr) / 2;
        S[i].value = magic(
            __get_value(S, i + 1, tl, mid),
            __get_value(S, i + (mid - tl) * 2, mid, tr)
        );
    }
}

void __add_mod(int *S, int i, int tl, int tr, int sub) {
    if (S[i].have_mod) {
        S[i].mod = merge_mods(S[i].mod, sub, tl, tr);
    } else {
        S[i].mod = sub;
        S[i].have_mod = true;
    }
}

void __push(int *S, int i, int tl, int tr) {
    if (S[i].have_mod) {
        S[i].value = apply_mod(S[i].value, S[i].mod, tl, tr);
        if (tl + 1 != tr) {
            int mid = (tl + tr) / 2;
            __add_mod(S, i + 1, tl, mid, S[i].mod);
            __add_mod(S, i + (mid - tl) * 2, mid, tr, S[i].mod);
        }
        S[i].have_mod = false;
    }
}

void init(int *S, int i, int tl, int tr, int *src, int n) {
    if (tl + 1 == tr) {
        S[i].value = src[tl];
    } else {
        int mid = (tl + tr) / 2;
        init(S, i + 1, tl, mid, src, n);
        init(S, i + (mid - tl) * 2, mid, tr, src, n);
        __recalc_value(S, i, tl, tr);
    }
}

void TreeSegment_init(TreeSegment *ts, int *src, int n, int def) {
    ts->n = n;
    ts->S = (int *)malloc(sizeof(Node) * (2 * n + 1));
    init(ts->S, 0, 0, n, src, n);
}

int __query(int *S, int i, int tl, int tr, int ql, int qr) {
    __push(S, i, tl, tr);
    if (ql <= tl && tr <= qr) {
        return S[i].value;
    } else {
        int mid = (tl + tr) / 2;
        if (__intersects(tl, mid, ql, qr) && __intersects(mid, tr, ql, qr)) {
            return magic(
                __query(S, i + 1, tl, mid, ql, qr),
                __query(S, i + (mid - tl) * 2, mid, tr, ql, qr)
            );
        } else if (__intersects(tl, mid, ql, qr)) {
            return __query(S, i + 1, tl, mid, ql, qr);
        } else {
            return __query(S, i + (mid - tl) * 2, mid, tr, ql, qr);
        }
    }
}

void __change(int *S, int i, int tl, int tr, int j, int _new) {
    __push(S, i, tl, tr);
    if (tl + 1 == tr) {
        S[i].value = _new;
    } else {
        int m = (tl + tr) / 2;
        if (j < m) {
            __change(S, S[i].l, tl, m, j, _new);
        } else {
            __change(S, S[i].r, m, tr, j, _new);
        }
        __recalc_value(S, i, tl, tr);
    }
}

void __update(int *S, int i, int tl, int tr, int ql, int qr, int mod) {
    __push(S, i, tl, tr);
    if (ql <= tl && tr <= qr) {
        __add_mod(S, i, tl, tr, mod);
    } else {
        int mid = (tl + tr) / 2;
        if (__intersects(tl, mid, ql, qr)) {
            __update(S, i + 1, tl, mid, ql, qr, mod);
        }
        if (__intersects(mid, tr, ql, qr)) {
            __update(S, i + (mid - tl) * 2, mid, tr, ql, qr, mod);
        }
        __recalc_value(S, i, tl, tr);
    }
}

int query(TreeSegment *ts, int ql, int qr) {
    return __query(ts->S, 0, 0, ts->n, ql, qr);
}

void change(TreeSegment *ts, int i, int value) {
    __change(ts->S, 0, 0, ts->n, i, value);
}

void update(TreeSegment *ts, int ql, int qr, int mod) {
    __update(ts->S, 0, 0, ts->n, ql, qr, mod);
}

int find_right(TreeSegment *ts, int L, int (*checker)(int), int start) {
    if (checker(start)) {
        return L - 1;
    }
    int rez = id0(ts->S, 0, ts->n, L, checker, start).first;
    return (rez == -1) ? ts->n : rez;
}

int find_left(TreeSegment *ts, int R, int (*checker)(int), int start) {
    if (checker(start)) {
        return R + 1;
    }
    int rez = id3(ts->S, 0, ts->n, R, checker, start).first;
    return (rez == -1) ? -1 : rez;
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    int *pos = (int *)malloc(sizeof(int) * n);
    int *w = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &pos[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
    }

    TreeSegment ts;
    TreeSegment_init(&ts, w, n, 0);

    int *subw = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        subw[i] = (w[i] * (i - pos[i])) % MOD;
    }

    TreeSegment resp;
    TreeSegment_init(&resp, subw, n, 0);

    for (int i = 0; i < q; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        if (x < 0) {
            int ind = -x;
            int _new = y;
            ind--;
            update(&ts, ind, ind + 1, _new);
            update(&resp, ind, ind + 1, (_new * (ind - pos[ind])) % MOD);
        } else {
            int l = x, r = y;
            l--;

            int sm = query(&ts, l, r);

            int bestL = find_right(&ts, l, [](int x) {
                return x * 2 >= sm;
            }, 0);

            int x = pos[bestL] - bestL + l;

            int left = 0;
            if (l < bestL) {
                left = query(&resp, l, bestL) + query(&ts, l, bestL) * (x - l);
            }
            int right = 0;
            if (bestL < r) {
                right = query(&resp, bestL, r) + query(&ts, bestL, r) * (x - l);
            }
            printf("%d\n", (left - right + MOD) % MOD);
        }
    }

    free(pos);
    free(w);
    free(subw);
    free(ts.S);
    free(resp.S);

    return 0;
}
