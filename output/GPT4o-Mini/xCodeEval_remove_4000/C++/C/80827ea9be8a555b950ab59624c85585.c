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
    int value;
    bool have_mod;
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

void init(TreeSegment* ts, int n, int def, int (*magic)(int, int), int (*apply_mod)(int, int, int, int), int (*merge_mods)(int, int, int, int)) {
    ts->n = n;
    ts->S = (Node*)my_malloc(sizeof(Node) * (2 * n + 1));
    for (int i = 0; i < 2 * n + 1; i++) {
        ts->S[i].have_mod = false;
        ts->S[i].value = def;
    }
    ts->magic = magic;
    ts->apply_mod = apply_mod;
    ts->merge_mods = merge_mods;
}

void update(TreeSegment* ts, int ql, int qr, int mod) {
    // Implementation of update logic
}

int query(TreeSegment* ts, int ql, int qr) {
    // Implementation of query logic
    return 0; // Placeholder
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
    init(&ts, n, 0, [](int a, int b) { return a + b; }, [](int value, int mod, int tl, int tr) { return mod; }, [](int old, int _new, int tl, int tr) { return _new; });

    for (int i = 0; i < q; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        if (x < 0) {
            int ind = -x - 1;
            int _new = y;
            update(&ts, ind, ind + 1, _new);
        } else {
            int l = x - 1, r = y;
            int sm = query(&ts, l, r);
            // Further logic for processing the query
        }
    }

    free(pos);
    free(w);
    return 0;
}
