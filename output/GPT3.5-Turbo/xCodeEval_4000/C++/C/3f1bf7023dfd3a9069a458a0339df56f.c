#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 1004
#define MAX_M 2004

typedef struct {
    unsigned int data[MAX_N];
} Bitset;

void Bitset_set(Bitset* set, int pos) {
    set->data[pos >> 5] |= 1u << (pos & 31);
}

void Bitset_reset(Bitset* set, int pos) {
    set->data[pos >> 5] &= ~(1u << (pos & 31));
}

int Bitset_test(const Bitset* set, int pos) {
    return (set->data[pos >> 5] >> (pos & 31)) & 1;
}

void Bitset_or(Bitset* res, const Bitset* set1, const Bitset* set2) {
    int i;
    for (i = 0; i < MAX_N; i++) {
        res->data[i] = set1->data[i] | set2->data[i];
    }
}

void Bitset_and(Bitset* res, const Bitset* set1, const Bitset* set2) {
    int i;
    for (i = 0; i < MAX_N; i++) {
        res->data[i] = set1->data[i] & set2->data[i];
    }
}

void Bitset_xor(Bitset* res, const Bitset* set1, const Bitset* set2) {
    int i;
    for (i = 0; i < MAX_N; i++) {
        res->data[i] = set1->data[i] ^ set2->data[i];
    }
}

void Bitset_shift_left(Bitset* set, int shift) {
    int i;
    const int full = shift >> 5;
    const int partial = shift & 31;

    if (full >= MAX_N) {
        memset(set->data, 0, MAX_N * sizeof(unsigned int));
        return;
    }

    if (full) {
        memmove(set->data + full, set->data, (MAX_N - full) * sizeof(unsigned int));
        memset(set->data, 0, full * sizeof(unsigned int));
    }

    if (partial) {
        for (i = MAX_N - 1; i >= 1; i--) {
            set->data[i] = (set->data[i] << partial) | (set->data[i - 1] >> (32 - partial));
        }
        set->data[0] <<= partial;
    }
}

void Bitset_shift_right(Bitset* set, int shift) {
    int i;
    const int full = shift >> 5;
    const int partial = shift & 31;

    if (full >= MAX_N) {
        memset(set->data, 0, MAX_N * sizeof(unsigned int));
        return;
    }

    if (full) {
        memmove(set->data, set->data + full, (MAX_N - full) * sizeof(unsigned int));
        memset(set->data + MAX_N - full, 0, full * sizeof(unsigned int));
    }

    if (partial) {
        const unsigned int mask = (1u << partial) - 1;
        for (i = 0; i < MAX_N - 1; i++) {
            set->data[i] = (set->data[i] >> partial) | ((set->data[i + 1] & mask) << (32 - partial));
        }
        set->data[MAX_N - 1] >>= partial;
    }
}

void Bitset_copy(Bitset* dest, const Bitset* src) {
    memcpy(dest->data, src->data, MAX_N * sizeof(unsigned int));
}

void Bitset_reset_all(Bitset* set) {
    memset(set->data, 0, MAX_N * sizeof(unsigned int));
}

void Bitset_set_all(Bitset* set) {
    memset(set->data, 255, MAX_N * sizeof(unsigned int));
}

int Bitset_count(const Bitset* set) {
    int count = 0;
    int i;
    for (i = 0; i < MAX_N; i++) {
        unsigned int val = set->data[i];
        while (val) {
            count++;
            val &= val - 1;
        }
    }
    return count;
}

int Bitset_none(const Bitset* set) {
    int i;
    for (i = 0; i < MAX_N; i++) {
        if (set->data[i] != 0) {
            return 0;
        }
    }
    return 1;
}

int Bitset_any(const Bitset* set) {
    int i;
    for (i = 0; i < MAX_N; i++) {
        if (set->data[i] != 0) {
            return 1;
        }
    }
    return 0;
}

int Bitset_ctz(const Bitset* set) {
    int i;
    for (i = 0; i < MAX_N; i++) {
        unsigned int val = set->data[i];
        if (val != 0) {
            int count = 0;
            while ((val & 1) == 0) {
                val >>= 1;
                count++;
            }
            return count + (i << 5);
        }
    }
    return MAX_N << 5;
}

