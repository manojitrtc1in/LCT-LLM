#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

#define MAXMEM (200 * 1000 * 1024)
#define MOD 1000000007

char _memory[MAXMEM];
size_t _ptr = 0;

void* my_malloc(size_t size) {
    _ptr += size;
    assert(_ptr < MAXMEM);
    return _memory + _ptr - size;
}

void my_free(void* ptr) {}

typedef long long ll;
typedef unsigned long long ull;
typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int* data;
    int size;
    int capacity;
} vector;

void vector_init(vector* v, int capacity) {
    v->data = (int*)my_malloc(capacity * sizeof(int));
    v->size = 0;
    v->capacity = capacity;
}

void vector_push_back(vector* v, int value) {
    if (v->size >= v->capacity) {
        v->capacity *= 2;
        v->data = (int*)my_malloc(v->capacity * sizeof(int));
    }
    v->data[v->size++] = value;
}

typedef struct {
    bool have_mod;
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

bool intersects(int tl, int tr, int ql, int qr) {
    return !(tr <= ql || qr <= tl);
}

int create_node(TreeSegment* ts) {
    ts->S = (Node*)my_malloc((ts->n + 1) * sizeof(Node));
    return ts->n++;
}

int get_value(TreeSegment* ts, int i, int tl, int tr) {
    if (!ts->S[i].have_mod) return ts->S[i].value;
    return ts->apply_mod(ts->S[i].value, ts->S[i].mod, tl, tr);
}

void recalc_value(TreeSegment* ts, int i, int tl, int tr) {
    if (tl + 1 != tr) {
        int mid = (tl + tr) / 2;
        ts->S[i].value = ts->magic(
            get_value(ts, ts->S[i].l, tl, mid),
            get_value(ts, ts->S[i].r, mid, tr)
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

int query(TreeSegment* ts, int i, int tl, int tr, int ql, int qr) {
    push(ts, i, tl, tr);
    if (ql <= tl && tr <= qr) {
        return ts->S[i].value;
    } else {
        int mid = (tl + tr) / 2;
        if (intersects(tl, mid, ql, qr) && intersects(mid, tr, ql, qr)) {
            return ts->magic(
                query(ts, ts->S[i].l, tl, mid, ql, qr),
                query(ts, ts->S[i].r, mid, tr, ql, qr)
            );
        } else if (intersects(tl, mid, ql, qr)) {
            return query(ts, ts->S[i].l, tl, mid, ql, qr);
        } else if (intersects(mid, tr, ql, qr)) {
            return query(ts, ts->S[i].r, mid, tr, ql, qr);
        } else {
            assert(false);
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

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    
    vector pos, w;
    vector_init(&pos, n);
    vector_init(&w, n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &pos.data[i]);
    }
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &w.data[i]);
    }

    TreeSegment ts;
    ts.n = 0;
    ts.S = (Node*)my_malloc(n * sizeof(Node));
    ts.magic = [](int a, int b) { return a + b; };
    ts.apply_mod = [](int value, int mod, int, int) { return mod; };
    ts.merge_mods = [](int old, int _new, int, int) { return _new; };
    init(&ts, 0, n, w.data);

    int* subw = (int*)my_malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        subw[i] = (w.data[i] * (i - pos.data[i])) % MOD;
    }

    TreeSegment resp;
    resp.n = 0;
    resp.S = (Node*)my_malloc(n * sizeof(Node));
    resp.magic = [](int a, int b) { return (a + b) % MOD; };
    resp.apply_mod = [](int value, int mod, int, int) { return mod; };
    resp.merge_mods = [](int old, int _new, int, int) { return _new; };
    init(&resp, 0, n, subw);

    for (int i = 0; i < q; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        if (x < 0) {
            int ind = -x - 1;
            int _new = y;
            update(&ts, 0, 0, n, ind, ind + 1, _new);
            update(&resp, 0, 0, n, ind, ind + 1, (_new * (ind - pos.data[ind])) % MOD);
        } else {
            int l = x - 1, r = y;
            int sm = query(&ts, 0, 0, n, l, r);
            int bestL = l; // Simplified for demonstration
            int x = pos.data[bestL] - bestL + l;

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

    return 0;
}
