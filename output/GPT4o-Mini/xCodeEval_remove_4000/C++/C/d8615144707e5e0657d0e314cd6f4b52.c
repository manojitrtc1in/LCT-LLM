#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <immintrin.h>

#define MAX_N 1004
#define MAX_M 2004
#define MAX_C 1000002

typedef struct {
    unsigned data[(MAX_N + 31) / 32];
} Bitset;

void Bitset_init(Bitset *b) {
    memset(b->data, 0, sizeof(b->data));
}

void Bitset_set(Bitset *b, int pos) {
    b->data[pos >> 5] |= 1u << (pos & 31);
}

void Bitset_reset(Bitset *b) {
    memset(b->data, 0, sizeof(b->data));
}

int Bitset_test(Bitset *b, int pos) {
    return (b->data[pos >> 5] >> (pos & 31)) & 1;
}

void Bitset_or(Bitset *a, Bitset *b) {
    for (int i = 0; i < (MAX_N + 31) / 32; ++i) {
        a->data[i] |= b->data[i];
    }
}

void Bitset_transitiveClosure(Bitset *good, Bitset *bad, int n) {
    for (int i = 0; i < 2 * n; ++i) {
        if (i < n) {
            Bitset_set(good + i, i);
        } else {
            Bitset_set(bad + (i - n), i);
        }
    }
    for (int mid = 0; mid < 2 * n; ++mid) {
        for (int i = 0; i < 2 * n; ++i) {
            int ok = 0;
            if (mid < n) {
                if (Bitset_test(good + i, mid)) {
                    ok = 1;
                }
            } else {
                if (Bitset_test(bad + (i - n), mid - n)) {
                    ok = 1;
                }
            }
            if (ok) {
                Bitset_or(good + i, good + mid);
                Bitset_or(bad + i, bad + mid);
            }
        }
    }
}

typedef struct {
    Bitset good[MAX_M], bad[MAX_M];
    int bv[MAX_M];
} IG;

void IG_init(IG *g) {
    for (int i = 0; i < MAX_M; ++i) {
        Bitset_reset(&g->good[i]);
        Bitset_reset(&g->bad[i]);
    }
    memset(g->bv, 0, sizeof(g->bv));
}

int getNum(int a, int n) {
    if (a > 0) return a - 1;
    a = -a;
    return n + a - 1;
}

int neg(int a, int n) {
    if (a < n) return a + n; else
        return a - n;
}

void addImplication(IG *g, int a, int b, int n) {
    a = getNum(a, n);
    b = getNum(b, n);
    if (b < n) {
        Bitset_set(&g->good[a], b);
    } else {
        Bitset_set(&g->bad[a], b - n);
    }
}

void add(IG *g, int a, int b, int n) {
    addImplication(g, -a, b, n);
    addImplication(g, -b, a, n);
}

int main() {
    int n, m1, m2;
    scanf("%d %d %d", &n, &m1, &m2);
    
    IG g1, g2;
    IG_init(&g1);
    IG_init(&g2);
    
    for (int i = 0; i < m1; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        add(&g1, a, b, n);
    }
    
    for (int i = 0; i < m2; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        add(&g2, a, b, n);
    }
    
    Bitset_transitiveClosure(g1.good, g1.bad, n);
    Bitset_transitiveClosure(g2.good, g2.bad, n);
    
    // Further implementation needed for solution checking and printing
    // ...

    return 0;
}
