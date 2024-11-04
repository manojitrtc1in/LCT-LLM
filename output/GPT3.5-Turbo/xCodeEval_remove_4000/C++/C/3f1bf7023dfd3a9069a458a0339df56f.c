#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define N 1004

typedef struct {
    bool data[N];
} Bitset;

void Bitset_set(Bitset* bitset) {
    memset(bitset->data, true, N * sizeof(bool));
}

void Bitset_setPos(Bitset* bitset, int pos) {
    bitset->data[pos / 32] |= (1u << (pos % 32));
}

void Bitset_reset(Bitset* bitset) {
    memset(bitset->data, false, N * sizeof(bool));
}

void Bitset_resetPos(Bitset* bitset, int pos) {
    bitset->data[pos / 32] &= ~(1u << (pos % 32));
}

void Bitset_flipPos(Bitset* bitset, int pos) {
    bitset->data[pos / 32] ^= (1u << (pos % 32));
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
        for (; i >= 4; i -= 4) {
            bitset->data[i] = (bitset->data[i] << shift) | (bitset->data[i - 1] >> (32 - shift));
        }
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
        for (; i + 4 < N - 1; i += 4) {
            bitset->data[i] = (bitset->data[i] >> shift) | (bitset->data[i + 1] << (32 - shift));
        }
        for (; i < N - 1; ++i) {
            bitset->data[i] = (bitset->data[i] >> shift) | (bitset->data[i + 1] << (32 - shift));
        }
        bitset->data[N - 1] >>= shift;
    }
}

int Bitset_count(const Bitset* bitset) {
    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 32; j++) {
            if (bitset->data[i] & (1u << j)) {
                count++;
            }
        }
    }
    return count;
}

