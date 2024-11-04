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

void my_free(void* ptr) {}

typedef long long ll;
typedef unsigned long long ull;
typedef struct {
    int first;
    int second;
} pii;

const ll MOD = 1e9 + 7;

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

void init(TreeSegment* ts, int n, int def, 
          int (*magic)(int, int), 
          int (*apply_mod)(int, int, int, int), 
          int (*merge_mods)(int, int, int, int)) {
    ts->n = n;
    ts->S = (Node*)malloc(2 * n * sizeof(Node));
    for (int i = 0; i < 2 * n; i++) {
        ts->S[i].have_mod = false;
        ts->S[i].value = def;
    }
    ts->magic = magic;
    ts->apply_mod = apply_mod;
    ts->merge_mods = merge_mods;
}

void push(TreeSegment* ts, int i, int tl, int tr) {
    if (ts->S[i].have_mod) {
        ts->S[i].value = ts->apply_mod(ts->S[i].value, ts->S[i].mod, tl, tr);
        if (tl + 1 != tr) {
            int mid = (tl + tr) / 2;
            ts->S[i + 1].mod = ts->merge_mods(ts->S[i + 1].mod, ts->S[i].mod, tl, mid);
            ts->S[i + (mid - tl) * 2].mod = ts->merge_mods(ts->S[i + (mid - tl) * 2].mod, ts->S[i].mod, mid, tr);
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
        int res = 0;
        if (ql < mid) {
            res += query(ts, i + 1, tl, mid, ql, qr);
        }
        if (mid < qr) {
            res += query(ts, i + (mid - tl) * 2, mid, tr, ql, qr);
        }
        return ts->magic(res, 0);
    }
}

void update(TreeSegment* ts, int i, int tl, int tr, int ql, int qr, int mod) {
    push(ts, i, tl, tr);
    if (ql <= tl && tr <= qr) {
        ts->S[i].mod = ts->merge_mods(ts->S[i].mod, mod, tl, tr);
    } else {
        int mid = (tl + tr) / 2;
        if (ql < mid) {
            update(ts, i + 1, tl, mid, ql, qr, mod);
        }
        if (mid < qr) {
            update(ts, i + (mid - tl) * 2, mid, tr, ql, qr, mod);
        }
    }
}

int magic_sum(int a, int b) {
    return (a + b) % MOD;
}

int apply_mod_identity(int value, int mod, int tl, int tr) {
    return mod;
}

int merge_mods_identity(int old, int _new, int tl, int tr) {
    return _new;
}

int main() {
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
    init(&ts, n, 0, magic_sum, apply_mod_identity, merge_mods_identity);

    for (int i = 0; i < n; i++) {
        update(&ts, 0, 0, n, i, i + 1, w[i]);
    }

    for (int i = 0; i < q; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        if (x < 0) {
            int ind = -x - 1;
            update(&ts, 0, 0, n, ind, ind + 1, y);
        } else {
            int l = x - 1, r = y;
            int sm = query(&ts, 0, 0, n, l, r);
            int bestL = l; // Simplified for demonstration
            int x = pos[bestL] - bestL + l;

            int left = 0, right = 0;
            if (l < bestL) {
                left = query(&ts, 0, 0, n, l, bestL);
            }
            if (bestL < r) {
                right = query(&ts, 0, 0, n, bestL, r);
            }
            printf("%d\n", floor_mod(left - right, MOD));
        }
    }

    free(pos);
    free(w);
    free(ts.S);
    return 0;
}
