#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

#define MAXMEM (200 * 1000 * 1024)
char _memory[MAXMEM];
size_t _ptr = 0;

void* my_malloc(size_t _x) {
    _ptr += _x;
    assert(_ptr < MAXMEM);
    return _memory + _ptr - _x;
}

void my_free(void*) {}

#define int long long

typedef struct {
    bool have_mod;
    int value;
    int mod;
} Node;

typedef struct {
    Node* S;
    int n;
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

bool intersects(int tl, int tr, int ql, int qr) {
    return !(tr <= ql || qr <= tl);
}

int get_value(TreeSegment* ts, int i, int tl, int tr) {
    if (!ts->S[i].have_mod) return ts->S[i].value;
    return ts->apply_mod(ts->S[i].value, ts->S[i].mod, tl, tr);
}

void recalc_value(TreeSegment* ts, int i, int tl, int tr) {
    if (tl + 1 != tr) {
        int mid = (tl + tr) / 2;
        ts->S[i].value = ts->magic(
            get_value(ts, i + 1, tl, mid),
            get_value(ts, i + (mid - tl) * 2, mid, tr)
        );
    }
}

void add_mod(TreeSegment* ts, int i, int tl, int tr, int sub) {
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
            add_mod(ts, i + 1, tl, mid, ts->S[i].mod);
            add_mod(ts, i + (mid - tl) * 2, mid, tr, ts->S[i].mod);
        }
        ts->S[i].have_mod = false;
    }
}

void init(TreeSegment* ts, int i, int tl, int tr, int* src) {
    if (tl + 1 == tr) {
        ts->S[i].value = src[tl];
    } else {
        int mid = (tl + tr) / 2;
        init(ts, i + 1, tl, mid, src);
        init(ts, i + (mid - tl) * 2, mid, tr, src);
        recalc_value(ts, i, tl, tr);
    }
}

int query(TreeSegment* ts, int i, int tl, int tr, int ql, int qr) {
    push(ts, i, tl, tr);
    if (ql <= tl && tr <= qr) {
        return ts->S[i].value;
    } else {
        int mid = (tl + tr) / 2;
        if (intersects(tl, mid, ql, qr) && intersects(mid, tr, ql, qr)) {
            return ts->magic(
                query(ts, i + 1, tl, mid, ql, qr),
                query(ts, i + (mid - tl) * 2, mid, tr, ql, qr)
            );
        } else if (intersects(tl, mid, ql, qr)) {
            return query(ts, i + 1, tl, mid, ql, qr);
        } else {
            return query(ts, i + (mid - tl) * 2, mid, tr, ql, qr);
        }
    }
}

void change(TreeSegment* ts, int i, int tl, int tr, int j, int _new) {
    push(ts, i, tl, tr);
    if (tl + 1 == tr) {
        ts->S[i].value = _new;
    } else {
        int m = (tl + tr) / 2;
        if (j < m) {
            change(ts, ts->S[i].l, tl, m, j, _new);
        } else {
            change(ts, ts->S[i].r, m, tr, j, _new);
        }
        recalc_value(ts, i, tl, tr);
    }
}

void update(TreeSegment* ts, int i, int tl, int tr, int ql, int qr, int mod) {
    push(ts, i, tl, tr);
    if (ql <= tl && tr <= qr) {
        add_mod(ts, i, tl, tr, mod);
    } else {
        int mid = (tl + tr) / 2;
        if (intersects(tl, mid, ql, qr)) {
            update(ts, i + 1, tl, mid, ql, qr, mod);
        }
        if (intersects(mid, tr, ql, qr)) {
            update(ts, i + (mid - tl) * 2, mid, tr, ql, qr, mod);
        }
        recalc_value(ts, i, tl, tr);
    }
}

void init_tree_segment(TreeSegment* ts, int n, int def, 
                       int (*magic)(int, int), 
                       int (*apply_mod)(int, int, int, int), 
                       int (*merge_mods)(int, int, int, int)) {
    ts->n = n;
    ts->S = (Node*)my_malloc((2 * n + 1) * sizeof(Node));
    for (int i = 0; i < 2 * n + 1; i++) {
        ts->S[i].have_mod = false;
        ts->S[i].value = def;
        ts->S[i].mod = 0;
    }
    ts->magic = magic;
    ts->apply_mod = apply_mod;
    ts->merge_mods = merge_mods;
}

int sum(int a, int b) {
    return a + b;
}

int main() {
    int n, q;
    scanf("%lld %lld", &n, &q);
    
    int* pos = (int*)malloc(n * sizeof(int));
    int* w = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%lld", &pos[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%lld", &w[i]);
    }

    TreeSegment ts;
    init_tree_segment(&ts, n, 0, sum, [](int value, int mod, int, int) { return mod; }, 
                      [](int old, int _new, int, int) { return _new; });

    int* subw = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        subw[i] = (w[i] * (i - pos[i])) % (1000000007);
    }

    TreeSegment resp;
    init_tree_segment(&resp, n, 0, sum, [](int value, int mod, int, int) { return mod; }, 
                      [](int old, int _new, int, int) { return _new; });

    for (int i = 0; i < q; i++) {
        int x, y;
        scanf("%lld %lld", &x, &y);
        if (x < 0) {
            int ind = -x;
            int _new = y;
            ind--;
            update(&ts, 0, 0, n, ind, ind + 1, _new);
            update(&resp, 0, 0, n, ind, ind + 1, (_new * (ind - pos[ind])) % (1000000007));
        } else {
            int l = x, r = y;
            l--;

            int sm = query(&ts, 0, 0, n, l, r);

            int bestL = find_right(&ts, l, sm);

            int x = pos[bestL] - bestL + l;

            int left = 0;
            if (l < bestL) {
                left = query(&resp, 0, 0, n, l, bestL) + query(&ts, 0, 0, n, l, bestL) * (x - l);
            }
            int right = 0;
            if (bestL < r) {
                right = query(&resp, 0, 0, n, bestL, r) + query(&ts, 0, 0, n, bestL, r) * (x - l);
            }
            printf("%lld\n", floor_mod(left - right, 1000000007));
        }
    }

    free(pos);
    free(w);
    free(subw);
    free(ts.S);
    free(resp.S);
    return 0;
}