int Bitset_clz(const Bitset* set) {
    int i;
    for (i = MAX_N - 1; i >= 0; i--) {
        unsigned int val = set->data[i];
        if (val != 0) {
            int count = 0;
            while (val != 0) {
                val >>= 1;
                count++;
            }
            return (MAX_N - i - 1) << 5 + (32 - count);
        }
    }
    return 0;
}

void Bitset_init(Bitset* set) {
    Bitset_reset_all(set);
}

typedef struct {
    Bitset good[MAX_M];
    Bitset bad[MAX_M];
    int bv[MAX_M];
} IG;

void IG_init(IG* ig) {
    int i;
    for (i = 0; i < MAX_M; i++) {
        Bitset_init(&ig->good[i]);
        Bitset_init(&ig->bad[i]);
        ig->bv[i] = 0;
    }
}

int IG_getNum(int a, int n) {
    if (a > 0) {
        return a - 1;
    } else {
        return n + a - 1;
    }
}

int IG_neg(int a, int n) {
    if (a < n) {
        return a + n;
    } else {
        return a - n;
    }
}

void IG_addImplication(IG* ig, int a, int b, int n) {
    a = IG_getNum(a, n);
    b = IG_getNum(b, n);
    if (b < n) {
        Bitset_set(&ig->good[a], b);
    } else {
        Bitset_set(&ig->bad[a], b - n);
    }
}

void IG_add(IG* ig, int a, int b, int n) {
    IG_addImplication(ig, -a, b, n);
    IG_addImplication(ig, -b, a, n);
}

void IG_transitiveClosure(IG* ig, int n) {
    int i, j, k;
    for (i = 0; i < 2 * n; i++) {
        if (i < n) {
            Bitset_set(&ig->good[i], i);
        } else {
            Bitset_set(&ig->bad[i], i - n);
        }
    }

    for (k = 0; k < 2 * n; k++) {
        for (i = 0; i < 2 * n; i++) {
            if (i < n) {
                if (Bitset_test(&ig->good[i], k)) {
                    Bitset_or(&ig->good[i], &ig->good[i], &ig->good[k]);
                }
            } else {
                if (Bitset_test(&ig->bad[i], k - n)) {
                    Bitset_or(&ig->bad[i], &ig->bad[i], &ig->bad[k]);
                }
            }
        }
    }

    for (i = 0; i < 2 * n; i++) {
        if (i < n) {
            if (Bitset_test(&ig->bad[i], i) && Bitset_test(&ig->good[i + n], i)) {
                ig->bv[i] = 1;
            }
        } else {
            if (Bitset_test(&ig->good[i], i - n) && Bitset_test(&ig->bad[i], i - n)) {
                ig->bv[i] = 1;
            }
        }
    }

    for (i = 0; i < 2 * n; i++) {
        for (j = 0; j < 2 * n; j++) {
            if (!ig->bv[j]) {
                if (j < n) {
                    if (Bitset_test(&ig->good[i], j)) {
                        ig->bv[i] = 1;
                    }
                } else {
                    if (Bitset_test(&ig->bad[i], j - n)) {
                        ig->bv[i] = 1;
                    }
                }
            }
        }
    }
}

int IG_hasSolution(const IG* ig, int n) {
    int i;
    for (i = 0; i < n; i++) {
        if (Bitset_test(&ig->bad[i], i) && Bitset_test(&ig->good[i + n], i)) {
            return 0;
        }
    }
    return 1;
}

void IG_select(IG* ig, int v, int n) {
    int t = v;
    if (t < 0) {
        t += n;
    }
    if (ig->bv[t]) {
        return;
    }

    int k = 0;
    int sof[MAX_M];
    sof[k++] = v;
    int ok = 1;
    int i;
    for (i = 0; i < n; i++) {
        if (Bitset_test(&ig->good[t], i)) {
            if (ig->bv[i] == 0) {
                ok = 0;
                break;
            }
            if (ig->bv[i] == -1) {
                ig->bv[i] = 1;
                sof[k++] = i;
            }
        }
        if (Bitset_test(&ig->bad[t], i)) {
            if (ig->bv[i] == 1) {
                ok = 0;
                break;
            }
            if (ig->bv[i] == -1) {
                ig->bv[i] = 0;
                sof[k++] = i;
            }
        }
    }

    if (!ok) {
        for (i = 0; i < k; i++) {
            ig->bv[sof[i]] = -1;
        }
        return;
    }
}

