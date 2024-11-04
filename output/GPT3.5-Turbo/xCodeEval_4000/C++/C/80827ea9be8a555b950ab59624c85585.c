#include <stdio.h>
#include <stdlib.h>

#define MAXMEM 200 * 1000 * 1024

char _memory[MAXMEM];
size_t _ptr = 0;

void* operator new(size_t _x) {
    _ptr += _x;
    if (_ptr >= MAXMEM) {
        exit(1);
    }
    return _memory + _ptr - _x;
}

void operator delete(void*) noexcept {}

typedef long long ll;
typedef unsigned long long ull;
typedef struct {
    int x;
    int y;
} pii;
typedef long double ld;

ll floor_mod(ll a, ll b) {
    if (a % b == 0) {
        return 0;
    }
    if (a >= 0 && b >= 0) {
        return a % b;
    }
    if (a <= 0 && b <= 0) {
        return a % b;
    }
    return abs(b) - (abs(a) % abs(b));
}

typedef struct {
    int have_mod;
    int value;
    int mod;
} Node;

typedef struct {
    int* S;
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

int __intersects(int tl, int tr, int ql, int qr) {
    return !(tr <= ql || qr <= tl);
}

int __create_node(int* S, int* len) {
    S[*len] = 0;
    (*len)++;
    return *len - 1;
}

int __get_value(int* S, int i, int tl, int tr) {
    if (!S[i]) {
        return S[i + 1];
    }
    return apply_mod(S[i + 1], S[i], tl, tr);
}

void __recalc_value(int* S, int i, int tl, int tr) {
    if (tl + 1 != tr) {
        int mid = (tl + tr) / 2;
        S[i + 1] = magic(
            __get_value(S, i + 2, tl, mid),
            __get_value(S, i + (mid - tl) * 2 + 2, mid, tr)
        );
    }
}

void __add_mod(int* S, int i, int tl, int tr, int sub) {
    if (S[i]) {
        S[i + 1] = merge_mods(S[i + 1], sub, tl, tr);
    } else {
        S[i] = 1;
        S[i + 1] = sub;
    }
}

void __push(int* S, int i, int tl, int tr) {
    if (S[i]) {
        S[i + 1] = apply_mod(S[i + 1], S[i], tl, tr);
        if (tl + 1 != tr) {
            int mid = (tl + tr) / 2;
            __add_mod(S, i + 2, tl, mid, S[i]);
            __add_mod(S, i + (mid - tl) * 2 + 2, mid, tr, S[i]);
        }
        S[i] = 0;
    }
}

void init(int* S, int* len, int i, int tl, int tr, int* src) {
    if (tl + 1 == tr) {
        S[i + 1] = src[tl];
    } else {
        int mid = (tl + tr) / 2;
        init(S, len, i + 2, tl, mid, src);
        init(S, len, i + (mid - tl) * 2 + 2, mid, tr, src);
        __recalc_value(S, i, tl, tr);
    }
}

void init_tree_segment(TreeSegment* ts, int* S, int n, int* src) {
    ts->S = S;
    ts->n = n;
    int len = 0;
    init(S, &len, 0, 0, n, src);
}

int query(int* S, int i, int tl, int tr, int ql, int qr) {
    __push(S, i, tl, tr);
    if (ql <= tl && tr <= qr) {
        return S[i + 1];
    } else {
        int mid = (tl + tr) / 2;
        if (__intersects(tl, mid, ql, qr) && __intersects(mid, tr, ql, qr)) {
            return magic(
                query(S, i + 2, tl, mid, ql, qr),
                query(S, i + (mid - tl) * 2 + 2, mid, tr, ql, qr)
            );
        } else if (__intersects(tl, mid, ql, qr)) {
            return query(S, i + 2, tl, mid, ql, qr);
        } else {
            return query(S, i + (mid - tl) * 2 + 2, mid, tr, ql, qr);
        }
    }
}

void change(int* S, int i, int tl, int tr, int j, int _new) {
    __push(S, i, tl, tr);
    if (tl + 1 == tr) {
        S[i + 1] = _new;
    } else {
        int m = (tl + tr) / 2;
        if (j < m) {
            change(S, i + 2, tl, m, j, _new);
        } else {
            change(S, i + (m - tl) * 2 + 2, m, tr, j, _new);
        }
        __recalc_value(S, i, tl, tr);
    }
}

void update(int* S, int i, int tl, int tr, int ql, int qr, int mod) {
    __push(S, i, tl, tr);
    if (ql <= tl && tr <= qr) {
        __add_mod(S, i, tl, tr, mod);
    } else {
        int mid = (tl + tr) / 2;
        if (__intersects(tl, mid, ql, qr)) {
            update(S, i + 2, tl, mid, ql, qr, mod);
        }
        if (__intersects(mid, tr, ql, qr)) {
            update(S, i + (mid - tl) * 2 + 2, mid, tr, ql, qr, mod);
        }
        __recalc_value(S, i, tl, tr);
    }
}

int find_right(int* S, int i, int tl, int tr, int L, int sm) {
    __push(S, i, tl, tr);
    if (tr <= L) {
        return -1;
    }
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
            int _left = magic(sm, __get_value(S, i + 2, tl, mid));
            if (_left * 2 >= sm) {
                return find_right(S, i + 2, tl, mid, L, sm);
            } else {
                return find_right(S, i + (mid - tl) * 2 + 2, mid, tr, L, _left);
            }
        } else {
            int* t = find_right(S, i + 2, tl, mid, L, sm);
            if (t[0] != -1) {
                return t;
            }
            return find_right(S, i + (mid - tl) * 2 + 2, mid, tr, L, t[1]);
        }
    }
}

