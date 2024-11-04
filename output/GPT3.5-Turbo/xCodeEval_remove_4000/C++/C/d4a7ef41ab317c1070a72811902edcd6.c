#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define N 1004

typedef struct {
    bool data[N];
} Bitset;

typedef struct {
    Bitset good[2004];
    Bitset bad[2004];
    bool bv[2004];
} IG;

typedef struct {
    int x;
    int y;
} pii;

void Bitset_set(Bitset* bitset) {
    memset(bitset->data, true, N * sizeof(bool));
}

void Bitset_setPos(Bitset* bitset, int pos) {
    bitset->data[pos / 32] |= 1u << (pos % 32);
}

void Bitset_reset(Bitset* bitset) {
    memset(bitset->data, false, N * sizeof(bool));
}

void Bitset_resetPos(Bitset* bitset, int pos) {
    bitset->data[pos / 32] &= ~(1u << (pos % 32));
}

void Bitset_flipPos(Bitset* bitset, int pos) {
    bitset->data[pos / 32] ^= 1u << (pos % 32);
}

bool Bitset_testPos(const Bitset* bitset, int pos) {
    return (bitset->data[pos / 32] >> (pos % 32)) & 1;
}

void Bitset_or(Bitset* res, const Bitset* bitset1, const Bitset* bitset2) {
    for (int i = 0; i < N; i++) {
        res->data[i] = bitset1->data[i] | bitset2->data[i];
    }
}

void Bitset_and(Bitset* res, const Bitset* bitset1, const Bitset* bitset2) {
    for (int i = 0; i < N; i++) {
        res->data[i] = bitset1->data[i] & bitset2->data[i];
    }
}

void Bitset_xor(Bitset* res, const Bitset* bitset1, const Bitset* bitset2) {
    for (int i = 0; i < N; i++) {
        res->data[i] = bitset1->data[i] ^ bitset2->data[i];
    }
}

void Bitset_leftShift(Bitset* bitset, int shift) {
    const int full = shift / 32;
    if (full >= N) {
        Bitset_reset(bitset);
        return;
    }
    if (full) {
        memmove(bitset->data + full, bitset->data, (N - full) * sizeof(bool));
        memset(bitset->data, false, full * sizeof(bool));
    }

    shift &= 31;
    if (shift) {
        int i = N - 1;
        for (; i >= 1; --i) {
            bitset->data[i] = (bitset->data[i] << shift) | (bitset->data[i - 1] >> (32 - shift));
        }
        bitset->data[0] <<= shift;
    }
}

void Bitset_rightShift(Bitset* bitset, int shift) {
    const int full = shift / 32;
    if (full >= N) {
        Bitset_reset(bitset);
        return;
    }
    if (full) {
        memmove(bitset->data, bitset->data + full, (N - full) * sizeof(bool));
        memset(bitset->data + N - full, false, full * sizeof(bool));
    }

    shift &= 31;
    if (shift) {
        int i = 0;
        for (; i < N - 1; ++i) {
            bitset->data[i] = (bitset->data[i] >> shift) | (bitset->data[i + 1] << (32 - shift));
        }
        bitset->data[N - 1] >>= shift;
    }
}

int Bitset_count(const Bitset* bitset) {
    int count = 0;
    for (int i = 0; i < N; i++) {
        if (bitset->data[i]) {
            count += __builtin_popcount(bitset->data[i]);
        }
    }
    return count;
}

bool Bitset_none(const Bitset* bitset) {
    for (int i = 0; i < N; i++) {
        if (bitset->data[i]) {
            return false;
        }
    }
    return true;
}

bool Bitset_any(const Bitset* bitset) {
    return !Bitset_none(bitset);
}

int Bitset_ctz(const Bitset* bitset) {
    for (int i = 0; i < N; i++) {
        if (bitset->data[i]) {
            return __builtin_ctz(bitset->data[i]) + i * 32;
        }
    }
    return N * 32;
}

