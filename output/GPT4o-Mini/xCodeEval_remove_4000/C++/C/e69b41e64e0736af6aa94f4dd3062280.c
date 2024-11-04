#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define MAXMEM (200 * 1000 * 1024)
char _memory[MAXMEM];
size_t _ptr = 0;

void* my_malloc(size_t _x) {
    _ptr += _x;
    assert(_ptr < MAXMEM);
    return _memory + _ptr - _x;
}

void my_free(void* ptr) {}

typedef long long ll;
typedef unsigned long long ull;
typedef struct {
    int first;
    int second;
} pii;

const ll MOD = 1e9 + 7;

typedef struct {
    int have_mod;
    int l, r;
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

int create_node(TreeSegment* ts) {
    ts->S = realloc(ts->S, (ts->n + 1) * sizeof(Node));
    return ts->n++;
}

int get_value(TreeSegment* ts, int i) {
    if (!ts->S[i].have_mod) return ts->S[i].value;
    return ts->apply_mod(ts->S[i].value, ts->S[i].mod, 0, 0); // Placeholder for tl, tr
}

void recalc_value(TreeSegment* ts, int i) {
    if (ts->S[i].l != -1) {
        ts->S[i].value = ts->magic(
            get_value(ts, ts->S[i].l),
            get_value(ts, ts->S[i].r)
        );
    }
}

void add_mod(TreeSegment* ts, int i, int sub) {
    if (ts->S[i].have_mod) {
        ts->S[i].mod = ts->merge_mods(ts->S[i].mod, sub, 0, 0); // Placeholder for tl, tr
    } else {
        ts->S[i].mod = sub;
        ts->S[i].have_mod = 1;
    }
}

void push(TreeSegment* ts, int i) {
    if (ts->S[i].have_mod) {
        ts->S[i].value = ts->apply_mod(ts->S[i].value, ts->S[i].mod, 0, 0); // Placeholder for tl, tr
        if (ts->S[i].l != -1) {
            add_mod(ts, ts->S[i].l, ts->S[i].mod);
            add_mod(ts, ts->S[i].r, ts->S[i].mod);
        }
        ts->S[i].have_mod = 0;
    }
}

void init(TreeSegment* ts, int tl, int tr, int* src) {
    int i = create_node(ts);
    if (tl + 1 == tr) {
        ts->S[i].value = src[tl];
    } else {
        int mid = (tl + tr) / 2;
        init(ts, tl, mid, src);
        init(ts, mid, tr, src);
        recalc_value(ts, i);
    }
}

int query(TreeSegment* ts, int i, int tl, int tr, int ql, int qr) {
    push(ts, i);
    if (ql <= tl && tr <= qr) {
        return ts->S[i].value;
    } else {
        int mid = (tl + tr) / 2;
        if (ql < mid) {
            return ts->magic(query(ts, ts->S[i].l, tl, mid, ql, qr), query(ts, ts->S[i].r, mid, tr, ql, qr));
        } else {
            return query(ts, ts->S[i].r, mid, tr, ql, qr);
        }
    }
}

void update(TreeSegment* ts, int i, int tl, int tr, int ql, int qr, int mod) {
    push(ts, i);
    if (ql <= tl && tr <= qr) {
        add_mod(ts, i, mod);
    } else {
        int mid = (tl + tr) / 2;
        if (ql < mid) update(ts, ts->S[i].l, tl, mid, ql, qr, mod);
        if (mid < qr) update(ts, ts->S[i].r, mid, tr, ql, qr, mod);
        recalc_value(ts, i);
    }
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    int* pos = malloc(n * sizeof(int));
    int* w = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &pos[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
    }

    TreeSegment ts = {NULL, 0, NULL, NULL, NULL};
    ts.magic = [](int a, int b) { return a + b; };
    ts.apply_mod = [](int value, int mod, int tl, int tr) { return mod; };
    ts.merge_mods = [](int old, int _new, int tl, int tr) { return _new; };
    init(&ts, 0, n, w);

    int* subw = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        subw[i] = (w[i] * (i - pos[i])) % MOD;
    }

    TreeSegment resp = {NULL, 0, NULL, NULL, NULL};
    resp.magic = [](int a, int b) { return (a + b) % MOD; };
    resp.apply_mod = [](int value, int mod, int tl, int tr) { return mod; };
    resp.merge_mods = [](int old, int _new, int tl, int tr) { return _new; };
    init(&resp, 0, n, subw);

    for (int i = 0; i < q; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        if (x < 0) {
            int ind = -x - 1;
            int _new = y;
            update(&ts, 0, 0, n, ind, ind + 1, _new);
            update(&resp, 0, 0, n, ind, ind + 1, (_new * (ind - pos[ind])) % MOD);
        } else {
            int l = x - 1, r = y;
            int sm = query(&ts, 0, 0, n, l, r);
            int bestL = l; // Placeholder for finding right

            int x = pos[bestL] - bestL + l;

            int left = 0;
            if (l < bestL) {
                left = query(&resp, 0, 0, n, l, bestL) + query(&ts, 0, 0, n, l, bestL) * (x - l);
            }
            int right = 0;
            if (bestL < r) {
                right = query(&resp, 0, 0, n, bestL, r) + query(&ts, 0, 0, n, bestL, r) * (x - l);
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
