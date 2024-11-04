#include <stdio.h>
#include <stdlib.h>

#define len(v) ((int)v.size())

typedef struct {
    int have_mod;
    int value;
    int mod;
} Node;

typedef struct {
    int n;
    Node* S;
    int (*magic)(int, int);
    int (*apply_mod)(int, int, int, int);
    int (*merge_mods)(int, int, int, int);
} TreeSegment;

int floor_mod(int a, int b) {
    if (a % b == 0) return 0;
    if (a >= 0 && b >= 0) return a % b;
    if (a <= 0 && b <= 0) return a % b;
    return abs(b) - (abs(a) % abs(b));
}

int magic(int a, int b) {
    return a + b;
}

int apply_mod(int value, int mod, int tl, int tr) {
    return mod;
}

int merge_mods(int old, int _new, int tl, int tr) {
    return _new;
}

void init(TreeSegment* ts, int i, int tl, int tr, int* src) {
    if (tl + 1 == tr) {
        ts->S[i].value = src[tl];
    } else {
        int mid = (tl + tr) / 2;
        init(ts, i + 1, tl, mid, src);
        init(ts, i + (mid - tl) * 2, mid, tr, src);
        ts->S[i].value = ts->magic(
            ts->__get_value(ts, i + 1, tl, mid),
            ts->__get_value(ts, i + (mid - tl) * 2, mid, tr)
        );
    }
}

int __get_value(TreeSegment* ts, int i, int tl, int tr) {
    if (!ts->S[i].have_mod) return ts->S[i].value;
    return ts->apply_mod(ts->S[i].value, ts->S[i].mod, tl, tr);
}

void __recalc_value(TreeSegment* ts, int i, int tl, int tr) {
    if (tl + 1 != tr) {
        int mid = (tl + tr) / 2;
        ts->S[i].value = ts->magic(
            ts->__get_value(ts, i + 1, tl, mid),
            ts->__get_value(ts, i + (mid - tl) * 2, mid, tr)
        );
    }
}

void __add_mod(TreeSegment* ts, int i, int tl, int tr, int sub) {
    if (ts->S[i].have_mod) {
        ts->S[i].mod = ts->merge_mods(ts->S[i].mod, sub, tl, tr);
    } else {
        ts->S[i].mod = sub;
        ts->S[i].have_mod = 1;
    }
}

void __push(TreeSegment* ts, int i, int tl, int tr) {
    if (ts->S[i].have_mod) {
        ts->S[i].value = ts->apply_mod(ts->S[i].value, ts->S[i].mod, tl, tr);
        if (tl + 1 != tr) {
            int mid = (tl + tr) / 2;
            __add_mod(ts, i + 1, tl, mid, ts->S[i].mod);
            __add_mod(ts, i + (mid - tl) * 2, mid, tr, ts->S[i].mod);
        }
        ts->S[i].have_mod = 0;
    }
}

int __query(TreeSegment* ts, int i, int tl, int tr, int ql, int qr) {
    __push(ts, i, tl, tr);
    if (ql <= tl && tr <= qr) {
        return ts->S[i].value;
    } else {
        int mid = (tl + tr) / 2;
        if (ql <= tl && tr <= qr) {
            return ts->magic(
                __query(ts, i + 1, tl, mid, ql, qr),
                __query(ts, i + (mid - tl) * 2, mid, tr, ql, qr)
            );
        } else if (ql <= tl && tr <= qr) {
            return __query(ts, i + 1, tl, mid, ql, qr);
        } else {
            return __query(ts, i + (mid - tl) * 2, mid, tr, ql, qr);
        }
    }
}

void __change(TreeSegment* ts, int i, int tl, int tr, int j, int _new) {
    __push(ts, i, tl, tr);
    if (tl + 1 == tr) {
        ts->S[i].value = _new;
    } else {
        int m = (tl + tr) / 2;
        if (j < m) {
            __change(ts, ts->S[i].l, tl, m, j, _new);
        } else {
            __change(ts, ts->S[i].r, m, tr, j, _new);
        }
        __recalc_value(ts, i, tl, tr);
    }
}

void __update(TreeSegment* ts, int i, int tl, int tr, int ql, int qr, int mod) {
    __push(ts, i, tl, tr);
    if (ql <= tl && tr <= qr) {
        __add_mod(ts, i, tl, tr, mod);
    } else {
        int mid = (tl + tr) / 2;
        if (ql <= tl && tr <= qr) {
            __update(ts, i + 1, tl, mid, ql, qr, mod);
        }
        if (ql <= tl && tr <= qr) {
            __update(ts, i + (mid - tl) * 2, mid, tr, ql, qr, mod);
        }
        __recalc_value(ts, i, tl, tr);
    }
}