int Bitset_clz(const Bitset* bitset) {
    for (int i = N - 1; i >= 0; i--) {
        if (bitset->data[i]) {
            return __builtin_clz(bitset->data[i]) + (N - 1 - i) * 32;
        }
    }
    return N * 32;
}

bool Bitset_equals(const Bitset* bitset1, const Bitset* bitset2) {
    for (int i = 0; i < N; i++) {
        if (bitset1->data[i] != bitset2->data[i]) {
            return false;
        }
    }
    return true;
}

bool Bitset_lessThan(const Bitset* bitset1, const Bitset* bitset2) {
    for (int i = N - 1; i >= 0; i--) {
        if (bitset1->data[i] != bitset2->data[i]) {
            return bitset1->data[i] < bitset2->data[i];
        }
    }
    return false;
}

bool Bitset_greaterThan(const Bitset* bitset1, const Bitset* bitset2) {
    for (int i = N - 1; i >= 0; i--) {
        if (bitset1->data[i] != bitset2->data[i]) {
            return bitset1->data[i] > bitset2->data[i];
        }
    }
    return false;
}

bool Bitset_lessThanOrEqual(const Bitset* bitset1, const Bitset* bitset2) {
    return !Bitset_greaterThan(bitset1, bitset2);
}

bool Bitset_greaterThanOrEqual(const Bitset* bitset1, const Bitset* bitset2) {
    return !Bitset_lessThan(bitset1, bitset2);
}

bool Bitset_notEquals(const Bitset* bitset1, const Bitset* bitset2) {
    return !Bitset_equals(bitset1, bitset2);
}

void IG_addImplication(IG* ig, int a, int b) {
    a--;
    b--;
    if (b < N) {
        Bitset_setPos(&ig->good[a], b);
    }
    else {
        Bitset_setPos(&ig->bad[a], b - N);
    }
}

void IG_add(IG* ig, int a, int b) {
    IG_addImplication(ig, -a, b);
    IG_addImplication(ig, -b, a);
}

void IG_transitiveClosure(IG* ig) {
    for (int i = 0; i < 2 * N; i++) {
        if (i < N) {
            Bitset_setPos(&ig->good[i], i);
        }
        else {
            Bitset_setPos(&ig->bad[i], i - N);
        }
    }

    for (int mid = 0; mid < 2 * N; mid++) {
        for (int i = 0; i < 2 * N; i++) {
            bool ok = false;
            if (mid < N) {
                if (Bitset_testPos(&ig->good[i], mid)) {
                    ok = true;
                }
            }
            else {
                if (Bitset_testPos(&ig->bad[i], mid - N)) {
                    ok = true;
                }
            }
            if (ok) {
                Bitset_or(&ig->good[i], &ig->good[i], &ig->good[mid]);
                Bitset_or(&ig->bad[i], &ig->bad[i], &ig->bad[mid]);
            }
        }
    }

    for (int i = 0; i < 2 * N; i++) {
        if (i < N) {
            if (Bitset_testPos(&ig->bad[i], i) && Bitset_testPos(&ig->good[i + N], i)) {
                ig->bv[i] = true;
            }
        }
        else {
            if (Bitset_testPos(&ig->good[i], i - N)) {
                ig->bv[i] = true;
            }
        }
    }

    for (int i = 0; i < 2 * N; i++) {
        for (int j = 0; j < 2 * N; j++) {
            if (!ig->bv[j]) {
                if (j < N) {
                    if (Bitset_testPos(&ig->good[i], j)) {
                        ig->bv[i] = true;
                    }
                }
                else {
                    if (Bitset_testPos(&ig->bad[i], j - N)) {
                        ig->bv[i] = true;
                    }
                }
            }
        }
    }
}

bool IG_hasSolution(const IG* ig) {
    for (int i = 0; i < N; i++) {
        if (Bitset_testPos(&ig->bad[i], i) && Bitset_testPos(&ig->good[i + N], i)) {
            return false;
        }
    }
    return true;
}

