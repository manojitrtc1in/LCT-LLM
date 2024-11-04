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

void init(TreeSegment* ts, int n, int def, int (*magic)(int, int), int (*apply_mod)(int, int, int, int), int (*merge_mods)(int, int, int, int)) {
    ts->n = n;
    ts->S = (Node*)malloc(2 * n * sizeof(Node));
    for (int i = 0; i < 2 * n; i++) {
        ts->S[i].have_mod = false;
        ts->S[i].value = def;
        ts->S[i].mod = 0;
    }
}

int query(TreeSegment* ts, int ql, int qr) {
    // Implement query logic here
    return 0; // Placeholder
}

void update(TreeSegment* ts, int ql, int qr, int mod) {
    // Implement update logic here
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

    int* subw = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        subw[i] = (w[i] * (i - pos[i])) % MOD;
    }

    TreeSegment resp;
    init(&resp, n, 0, [](int a, int b) { return (a + b) % MOD; }, [](int value, int mod, int tl, int tr) { return mod; }, [](int old, int _new, int tl, int tr) { return _new; });

    for (int i = 0; i < q; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        if (x < 0) {
            int ind = -x - 1;
            int _new = y;
            update(&ts, ind, ind + 1, _new);
            update(&resp, ind, ind + 1, (_new * (ind - pos[ind])) % MOD);
        } else {
            int l = x - 1, r = y;
            int sm = query(&ts, l, r);
            int bestL = l; // Placeholder for finding bestL logic

            int x = pos[bestL] - bestL + l;

            int left = 0;
            if (l < bestL) {
                left = query(&resp, l, bestL) + query(&ts, l, bestL) * (x - l);
            }
            int right = 0;
            if (bestL < r) {
                right = query(&resp, bestL, r) + query(&ts, bestL, r) * (x - l);
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