void ts_init(TreeSegment* ts, int n, int def[], int def_len) {
    ts->n = n;
    ts->S = (Node*)malloc((2 * n + 1) * sizeof(Node));
    ts->magic = magic;
    ts->apply_mod = apply_mod;
    ts->merge_mods = merge_mods;
    init(ts, 0, 0, def_len, def);
}

int ts_query(TreeSegment* ts, int ql, int qr) {
    return __query(ts, 0, 0, ts->n, ql, qr);
}

void ts_change(TreeSegment* ts, int i, int value) {
    __change(ts, 0, 0, ts->n, i, value);
}

void ts_update(TreeSegment* ts, int ql, int qr, int mod) {
    __update(ts, 0, 0, ts->n, ql, qr, mod);
}

typedef struct {
    int first;
    int second;
} Pair;

Pair mp(int first, int second) {
    Pair p;
    p.first = first;
    p.second = second;
    return p;
}

Pair id0(TreeSegment* ts, int i, int tl, int tr, int L, int (*checker)(int), int pref) {
    __push(ts, i, tl, tr);
    if (tr <= L) return mp(-1, pref);
    if (tl + 1 == tr) {
        int _this = ts->magic(pref, __get_value(ts, i, tl, tr));
        if (checker(_this)) {
            return mp(tl, _this);
        } else {
            return mp(-1, _this);
        }
    } else {
        int mid = (tl + tr) / 2;
        if (L <= tl) {
            int _left = ts->magic(pref, __get_value(ts, i + 1, tl, mid));
            if (checker(_left)) {
                return id0(ts, i + 1, tl, mid, L, checker, pref);
            } else {
                return id0(ts, i + (mid - tl) * 2, mid, tr, L, checker, _left);
            }
        } else {
            Pair t = id0(ts, i + 1, tl, mid, L, checker, pref);
            if (t.first != -1) return t;
            return id0(ts, i + (mid - tl) * 2, mid, tr, L, checker, t.second);
        }
    }
}

Pair id3(TreeSegment* ts, int i, int tl, int tr, int R, int (*checker)(int), int pref) {
    __push(ts, i, tl, tr);
    if (R < tl) return mp(-1, pref);
    if (tl + 1 == tr) {
        int _this = ts->magic(pref, __get_value(ts, i, tl, tr));
        if (checker(_this)) {
            return mp(tl, _this);
        } else {
            return mp(-1, _this);
        }
    } else {
        int mid = (tl + tr) / 2;
        if (tr <= R + 1) {
            int _right = ts->magic(pref, __get_value(ts, S[i].r, mid, tr));
            if (checker(_right)) {
                return id3(ts, S[i].r, mid, tr, R, checker, pref);
            } else {
                return id3(ts, S[i].l, tl, mid, R, checker, _right);
            }
        } else {
            Pair t = id3(ts, S[i].r, mid, tr, R, checker, pref);
            if (t.first != -1) return t;
            return id3(ts, S[i].l, tl, mid, R, checker, t.second);
        }
    }
}

int find_right(TreeSegment* ts, int L, int (*checker)(int), int start) {
    if (checker(start)) return L - 1;
    int rez = id0(ts, 0, 0, ts->n, L, checker, start).first;
    return (rez == -1) ? ts->n : rez;
}

int find_left(TreeSegment* ts, int R, int (*checker)(int), int start) {
    if (checker(start)) return R + 1;
    int rez = id3(ts, 0, 0, ts->n, R, checker, start).first;
    return (rez == -1) ? -1 : rez;
}

int main(int argc, char *argv[]) {
    int n, q;
    scanf("%d %d", &n, &q);
    int* pos = (int*)malloc(n * sizeof(int));
    int* w = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &pos[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
    }

    TreeSegment ts;
    ts_init(&ts, n, w, n);

    int* subw = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        subw[i] = (w[i] * (i - pos[i])) % MOD;
    }

    TreeSegment resp;
    ts_init(&resp, n, subw, n);

    for (int i = 0; i < q; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        if (x < 0) {
            int ind = -x;
            int _new = y;
            ind--;
            ts_update(&ts, ind, ind + 1, _new);
            resp_update(&resp, ind, ind + 1, (_new * (ind - pos[ind])) % MOD);
        } else {
            int l = x, r = y;
            l--;

            int sm = ts_query(&ts, l, r);

            int bestL = find_right(&ts, l, [sm](int x) {
                return x * 2 >= sm;
            }, 0);

            int x = pos[bestL] - bestL + l;

            int left = 0;
            if (l < bestL) {
                left = resp_query(&resp, l, bestL) + ts_query(&ts, l, bestL) * (x - l);
            }
            int right = 0;
            if (bestL < r) {
                right = resp_query(&resp, bestL, r) + ts_query(&ts, bestL, r) * (x - l);
            }
            printf("%d\n", floor_mod(left - right, MOD));
        }
    }

    free(pos);
    free(w);
    free(subw);
    free(ts.S);
    free(resp.S);

    return 0;
}
