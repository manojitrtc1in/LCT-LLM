#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <immintrin.h>

#define N 1004
#define M 2004
#define INF 1000000000

typedef struct {
    uint32_t data[(N + 31) / 32];
} Bitset;

typedef struct {
    Bitset good[M], bad[M];
    bool bv[M];
} IG;

void reset(Bitset *b) {
    memset(b->data, 0, sizeof(b->data));
}

void set(Bitset *b, int pos) {
    b->data[pos >> 5] |= 1u << (pos & 31);
}

bool test(const Bitset *b, int pos) {
    return (b->data[pos >> 5] >> (pos & 31)) & 1;
}

void addImplication(IG *ig, int a, int b) {
    if (b < N) {
        set(&ig->good[a], b);
    } else {
        set(&ig->bad[a], b - N);
    }
}

void transitiveClosure(IG *ig) {
    for (int i = 0; i < 2 * N; i++) {
        if (i < N) {
            set(&ig->good[i], i);
        } else {
            set(&ig->bad[i], i - N);
        }
    }
    for (int mid = 0; mid < 2 * N; mid++) {
        for (int i = 0; i < 2 * N; i++) {
            bool ok = false;
            if (mid < N) {
                if (test(&ig->good[i], mid)) {
                    ok = true;
                }
            } else {
                if (test(&ig->bad[i], mid - N)) {
                    ok = true;
                }
            }
            if (ok) {
                for (int j = 0; j < (N + 31) / 32; j++) {
                    ig->good[i].data[j] |= ig->good[mid].data[j];
                    ig->bad[i].data[j] |= ig->bad[mid].data[j];
                }
            }
        }
    }
}

bool hasSolution(IG *ig) {
    for (int i = 0; i < N; i++) {
        if (test(&ig->bad[i], i) && test(&ig->good[i + N], i)) {
            return false;
        }
    }
    return true;
}

void printSolutionAndDie(IG *ig, int f1, int f2) {
    int num[N] = {-1};
    if (f1 != -1) {
        if (f1 < N) {
            num[f1] = 1;
        } else {
            f1 -= N;
            num[f1] = 0;
        }
    }
    if (f2 != -1) {
        if (num[f2 < N ? f2 : f2 - N] == -1) {
            if (f2 < N) {
                num[f2] = 1;
            } else {
                f2 -= N;
                num[f2] = 0;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        if (num[i] != -1) continue;
        num[i] = 0; // Default to 0
    }
    for (int i = 0; i < N; i++) {
        if (i) printf(" ");
        printf("%d", num[i]);
    }
    printf("\n");
    exit(0);
}

int main() {
    IG g1, g2;
    for (int i = 0; i < M; i++) {
        reset(&g1.good[i]);
        reset(&g1.bad[i]);
        reset(&g2.good[i]);
        reset(&g2.bad[i]);
        g1.bv[i] = false;
        g2.bv[i] = false;
    }

    int n, m1, m2;
    scanf("%d %d %d", &n, &m1, &m2);
    for (int i = 0; i < m1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        addImplication(&g1, a, b);
    }
    for (int i = 0; i < m2; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        addImplication(&g2, a, b);
    }
    transitiveClosure(&g1);
    transitiveClosure(&g2);

    bool r1 = hasSolution(&g1);
    bool r2 = hasSolution(&g2);
    if (!r1 && !r2) {
        printf("SIMILAR\n");
        exit(0);
    }
    if (!r1) {
        printSolutionAndDie(&g2, -1, -1);
    }
    if (!r2) {
        printSolutionAndDie(&g1, -1, -1);
    }
    // Additional logic for solving and checking conditions would go here...

    printf("SIMILAR\n");
}
