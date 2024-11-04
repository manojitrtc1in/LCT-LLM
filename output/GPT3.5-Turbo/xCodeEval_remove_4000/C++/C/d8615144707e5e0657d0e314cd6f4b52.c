#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 1004

typedef struct {
    unsigned data[N];
} Bitset;

typedef struct {
    Bitset good[2004];
    Bitset bad[2004];
    int bv[2004];
} IG;

int n, m1, m2;
int a, b;
int used[2002][2002];
int cl1[1000002][2];
int cl2[1000002][2];

void Bitset_set(Bitset* bs) {
    memset(bs->data, 255, N * sizeof(unsigned));
}

void Bitset_setPos(Bitset* bs, int pos) {
    bs->data[pos >> 5] |= 1u << (pos & 31);
}

void Bitset_reset(Bitset* bs) {
    memset(bs->data, 0, N * sizeof(unsigned));
}

void Bitset_resetPos(Bitset* bs, int pos) {
    bs->data[pos >> 5] &= ~(1u << (pos & 31));
}

void Bitset_flipPos(Bitset* bs, int pos) {
    bs->data[pos >> 5] ^= 1u << (pos & 31);
}

int Bitset_testPos(const Bitset* bs, int pos) {
    return (bs->data[pos >> 5] >> (pos & 31)) & 1;
}

void Bitset_or(Bitset* res, const Bitset* bs1, const Bitset* bs2) {
    for (int i = 0; i < N; ++i) {
        res->data[i] = bs1->data[i] | bs2->data[i];
    }
}

void Bitset_and(Bitset* res, const Bitset* bs1, const Bitset* bs2) {
    for (int i = 0; i < N; ++i) {
        res->data[i] = bs1->data[i] & bs2->data[i];
    }
}

void Bitset_xor(Bitset* res, const Bitset* bs1, const Bitset* bs2) {
    for (int i = 0; i < N; ++i) {
        res->data[i] = bs1->data[i] ^ bs2->data[i];
    }
}

void Bitset_shiftLeft(Bitset* bs, int shift) {
    const int full = shift >> 5;
    if (full >= N) {
        Bitset_reset(bs);
        return;
    }
    if (full) {
        memmove(bs->data + full, bs->data, (N - full) * sizeof(unsigned));
        memset(bs->data, 0, full * sizeof(unsigned));
    }

    shift &= 31;
    if (shift) {
        int i = N - 1;
        for (; i >= 4; i -= 4) {
            unsigned P = bs->data[i - 4];
            unsigned A = bs->data[i - 3];
            P = P >> (32 - shift);
            A = A << shift;
            A = A | P;
            bs->data[i - 3] = A;
        }
        for (; i >= 1; --i) {
            bs->data[i] = (bs->data[i] << shift) | (bs->data[i - 1] >> (32 - shift));
        }
        bs->data[0] = bs->data[0] << shift;
    }
}

void Bitset_shiftRight(Bitset* bs, int shift) {
    const int full = shift >> 5;
    if (full >= N) {
        Bitset_reset(bs);
        return;
    }
    if (full) {
        memmove(bs->data, bs->data + full, (N - full) * sizeof(unsigned));
        memset(bs->data + N - full, 0, full * sizeof(unsigned));
    }

    shift &= 31;
    if (shift) {
        const unsigned u = (1u << shift) - 1;
        int i = 0;
        const unsigned U = u | (u << 8) | (u << 16) | (u << 24);
        for (; i + 4 < N - 1; i += 4) {
            unsigned NX = bs->data[i + 1];
            unsigned A = bs->data[i];
            NX = NX & U;
            NX = NX << (32 - shift);
            A = A >> shift;
            A = A | NX;
            bs->data[i] = A;
        }
        for (; i < N - 1; ++i) {
            bs->data[i] = (bs->data[i] >> shift) | ((bs->data[i + 1] & u) << (32 - shift));
        }
        bs->data[N - 1] = bs->data[N - 1] >> shift;
    }
}

void Bitset_copy(Bitset* dest, const Bitset* src) {
    memcpy(dest->data, src->data, N * sizeof(unsigned));
}

void Bitset_init(Bitset* bs) {
    Bitset_reset(bs);
}

void IG_init(IG* ig) {
    for (int i = 0; i < 2004; ++i) {
        Bitset_init(&ig->good[i]);
        Bitset_init(&ig->bad[i]);
    }
    memset(ig->bv, 0, 2004 * sizeof(int));
}

int IG_getNum(int a) {
    if (a > 0) {
        return a - 1;
    }
    a = -a;
    return n + a - 1;
}

int IG_neg(int a) {
    if (a < n) {
        return a + n;
    }
    return a - n;
}

void IG_addImplication(IG* ig, int a, int b) {
    a = IG_getNum(a);
    b = IG_getNum(b);
    if (b < n) {
        Bitset_setPos(&ig->good[a], b);
    }
    else {
        Bitset_setPos(&ig->bad[a], b - n);
    }
}

void IG_add(IG* ig, int a, int b) {
    IG_addImplication(ig, -a, b);
    IG_addImplication(ig, -b, a);
}

