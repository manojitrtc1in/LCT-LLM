#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define len(arr) (sizeof(arr) / sizeof(arr[0]))
#define scan(arr) for (int i = 0; i < len(arr); i++) scanf("%d", &arr[i])
#define print printf

typedef struct {
    bool have_mod;
    int l;
    int r;
    int value;
    int mod;
} Node;

typedef int (*Magic)(int, int);
typedef int (*ApplyMod)(int, int, int, int);
typedef int (*MergeMods)(int, int, int, int);

typedef struct {
    Magic magic;
    ApplyMod apply_mod;
    MergeMods merge_mods;
    Node* S;
    int n;
} TreeSegment;

int add_mod(TreeSegment* ts, int i, int tl, int tr, int sub) {
    if (ts->S[i].have_mod) {
        ts->S[i].mod = ts->merge_mods(ts->S[i].mod, sub, tl, tr);
    } else {
        ts->S[i].mod = sub;
        ts->S[i].have_mod = true;
    }
}

void push(TreeSegment* ts, int i, int tl, int tr) {
    if (ts->S[i].have_mod) {
        ts->S[i].value = ts->apply_mod(ts->S[i].value, ts->S[i].mod, tl, tr);
        if (tl + 1 != tr) {
            int mid = (tl + tr) / 2;
            add_mod(ts, ts->S[i].l, tl, mid, ts->S[i].mod);
            add_mod(ts, ts->S[i].r, mid, tr, ts->S[i].mod);
        }
        ts->S[i].have_mod = false;
    }
}

int query(TreeSegment* ts, int i, int tl, int tr, int ql, int qr) {
    push(ts, i, tl, tr);
    if (ql <= tl && tr <= qr) {
        return ts->S[i].value;
    } else {
        int mid = (tl + tr) / 2;
        if ((tl <= mid && mid <= tr) && (ql <= tl && tr <= qr)) {
            return ts->magic(
                query(ts, ts->S[i].l, tl, mid, ql, qr),
                query(ts, ts->S[i].r, mid, tr, ql, qr)
            );
        } else if (tl <= mid && mid <= tr && ql <= tl && tr <= qr) {
            return query(ts, ts->S[i].l, tl, mid, ql, qr);
        } else if (tl <= mid && mid <= tr && ql <= tl && tr <= qr) {
            return query(ts, ts->S[i].r, mid, tr, ql, qr);
        } else {
            exit(EXIT_FAILURE);
        }
    }
}

void update(TreeSegment* ts, int i, int tl, int tr, int ql, int qr, int mod) {
    push(ts, i, tl, tr);
    if (ql <= tl && tr <= qr) {
        add_mod(ts, i, tl, tr, mod);
    } else {
        int mid = (tl + tr) / 2;
        if (tl <= mid && mid <= tr && ql <= tl && tr <= qr) {
            update(ts, ts->S[i].l, tl, mid, ql, qr, mod);
        }
        if (tl <= mid && mid <= tr && ql <= tl && tr <= qr) {
            update(ts, ts->S[i].r, mid, tr, ql, qr, mod);
        }
        ts->S[i].value = ts->magic(
            query(ts, ts->S[i].l, tl, mid, tl, mid),
            query(ts, ts->S[i].r, mid, tr, mid, tr)
        );
    }
}

int find_right(TreeSegment* ts, int i, int tl, int tr, int L, int (*checker)(int)) {
    push(ts, i, tl, tr);
    if (tr <= L) return -1;
    if (tl + 1 == tr) {
        int _this = ts->magic(0, query(ts, i, tl, tr, tl, tr));
        if (checker(_this)) {
            return tl;
        } else {
            return -1;
        }
    } else {
        int mid = (tl + tr) / 2;
        if (L <= tl) {
            int _left = ts->magic(0, query(ts, i, tl, mid, tl, mid));
            if (checker(_left)) {
                return find_right(ts, ts->S[i].l, tl, mid, L, checker);
            } else {
                return find_right(ts, ts->S[i].r, mid, tr, L, checker);
            }
        } else {
            int* t = find_right(ts, ts->S[i].l, tl, mid, L, checker);
            if (t[0] != -1) return t;
            return find_right(ts, ts->S[i].r, mid, tr, L, checker);
        }
    }
}

int find_left(TreeSegment* ts, int i, int tl, int tr, int R, int (*checker)(int)) {
    push(ts, i, tl, tr);
    if (R < tl) return -1;
    if (tl + 1 == tr) {
        int _this = ts->magic(0, query(ts, i, tl, tr, tl, tr));
        if (checker(_this)) {
            return tl;
        } else {
            return -1;
        }
    } else {
        int mid = (tl + tr) / 2;
        if (tr <= R + 1) {
            int _right = ts->magic(0, query(ts, i, mid, tr, mid, tr));
            if (checker(_right)) {
                return find_left(ts, ts->S[i].r, mid, tr, R, checker);
            } else {
                return find_left(ts, ts->S[i].l, tl, mid, R, checker);
            }
        } else {
            int* t = find_left(ts, ts->S[i].r, mid, tr, R, checker);
            if (t[0] != -1) return t;
            return find_left(ts, ts->S[i].l, tl, mid, R, checker);
        }
    }
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

void init(TreeSegment* ts, int tl, int tr, int* src) {
    int i = len(ts->S);
    if (tl + 1 == tr) {
        ts->S[i].value = src[tl];
    } else {
        int mid = (tl + tr) / 2;
        ts->S[i].l = len(ts->S);
        init(ts, tl, mid, src);
        ts->S[i].r = len(ts->S);
        init(ts, mid, tr, src);
        ts->S[i].value = ts->magic(
            query(ts, ts->S[i].l, tl, mid, tl, mid),
            query(ts, ts->S[i].r, mid, tr, mid, tr)
        );
    }
}

void tree_segment_init(TreeSegment* ts, int n, int def[]) {
    ts->magic = magic;
    ts->apply_mod = apply_mod;
    ts->merge_mods = merge_mods;
    ts->S = (Node*)malloc(sizeof(Node) * 2 * n);
    ts->n = n;
    init(ts, 0, n, def);
}

int main(int argc, char *argv[]) {
    int n, q;
    scanf("%d %d", &n, &q);
    int* pos = (int*)malloc(sizeof(int) * n);
    int* w = (int*)malloc(sizeof(int) * n);
    scan(pos);
    scan(w);

    TreeSegment ts;
    tree_segment_init(&ts, n, w);

    int* subw = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        subw[i] = (w[i] * (i - pos[i])) % MOD;
    }

    TreeSegment resp;
    tree_segment_init(&resp, n, subw);

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

            int bestL = find_right(&ts, 0, 0, n, l, [](int x) {
                return x * 2 >= sm;
            });

            int x = pos[bestL] - bestL + l;

            int left = 0;
            if (l < bestL) {
                left = query(&resp, 0, 0, n, l, bestL) + query(&ts, 0, 0, n, l, bestL) * (x - l);
            }
            int right = 0;
            if (bestL < r) {
                right = query(&resp, 0, 0, n, bestL, r) + query(&ts, 0, 0, n, bestL, r) * (x - l);
            }
            print("%d\n", floor_mod(left - right, MOD));
        }
    }

    free(pos);
    free(w);
    free(subw);
    free(ts.S);
    free(resp.S);

    return 0;
}