void IG_printSolutionAndDie(const IG* ig, int f1, int f2, int n) {
    int num[MAX_N];
    memset(num, -1, sizeof(num));

    if (f1 != -1) {
        if (f1 < n) {
            num[f1] = 1;
        } else {
            f1 -= n;
            num[f1] = 0;
        }
        IG_select(ig, f1, n);
    }

    if (f2 != -1) {
        if (num[f2 < n ? f2 : f2 - n] == -1) {
            if (f2 < n) {
                num[f2] = 1;
            } else {
                f2 -= n;
                num[f2] = 0;
            }
            IG_select(ig, f2, n);
        }
    }

    int i;
    for (i = 0; i < n; i++) {
        if (num[i] == -1) {
            num[i] = 0;
            if (!IG_select(ig, i, n)) {
                num[i] = 1;
                IG_select(ig, i, n);
            }
        }
    }

    for (i = 0; i < n; i++) {
        if (i > 0) {
            printf(" ");
        }
        printf("%d", num[i]);
    }
    printf("\n");
    exit(0);
}

int IG_checkBad(const IG* ig, int v1, int v2) {
    Bitset t;
    Bitset_or(&t, &ig->good[v1], &ig->good[v2]);
    Bitset_and(&t, &t, &ig->bad[v1]);
    Bitset_and(&t, &t, &ig->bad[v2]);
    return !Bitset_none(&t);
}

void solve(pii* cl1, pii* cl2, IG* g1, IG* g2, int m1, int m2, int n) {
    int used[MAX_M][MAX_M];
    memset(used, 0, sizeof(used));

    int i;
    for (i = 0; i < m1; i++) {
        int v1 = IG_getNum(cl1[i].x, n);
        int v2 = IG_getNum(cl1[i].y, n);
        v1 = IG_neg(v1, n);
        v2 = IG_neg(v2, n);
        if (v1 > v2) {
            int temp = v1;
            v1 = v2;
            v2 = temp;
        }
        if (used[v1][v2]) {
            continue;
        }
        used[v1][v2] = 1;

        if (g2->bv[v1] || g2->bv[v2]) {
            continue;
        }
        if (IG_checkBad(g2, v1, v2)) {
            continue;
        }
        IG_printSolutionAndDie(g2, v1, v2, n);
    }
}

int main() {
    int n, m1, m2;
    scanf("%d %d %d", &n, &m1, &m2);

    IG g1, g2;
    IG_init(&g1);
    IG_init(&g2);

    int i;
    int a, b;
    pii cl1[MAX_M], cl2[MAX_M];
    for (i = 0; i < m1; i++) {
        scanf("%d %d", &a, &b);
        cl1[i].x = a;
        cl1[i].y = b;
        IG_add(&g1, a, b, n);
    }
    for (i = 0; i < m2; i++) {
        scanf("%d %d", &a, &b);
        cl2[i].x = a;
        cl2[i].y = b;
        IG_add(&g2, a, b, n);
    }

    IG_transitiveClosure(&g1, n);
    IG_transitiveClosure(&g2, n);

    int r1 = IG_hasSolution(&g1, n);
    int r2 = IG_hasSolution(&g2, n);
    if (!r1 && !r2) {
        printf("SIMILAR\n");
        return 0;
    }
    if (!r1) {
        IG_printSolutionAndDie(&g2, -1, -1, n);
    }
    if (!r2) {
        IG_printSolutionAndDie(&g1, -1, -1, n);
    }

    solve(cl1, cl2, &g1, &g2, m1, m2, n);
    solve(cl2, cl1, &g2, &g1, m2, m1, n);

    printf("SIMILAR\n");
    return 0;
}