void IG_transitiveClosure(IG* ig) {
    for (int i = 0; i < 2 * n; ++i) {
        if (i < n) {
            Bitset_setPos(&ig->good[i], i);
        }
        else {
            Bitset_setPos(&ig->bad[i], i - n);
        }
    }
    for (int mid = 0; mid < 2 * n; ++mid) {
        for (int i = 0; i < 2 * n; ++i) {
            int ok = 0;
            if (mid < n) {
                if (Bitset_testPos(&ig->good[i], mid)) {
                    ok = 1;
                }
            }
            else {
                if (Bitset_testPos(&ig->bad[i], mid - n)) {
                    ok = 1;
                }
            }
            if (ok) {
                Bitset_or(&ig->good[i], &ig->good[i], &ig->good[mid]);
                Bitset_or(&ig->bad[i], &ig->bad[i], &ig->bad[mid]);
            }
        }
    }

    for (int i = 0; i < 2 * n; ++i) {
        if (i < n) {
            if (Bitset_testPos(&ig->bad[i], i)) {
                ig->bv[i] = 1;
            }
        }
        else {
            if (Bitset_testPos(&ig->good[i], i - n)) {
                ig->bv[i] = 1;
            }
        }
    }

    for (int i = 0; i < 2 * n; ++i) {
        for (int j = 0; j < 2 * n; ++j) {
            if (!ig->bv[j]) {
                continue;
            }
            if (j < n) {
                if (Bitset_testPos(&ig->good[i], j)) {
                    ig->bv[i] = 1;
                }
            }
            else {
                if (Bitset_testPos(&ig->bad[i], j - n)) {
                    ig->bv[i] = 1;
                }
            }
        }
    }
}

int IG_hasSolution(const IG* ig) {
    for (int i = 0; i < n; ++i) {
        if (Bitset_testPos(&ig->bad[i], i) && Bitset_testPos(&ig->good[i + n], i)) {
            return 0;
        }
    }
    return 1;
}

void IG_select(IG* ig, int v, int* num, int* sof, int* k) {
    int t = v;
    if (num[v] == 0) {
        t += n;
    }
    if (ig->bv[t]) {
        return;
    }
    sof[(*k)++] = v;
    int ok = 1;
    for (int i = 0; i < n; ++i) {
        if (Bitset_testPos(&ig->good[t], i)) {
            if (num[i] == 0) {
                ok = 0;
                break;
            }
            if (num[i] == -1) {
                num[i] = 1;
                sof[(*k)++] = i;
            }
        }
        if (Bitset_testPos(&ig->bad[t], i)) {
            if (num[i] == 1) {
                ok = 0;
                break;
            }
            if (num[i] == -1) {
                num[i] = 0;
                sof[(*k)++] = i;
            }
        }
    }

    if (!ok) {
        for (int i = 0; i < *k; ++i) {
            num[sof[i]] = -1;
        }
        return;
    }
}

void IG_printSolutionAndDie(const IG* ig, int f1, int f2, int* num) {
    memset(num, -1, N * sizeof(int));
    if (f1 != -1) {
        if (f1 < n) {
            num[f1] = 1;
        }
        else {
            f1 -= n;
            num[f1] = 0;
        }
        IG_select(ig, f1, num, NULL, NULL);
    }
    if (f2 != -1) {
        if (num[f2 < n ? f2 : f2 - n] == -1) {
            if (f2 < n) {
                num[f2] = 1;
            }
            else {
                f2 -= n;
                num[f2] = 0;
            }
            IG_select(ig, f2, num, NULL, NULL);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (num[i] != -1) {
            continue;
        }
        num[i] = 0;
        IG_select(ig, i, num, NULL, NULL);
        if (!ig->bv[i]) {
            num[i] = 1;
            IG_select(ig, i, num, NULL, NULL);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (i) {
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
    return Bitset_testPos(&t, 0);
}

void solve(int cl1[][2], int cl2[][2], IG* g1, IG* g2, int m1, int m2) {
    memset(used, 0, sizeof(used));
    for (int i = 0; i < m1; ++i) {
        int v1 = IG_getNum(cl1[i][0]);
        int v2 = IG_getNum(cl1[i][1]);
        v1 = IG_neg(v1);
        v2 = IG_neg(v2);
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
        IG_printSolutionAndDie(g2, v1, v2, NULL);
    }
}

int main() {
    IG g1, g2;
    IG_init(&g1);
    IG_init(&g2);

    scanf("%d %d %d", &n, &m1, &m2);
    for (int i = 0; i < m1; ++i) {
        scanf("%d %d", &a, &b);
        cl1[i][0] = a;
        cl1[i][1] = b;
        IG_add(&g1, a, b);
    }
    for (int i = 0; i < m2; ++i) {
        scanf("%d %d", &a, &b);
        cl2[i][0] = a;
        cl2[i][1] = b;
        IG_add(&g2, a, b);
    }
    IG_transitiveClosure(&g1);
    IG_transitiveClosure(&g2);

    int r1 = IG_hasSolution(&g1);
    int r2 = IG_hasSolution(&g2);
    if (!r1 && !r2) {
        printf("SIMILAR\n");
        return 0;
    }
    if (!r1) {
        IG_printSolutionAndDie(&g2, -1, -1, NULL);
    }
    if (!r2) {
        IG_printSolutionAndDie(&g1, -1, -1, NULL);
    }
    solve(cl1, cl2, &g1, &g2, m1, m2);
    solve(cl2, cl1, &g2, &g1, m2, m1);
    printf("SIMILAR\n");

    return 0;
}
