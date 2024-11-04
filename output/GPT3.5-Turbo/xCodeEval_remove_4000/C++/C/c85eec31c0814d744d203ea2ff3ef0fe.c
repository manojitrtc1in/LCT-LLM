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
    if (!S[i * 2].have_mod) return S[i * 2].value;
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
    if (S[i * 2].have_mod) {
        S[i * 2].mod = merge_mods(S[i * 2].mod, sub, tl, tr);
    } else {
        S[i * 2].mod = sub;
        S[i * 2].have_mod = true;
    }
}

void __push(int *S, int i, int tl, int tr) {
    if (S[i * 2].have_mod) {
        S[i * 2].value = apply_mod(S[i * 2].value, S[i * 2].mod, tl, tr);
        if (tl + 1 != tr) {
            int mid = (tl + tr) / 2;
            __add_mod(S, i + 1, tl, mid, S[i * 2].mod);
            __add_mod(S, i + (mid - tl) * 2, mid, tr, S[i * 2].mod);
        }
        S[i * 2].have_mod = false;
    }
}

void init(int *S, int i, int tl, int tr, int *src, int n) {
    if (tl + 1 == tr) {
        S[i * 2].value = src[tl];
    } else {
        int mid = (tl + tr) / 2;
        init(S, i + 1, tl, mid, src, n);
        init(S, i + (mid - tl) * 2, mid, tr, src, n);
        __recalc_value(S, i, tl, tr);
    }
}

void tree_segment_init(TreeSegment *ts, int *src, int n) {
    ts->n = n;
    ts->S = (int *)malloc(sizeof(int) * (2 * n + 1));
    init(ts->S, 0, 0, n, src, n);
}