int find_left(int* S, int i, int tl, int tr, int R, int sm) {
    __push(S, i, tl, tr);
    if (R < tl) {
        return -1;
    }
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
            int _right = magic(sm, __get_value(S, i + (mid - tl) * 2 + 2, mid, tr));
            if (_right * 2 >= sm) {
                return find_left(S, i + (mid - tl) * 2 + 2, mid, tr, R, sm);
            } else {
                return find_left(S, i + 2, tl, mid, R, _right);
            }
        } else {
            int* t = find_left(S, i + (mid - tl) * 2 + 2, mid, tr, R, sm);
            if (t[0] != -1) {
                return t;
            }
            return find_left(S, i + 2, tl, mid, R, t[1]);
        }
    }
}

int main(int argc, char *argv[]) {
    int n, q;
    scanf("%d%d", &n, &q);
    int* pos = (int*)malloc(n * sizeof(int));
    int* w = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &pos[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
    }

    int* ts_S = (int*)malloc((2 * n + 1) * sizeof(int));
    TreeSegment ts;
    init_tree_segment(&ts, ts_S, n, w);

    int* subw = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        subw[i] = (w[i] * (i - pos[i])) % MOD;
    }

    int* resp_S = (int*)malloc((2 * n + 1) * sizeof(int));
    TreeSegment resp;
    init_tree_segment(&resp, resp_S, n, subw);

    for (int i = 0; i < q; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        if (x < 0) {
            int ind = -x;
            int _new = y;
            ind--;
            update(ts.S, 0, 0, n, ind, ind + 1, _new);
            update(resp.S, 0, 0, n, ind, ind + 1, (_new * (ind - pos[ind])) % MOD);
        } else {
            int l = x, r = y;
            l--;

            int sm = query(ts.S, 0, 0, n, l, r);

            int bestL = find_right(ts.S, 0, 0, n, l, sm);

            int x = pos[bestL] - bestL + l;

            int left = 0;
            if (l < bestL) {
                left = query(resp.S, 0, 0, n, l, bestL) + query(ts.S, 0, 0, n, l, bestL) * (x - l);
            }
            int right = 0;
            if (bestL < r) {
                right = query(resp.S, 0, 0, n, bestL, r) + query(ts.S, 0, 0, n, bestL, r) * (x - l);
            }
            printf("%lld\n", floor_mod(left - right, MOD));
        }
    }

    free(pos);
    free(w);
    free(ts_S);
    free(subw);
    free(resp_S);

    return 0;
}