bool Bitset_none(const Bitset* bitset) {
    for (int i = 0; i < N; i++) {
        if (bitset->data[i] != 0) {
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
        if (bitset->data[i] != 0) {
            for (int j = 0; j < 32; j++) {
                if (bitset->data[i] & (1u << j)) {
                    return i * 32 + j;
                }
            }
        }
    }
    return -1;
}

int Bitset_clz(const Bitset* bitset) {
    for (int i = N - 1; i >= 0; i--) {
        if (bitset->data[i] != 0) {
            for (int j = 31; j >= 0; j--) {
                if (bitset->data[i] & (1u << j)) {
                    return (N - 1 - i) * 32 + (31 - j);
                }
            }
        }
    }
    return -1;
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

int a, b, c, d, n, m, k, m1, m2;

typedef struct {
    Bitset good[2004];
    Bitset bad[2004];
    bool bv[2004];
} IG;

void IG_init(IG* ig) {
    for (int i = 0; i < 2004; i++) {
        Bitset_reset(&ig->good[i]);
        Bitset_reset(&ig->bad[i]);
    }
    memset(ig->bv, false, sizeof(ig->bv));
}

int IG_getNum(int a) {
    if (a > 0) {
        return a - 1;
    } else {
        a = -a;
        return n + a - 1;
    }
}

int IG_neg(int a) {
    if (a < n) {
        return a + n;
    } else {
        return a - n;
    }
}

void IG_addImplication(IG* ig, int a, int b) {
    a = IG_getNum(a);
    b = IG_getNum(b);
    if (b < n) {
        Bitset_setPos(&ig->good[a], b);
    } else {
        Bitset_setPos(&ig->bad[a], b - n);
    }
}

void IG_add(IG* ig, int a, int b) {
    IG_addImplication(ig, -a, b);
    IG_addImplication(ig, -b, a);
}

void IG_transitiveClosure(IG* ig) {
    for (int i = 0; i < 2 * n; i++) {
        if (i < n) {
            Bitset_setPos(&ig->good[i], i);
        } else {
            Bitset_setPos(&ig->bad[i], i - n);
        }
    }
    for (int mid = 0; mid < 2 * n; mid++) {
        for (int i = 0; i < 2 * n; i++) {
            bool ok = false;
            if (mid < n) {
                if (Bitset_testPos(&ig->good[i], mid)) {
                    ok = true;
                }
            } else {
                if (Bitset_testPos(&ig->bad[i], mid - n)) {
                    ok = true;
                }
            }
            if (ok) {
                Bitset_or(&ig->good[i], &ig->good[i], &ig->good[mid]);
                Bitset_or(&ig->bad[i], &ig->bad[i], &ig->bad[mid]);
            }
        }
    }

    for (int i = 0; i < 2 * n; i++) {
        if (i < n) {
            if (Bitset_testPos(&ig->bad[i], i)) {
                ig->bv[i] = true;
            }
        } else {
            if (Bitset_testPos(&ig->good[i], i - n)) {
                ig->bv[i] = true;
            }
        }
    }

    for (int i = 0; i < 2 * n; i++) {
        for (int j = 0; j < 2 * n; j++) {
            if (!ig->bv[j]) {
                continue;
            }
            if (j < n) {
                if (Bitset_testPos(&ig->good[i], j)) {
                    ig->bv[i] = true;
                }
            } else {
                if (Bitset_testPos(&ig->bad[i], j - n)) {
                    ig->bv[i] = true;
                }
            }
        }
    }
}

bool IG_hasSolution(const IG* ig) {
    for (int i = 0; i < n; i++) {
        if (Bitset_testPos(&ig->bad[i], i) && Bitset_testPos(&ig->good[i + n], i)) {
            return false;
        }
    }
    return true;
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
    bool ok = true;
    for (int i = 0; i < n; i++) {
        if (Bitset_testPos(&ig->good[t], i)) {
            if (num[i] == 0) {
                ok = false;
                break;
            }
            if (num[i] == -1) {
                num[i] = 1;
                sof[(*k)++] = i;
            }
        }
        if (Bitset_testPos(&ig->bad[t], i)) {
            if (num[i] == 1) {
                ok = false;
                break;
            }
            if (num[i] == -1) {
                num[i] = 0;
                sof[(*k)++] = i;
            }
        }
    }

    if (!ok) {
        for (int i = 0; i < *k; i++) {
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
        } else {
            f1 -= n;
            num[f1] = 0;
        }
        IG_select(ig, f1, num, NULL, NULL);
    }
    if (f2 != -1) {
        if (num[f2 < n ? f2 : f2 - n] == -1) {
            if (f2 < n) {
                num[f2] = 1;
            } else {
                f2 -= n;
                num[f2] = 0;
            }
            IG_select(ig, f2, num, NULL, NULL);
        }
    }
    for (int i = 0; i < n; i++) {
        if (num[i] != -1) {
            continue;
        }
        num[i] = 0;
        IG_select(ig, i, num, NULL, NULL);
        if (num[i] == -1) {
            num[i] = 1;
            IG_select(ig, i, num, NULL, NULL);
        }
    }
    for (int i = 0; i < n; i++) {
        if (i) {
            printf(" ");
        }
        printf("%d", num[i]);
    }
    printf("\n");
    exit(0);
}

bool IG_checkBad(const IG* ig, int v1, int v2) {
    Bitset t;
    Bitset_or(&t, &ig->good[v1], &ig->good[v2]);
    Bitset_and(&t, &t, &ig->bad[v1]);
    Bitset_and(&t, &t, &ig->bad[v2]);
    return !Bitset_none(&t);
}

char buf[65537];
char *ch = buf;
inline char get_char() {
    if (*ch == 0) {
        ch = buf;
        fread(buf, sizeof(char), 65536, stdin);
    }
    return *(ch++);
}

char _ch;
inline void next_int(int *ans) {
    *ans = 0;
    while (((_ch = get_char()) < '0' || _ch > '9') && _ch != '-');
    bool neg = false;
    if (_ch == '-') {
        neg = true;
        _ch = get_char();
    }
    do {
        *ans = *ans * 10 + _ch - '0';
    } while ((_ch = get_char()) >= '0' && _ch <= '9');
    if (neg) {
        *ans = -*ans;
    }
}

int main() {
    next_int(&n);
    next_int(&m1);
    next_int(&m2);

    IG g1, g2;
    IG_init(&g1);
    IG_init(&g2);

    for (int i = 0; i < m1; i++) {
        next_int(&a);
        next_int(&b);
        IG_add(&g1, a, b);
    }

    for (int i = 0; i < m2; i++) {
        next_int(&a);
        next_int(&b);
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
        IG_printSolutionAndDie(&g2, -1, -1, NULL);
    }

    if (!r2) {
        IG_printSolutionAndDie(&g1, -1, -1, NULL);
    }

    int num[N];
    int sof[N];
    int k;

    memset(used, false, sizeof(used));
    for (int i = 0; i < m1; i++) {
        int v1 = IG_getNum(cl1[i].x);
        int v2 = IG_getNum(cl1[i].y);
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
        used[v1][v2] = true;

        if (g2.bv[v1] || g2.bv[v2]) {
            continue;
        }
        if (IG_checkBad(&g2, v1, v2)) {
            continue;
        }
        IG_printSolutionAndDie(&g2, v1, v2, num);
    }

    memset(used, false, sizeof(used));
    for (int i = 0; i < m2; i++) {
        int v1 = IG_getNum(cl2[i].x);
        int v2 = IG_getNum(cl2[i].y);
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
        used[v1][v2] = true;

        if (g1.bv[v1] || g1.bv[v2]) {
            continue;
        }
        if (IG_checkBad(&g1, v1, v2)) {
            continue;
        }
        IG_printSolutionAndDie(&g1, v1, v2, num);
    }

    printf("SIMILAR\n");

    return 0;
}
