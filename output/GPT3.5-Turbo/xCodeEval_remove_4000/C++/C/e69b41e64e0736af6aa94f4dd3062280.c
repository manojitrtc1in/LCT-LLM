#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define len(arr) (sizeof(arr) / sizeof(arr[0]))
#define scan(arr) for (int i = 0; i < len(arr); i++) scanf("%d", &arr[i])
#define print(x) printf("%d\n", x)

typedef struct {
    bool have_mod;
    int l;
    int r;
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

int create_node(TreeSegment* ts) {
    int index = ts->n;
    ts->S[index].have_mod = false;
    ts->S[index].l = -1;
    ts->S[index].r = -1;
    ts->n++;
    return index;
}

int get_value(TreeSegment* ts, int i, int tl, int tr) {
    if (!ts->S[i].have_mod) return ts->S[i].value;
    return apply_mod(ts->S[i].value, ts->S[i].mod, tl, tr);
}

void recalc_value(TreeSegment* ts, int i, int tl, int tr) {
    if (tl + 1 != tr) {
        int mid = (tl + tr) / 2;
        ts->S[i].value = magic(
            get_value(ts, ts->S[i].l, tl, mid),
            get_value(ts, ts->S[i].r, mid, tr)
        );
    }
}

void add_mod(TreeSegment* ts, int i, int tl, int tr, int sub) {
    if (ts->S[i].have_mod) {
        ts->S[i].mod = merge_mods(ts->S[i].mod, sub, tl, tr);
    } else {
        ts->S[i].mod = sub;
        ts->S[i].have_mod = true;
    }
}

void push(TreeSegment* ts, int i, int tl, int tr) {
    if (ts->S[i].have_mod) {
        ts->S[i].value = apply_mod(ts->S[i].value, ts->S[i].mod, tl, tr);
        if (tl + 1 != tr) {
            int mid = (tl + tr) / 2;
            add_mod(ts, ts->S[i].l, tl, mid, ts->S[i].mod);
            add_mod(ts, ts->S[i].r, mid, tr, ts->S[i].mod);
        }
        ts->S[i].have_mod = false;
    }
}

int init(TreeSegment* ts, int tl, int tr, int* src) {
    int i = create_node(ts);
    if (tl + 1 == tr) {
        ts->S[i].value = src[tl];
    } else {
        int mid = (tl + tr) / 2;
        ts->S[i].l = init(ts, tl, mid, src);
        ts->S[i].r = init(ts, mid, tr, src);
        recalc_value(ts, i, tl, tr);
    }
    return i;
}

void tree_segment_init(TreeSegment* ts, int* src, int size) {
    ts->n = 0;
    ts->S = (Node*)malloc(size * sizeof(Node));
    init(ts, 0, size, src);
}

int query(TreeSegment* ts, int i, int tl, int tr, int ql, int qr) {
    push(ts, i, tl, tr);
    if (ql <= tl && tr <= qr) {
        return ts->S[i].value;
    } else {
        int mid = (tl + tr) / 2;
        if (intersects(tl, mid, ql, qr) && intersects(mid, tr, ql, qr)) {
            return magic(
                query(ts, ts->S[i].l, tl, mid, ql, qr),
                query(ts, ts->S[i].r, mid, tr, ql, qr)
            );
        } else if (intersects(tl, mid, ql, qr)) {
            return query(ts, ts->S[i].l, tl, mid, ql, qr);
        } else if (intersects(mid, tr, ql, qr)) {
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
        if (intersects(tl, mid, ql, qr)) {
            update(ts, ts->S[i].l, tl, mid, ql, qr, mod);
        }
        if (intersects(mid, tr, ql, qr)) {
            update(ts, ts->S[i].r, mid, tr, ql, qr, mod);
        }
        recalc_value(ts, i, tl, tr);
    }
}

int find_right(TreeSegment* ts, int i, int tl, int tr, int L, int (*checker)(int)) {
    push(ts, i, tl, tr);
    if (tr <= L) return -1;
    if (tl + 1 == tr) {
        int _this = magic(pref, get_value(ts, i, tl, tr));
        if (checker(_this)) {
            return tl;
        } else {
            return -1;
        }
    } else {
        int mid = (tl + tr) / 2;
        if (L <= tl) {
            int _left = magic(pref, get_value(ts, ts->S[i].l, tl, mid));
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
        int _this = magic(pref, get_value(ts, i, tl, tr));
        if (checker(_this)) {
            return tl;
        } else {
            return -1;
        }
    } else {
        int mid = (tl + tr) / 2;
        if (tr <= R + 1) {
            int _right = magic(pref, get_value(ts, ts->S[i].r, mid, tr));
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

int floor_mod(int a, int b) {
    if (a % b == 0) return 0;
    if (a >= 0 && b >= 0) return a % b;
    if (a <= 0 && b <= 0) return a % b;
    return abs(b) - (abs(a) % abs(b));
}

bool intersects(int tl, int tr, int ql, int qr) {
    return !(tr <= ql || qr <= tl);
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    int* pos = (int*)malloc(n * sizeof(int));
    int* w = (int*)malloc(n * sizeof(int));
    scan(pos);
    scan(w);

    TreeSegment ts;
    tree_segment_init(&ts, w, n);

    int* subw = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        subw[i] = (w[i] * (i - pos[i])) % MOD;
    }

    TreeSegment resp;
    tree_segment_init(&resp, subw, n);

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

            int bestL = find_right(&ts, 0, 0, n, l, [sm](int x) {
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
            print(floor_mod(left - right, MOD));
        }
    }

    free(pos);
    free(w);
    free(subw);
    free(ts.S);
    free(resp.S);

    return 0;
}