int __query(int *S, int i, int tl, int tr, int ql, int qr) {
    __push(S, i, tl, tr);
    if (ql <= tl && tr <= qr) {
        return S[i * 2].value;
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

int tree_segment_query(TreeSegment *ts, int ql, int qr) {
    return __query(ts->S, 0, 0, ts->n, ql, qr);
}

void __change(int *S, int i, int tl, int tr, int j, int _new) {
    __push(S, i, tl, tr);
    if (tl + 1 == tr) {
        S[i * 2].value = _new;
    } else {
        int m = (tl + tr) / 2;
        if (j < m) {
            __change(S, S[i * 2].l, tl, m, j, _new);
        } else {
            __change(S, S[i * 2].r, m, tr, j, _new);
        }
        __recalc_value(S, i, tl, tr);
    }
}

void tree_segment_change(TreeSegment *ts, int i, int value) {
    __change(ts->S, 0, 0, ts->n, i, value);
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

void tree_segment_update(TreeSegment *ts, int ql, int qr, int mod) {
    __update(ts->S, 0, 0, ts->n, ql, qr, mod);
}

typedef struct {
    int *S;
    int n;
} TreeSegmentResp;

void init_resp(int *S, int i, int tl, int tr, int *src, int n) {
    if (tl + 1 == tr) {
        S[i * 2].value = src[tl];
    } else {
        int mid = (tl + tr) / 2;
        init_resp(S, i + 1, tl, mid, src, n);
        init_resp(S, i + (mid - tl) * 2, mid, tr, src, n);
        __recalc_value(S, i, tl, tr);
    }
}

void tree_segment_resp_init(TreeSegmentResp *ts, int *src, int n) {
    ts->n = n;
    ts->S = (int *)malloc(sizeof(int) * (2 * n + 1));
    init_resp(ts->S, 0, 0, n, src, n);
}

int __query_resp(int *S, int i, int tl, int tr, int ql, int qr) {
    __push(S, i, tl, tr);
    if (ql <= tl && tr <= qr) {
        return S[i * 2].value;
    } else {
        int mid = (tl + tr) / 2;
        if (__intersects(tl, mid, ql, qr) && __intersects(mid, tr, ql, qr)) {
            return magic(
                __query_resp(S, i + 1, tl, mid, ql, qr),
                __query_resp(S, i + (mid - tl) * 2, mid, tr, ql, qr)
            );
        } else if (__intersects(tl, mid, ql, qr)) {
            return __query_resp(S, i + 1, tl, mid, ql, qr);
        } else {
            return __query_resp(S, i + (mid - tl) * 2, mid, tr, ql, qr);
        }
    }
}

int tree_segment_resp_query(TreeSegmentResp *ts, int ql, int qr) {
    return __query_resp(ts->S, 0, 0, ts->n, ql, qr);
}

void __change_resp(int *S, int i, int tl, int tr, int j, int _new) {
    __push(S, i, tl, tr);
    if (tl + 1 == tr) {
        S[i * 2].value = _new;
    } else {
        int m = (tl + tr) / 2;
        if (j < m) {
            __change_resp(S, S[i * 2].l, tl, m, j, _new);
        } else {
            __change_resp(S, S[i * 2].r, m, tr, j, _new);
        }
        __recalc_value(S, i, tl, tr);
    }
}

void tree_segment_resp_change(TreeSegmentResp *ts, int i, int value) {
    __change_resp(ts->S, 0, 0, ts->n, i, value);
}

void __update_resp(int *S, int i, int tl, int tr, int ql, int qr, int mod) {
    __push(S, i, tl, tr);
    if (ql <= tl && tr <= qr) {
        __add_mod(S, i, tl, tr, mod);
    } else {
        int mid = (tl + tr) / 2;
        if (__intersects(tl, mid, ql, qr)) {
            __update_resp(S, i + 1, tl, mid, ql, qr, mod);
        }
        if (__intersects(mid, tr, ql, qr)) {
            __update_resp(S, i + (mid - tl) * 2, mid, tr, ql, qr, mod);
        }
        __recalc_value(S, i, tl, tr);
    }
}

void tree_segment_resp_update(TreeSegmentResp *ts, int ql, int qr, int mod) {
    __update_resp(ts->S, 0, 0, ts->n, ql, qr, mod);
}

int find_right(int *S, int i, int tl, int tr, int L, int sm) {
    __push(S, i, tl, tr);
    if (tr <= L) return -1;
    if (tl + 1 == tr) {
        int _this = magic(sm, __get_value(S, i, tl, tr));
        if (_this * 2 >= sm) {
            return tl;
        } else {
            return -1;
        }
    } else {
        int mid = (tl + tr) / 2;
        if (L <= tl) {
            int _left = magic(sm, __get_value(S, i + 1, tl, mid));
            if (_left * 2 >= sm) {
                return find_right(S, i + 1, tl, mid, L, sm);
            } else {
                return find_right(S, i + (mid - tl) * 2, mid, tr, L, _left);
            }
        } else {
            int t = find_right(S, i + 1, tl, mid, L, sm);
            if (t != -1) return t;
            return find_right(S, i + (mid - tl) * 2, mid, tr, L, t);
        }
    }
}

int tree_segment_find_right(int *S, int L, int sm) {
    return find_right(S, 0, 0, len(S) / 2, L, sm);
}

int find_left(int *S, int i, int tl, int tr, int R, int sm) {
    __push(S, i, tl, tr);
    if (R < tl) return -1;
    if (tl + 1 == tr) {
        int _this = magic(sm, __get_value(S, i, tl, tr));
        if (_this * 2 >= sm) {
            return tl;
        } else {
            return -1;
        }
    } else {
        int mid = (tl + tr) / 2;
        if (tr <= R + 1) {
            int _right = magic(sm, __get_value(S, S[i * 2].r, mid, tr));
            if (_right * 2 >= sm) {
                return find_left(S, S[i * 2].r, mid, tr, R, sm);
            } else {
                return find_left(S, S[i * 2].l, tl, mid, R, _right);
            }
        } else {
            int t = find_left(S, S[i * 2].r, mid, tr, R, sm);
            if (t != -1) return t;
            return find_left(S, S[i * 2].l, tl, mid, R, t);
        }
    }
}

int tree_segment_find_left(int *S, int R, int sm) {
    return find_left(S, 0, 0, len(S) / 2, R, sm);
}

int floor_mod(int a, int b) {
    if (a % b == 0) return 0;
    if (a >= 0 && b >= 0) return a % b;
    if (a <= 0 && b <= 0) return a % b;
    return abs(b) - (abs(a) % abs(b));
}

int main(int argc, char *argv[]) {
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
    tree_segment_init(&ts, w, n);

    int *subw = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        subw[i] = (w[i] * (i - pos[i])) % MOD;
    }

    TreeSegmentResp resp;
    tree_segment_resp_init(&resp, subw, n);

    for (int i = 0; i < q; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        if (x < 0) {
            int ind = -x;
            int _new = y;
            ind--;
            tree_segment_update(&ts, ind, ind + 1, _new);
            tree_segment_resp_update(&resp, ind, ind + 1, (_new * (ind - pos[ind])) % MOD);
        } else {
            int l = x, r = y;
            l--;

            int sm = tree_segment_query(&ts, l, r);

            int bestL = tree_segment_find_right(ts.S, l, sm);

            int x = pos[bestL] - bestL + l;

            int left = 0;
            if (l < bestL) {
                left = tree_segment_resp_query(&resp, l, bestL) + tree_segment_query(&ts, l, bestL) * (x - l);
            }
            int right = 0;
            if (bestL < r) {
                right = tree_segment_resp_query(&resp, bestL, r) + tree_segment_query(&ts, bestL, r) * (x - l);
            }
            printf("%d\n", floor_mod(left - right, MOD));
        }
    }

    free(pos);
    free(w);
    free(ts.S);
    free(subw);
    free(resp.S);

    return 0;
}
