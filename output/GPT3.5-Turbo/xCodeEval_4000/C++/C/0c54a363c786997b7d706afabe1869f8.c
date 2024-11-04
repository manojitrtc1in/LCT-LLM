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
    int tl;
    int tr;
    int ql;
    int qr;
} Args;

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

int __get_value(Node *S, int i, int tl, int tr) {
    if (!S[i].have_mod) return S[i].value;
    return apply_mod(S[i].value, S[i].mod, tl, tr);
}

void __recalc_value(Node *S, int i, int tl, int tr) {
    if (tl + 1 != tr) {
        int mid = (tl + tr) / 2;
        S[i].value = magic(
            __get_value(S, i + 1, tl, mid),
            __get_value(S, i + (mid - tl) * 2, mid, tr)
        );
    }
}

void __add_mod(Node *S, int i, int tl, int tr, int sub) {
    if (S[i].have_mod) {
        S[i].mod = merge_mods(S[i].mod, sub, tl, tr);
    } else {
        S[i].mod = sub;
        S[i].have_mod = 1;
    }
}

void __push(Node *S, int i, int tl, int tr) {
    if (S[i].have_mod) {
        S[i].value = apply_mod(S[i].value, S[i].mod, tl, tr);
        if (tl + 1 != tr) {
            int mid = (tl + tr) / 2;
            __add_mod(S, i + 1, tl, mid, S[i].mod);
            __add_mod(S, i + (mid - tl) * 2, mid, tr, S[i].mod);
        }
        S[i].have_mod = 0;
    }
}

void init(Node *S, int i, int tl, int tr, int *src, int n) {
    if (tl + 1 == tr) {
        S[i].value = src[tl];
    } else {
        int mid = (tl + tr) / 2;
        init(S, i + 1, tl, mid, src, n);
        init(S, i + (mid - tl) * 2, mid, tr, src, n);
        __recalc_value(S, i, tl, tr);
    }
}

int __query(Node *S, int i, int tl, int tr, int ql, int qr) {
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

void __change(Node *S, int i, int tl, int tr, int j, int _new) {
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

void __update(Node *S, int i, int tl, int tr, int ql, int qr, int mod) {
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

void init_tree_segment(Node *S, int *src, int n) {
    init(S, 0, 0, n, src, n);
}

int query_tree_segment(Node *S, int ql, int qr) {
    return __query(S, 0, 0, n, ql, qr);
}

void change_tree_segment(Node *S, int i, int value) {
    __change(S, 0, 0, n, i, value);
}

void update_tree_segment(Node *S, int ql, int qr, int mod) {
    __update(S, 0, 0, n, ql, qr, mod);
}

int find_right_tree_segment(Node *S, int L, int sm) {
    if (sm >= 2) return L - 1;
    int rez = __find_right(S, 0, 0, n, L, sm, 0).first;
    return (rez == -1) ? n : rez;
}

int find_left_tree_segment(Node *S, int R, int sm) {
    if (sm >= 2) return R + 1;
    int rez = __find_left(S, 0, 0, n, R, sm, 0).first;
    return (rez == -1) ? -1 : rez;
}

int __find_right(Node *S, int i, int tl, int tr, int L, int sm, int pref) {
    __push(S, i, tl, tr);
    if (tr <= L) return mp(-1, pref);
    if (tl + 1 == tr) {
        int _this = magic(pref, __get_value(S, i, tl, tr));
        if (_this >= sm) {
            return mp(tl, _this);
        } else {
            return mp(-1, _this);
        }
    } else {
        int mid = (tl + tr) / 2;
        if (L <= tl) {
            int _left = magic(pref, __get_value(S, i + 1, tl, mid));
            if (_left >= sm) {
                return __find_right(S, i + 1, tl, mid, L, sm, pref);
            } else {
                return __find_right(S, i + (mid - tl) * 2, mid, tr, L, sm, _left);
            }
        } else {
            Args t = __find_right(S, i + 1, tl, mid, L, sm, pref);
            if (t.first != -1) return t;
            return __find_right(S, i + (mid - tl) * 2, mid, tr, L, sm, t.second);
        }    
    }
}

int __find_left(Node *S, int i, int tl, int tr, int R, int sm, int pref) {
    __push(S, i, tl, tr);
    if (R < tl) return mp(-1, pref);
    if (tl + 1 == tr) {
        int _this = magic(pref, __get_value(S, i, tl, tr));
        if (_this >= sm) {
            return mp(tl, _this);
        } else {
            return mp(-1, _this);
        }
    } else {
        int mid = (tl + tr) / 2;
        if (tr <= R + 1) {
            int _right = magic(pref, __get_value(S, S[i].r, mid, tr));
            if (_right >= sm) {
                return __find_left(S, S[i].r, mid, tr, R, sm, pref);
            } else {
                return __find_left(S, S[i].l, tl, mid, R, sm, _right);
            }
        } else {
            Args t = __find_left(S, S[i].r, mid, tr, R, sm, pref);
            if (t.first != -1) return t;
            return __find_left(S, S[i].l, tl, mid, R, sm, t.second);
        }    
    }
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

    Node *ts = (Node *)malloc((2 * n + 1) * sizeof(Node));
    Node *resp = (Node *)malloc((2 * n + 1) * sizeof(Node));

    init_tree_segment(ts, w, n);

    int *subw = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        subw[i] = (w[i] * (i - pos[i])) % MOD;
    }

    init_tree_segment(resp, subw, n);

    for (int i = 0; i < q; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        if (x < 0) {
            int ind = -x;
            int _new = y;
            ind--;
            update_tree_segment(ts, ind, ind + 1, _new);
            update_tree_segment(resp, ind, ind + 1, (_new * (ind - pos[ind])) % MOD);
        } else {
            int l = x, r = y;
            l--;

            int sm = query_tree_segment(ts, l, r);

            int bestL = find_right_tree_segment(ts, l, sm);

            int x = pos[bestL] - bestL + l;

            int left = 0;
            if (l < bestL) {
                left = query_tree_segment(resp, l, bestL) + query_tree_segment(ts, l, bestL) * (x - l);
            }
            int right = 0;
            if (bestL < r) {
                right = query_tree_segment(resp, bestL, r) + query_tree_segment(ts, bestL, r) * (x - l);
            }
            printf("%d\n", (left - right + MOD) % MOD);
        }
    }

    free(pos);
    free(w);
    free(ts);
    free(resp);
    free(subw);

    return 0;
}