void IG_select(IG* ig, int v, int* num, int* sof) {
    int t = v;
    if (num[v] == 0) {
        t += N;
    }
    if (ig->bv[t]) {
        return;
    }
    int k = 0;
    sof[k++] = v;
    bool ok = true;
    for (int i = 0; i < N; i++) {
        if (Bitset_testPos(&ig->good[t], i)) {
            if (num[i] == 0) {
                ok = false;
                break;
            }
            if (num[i] == -1) {
                num[i] = 1;
                sof[k++] = i;
            }
        }
        if (Bitset_testPos(&ig->bad[t], i)) {
            if (num[i] == 1) {
                ok = false;
                break;
            }
            if (num[i] == -1) {
                num[i] = 0;
                sof[k++] = i;
            }
        }
    }

    if (!ok) {
        for (int i = 0; i < k; i++) {
            num[sof[i]] = -1;
        }
        return;
    }
}

void IG_printSolutionAndDie(const IG* ig, int f1, int f2) {
    int num[N];
    int sof[N];
    memset(num, -1, N * sizeof(int));
    if (f1 != -1) {
        if (f1 < N) {
            num[f1] = 1;
        }
        else {
            f1 -= N;
            num[f1] = 0;
        }
        IG_select(ig, f1, num, sof);
    }
    if (f2 != -1) {
        if (num[f2 < N ? f2 : f2 - N] == -1) {
            if (f2 < N) {
                num[f2] = 1;
            }
            else {
                f2 -= N;
                num[f2] = 0;
            }
            IG_select(ig, f2, num, sof);
        }
    }
    for (int i = 0; i < N; i++) {
        if (num[i] != -1) {
            continue;
        }
        num[i] = 0;
        if (!IG_select(ig, i, num, sof)) {
            num[i] = 1;
            IG_select(ig, i, num, sof);
        }
    }
    for (int i = 0; i < N; i++) {
        if (i) {
            printf(" ");
        }
        printf("%d", num[i]);
    }
    printf("\n");
    exit(0);
}

void solve(pii* cl1, pii* cl2, IG* g1, IG* g2, int m1, int m2) {
    bool used[2002][2002];
    memset(used, false, sizeof(used));
    for (int i = 0; i < m1; i++) {
        int v1 = cl1[i].x;
        int v2 = cl1[i].y;
        v1--;
        v2--;
        v1 = -v1;
        v2 = -v2;
        if (v1 > v2) {
            int temp = v1;
            v1 = v2;
            v2 = temp;
        }
        if (used[v1][v2]) {
            continue;
        }
        used[v1][v2] = true;

        if (g2->bv[v1] || g2->bv[v2]) {
            continue;
        }
        if (g2->good[v1].data[v2] || g2->bad[v1].data[v2 - N]) {
            continue;
        }
        IG_printSolutionAndDie(g2, v1, v2);
    }
}

int main() {
    int n, m1, m2;
    scanf("%d %d %d", &n, &m1, &m2);

    IG g1;
    for (int i = 0; i < m1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        pii cl1 = {a, b};
        IG_add(&g1, a, b);
    }

    IG g2;
    for (int i = 0; i < m2; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        pii cl2 = {a, b};
        IG_add(&g2, a, b);
    }

    IG_transitiveClosure(&g1);
    IG_transitiveClosure(&g2);

    bool r1 = IG_hasSolution(&g1);
    bool r2 = IG_hasSolution(&g2);
    if (!r1 && !r2) {
        printf("SIMILAR\n");
        return 0;
    }
    if (!r1) {
        IG_printSolutionAndDie(&g2, -1, -1);
    }
    if (!r2) {
        IG_printSolutionAndDie(&g1, -1, -1);
    }
    solve(cl1, cl2, &g1, &g2, m1, m2);
    solve(cl2, cl1, &g2, &g1, m2, m1);
    printf("SIMILAR\n");

    return 0;
}
