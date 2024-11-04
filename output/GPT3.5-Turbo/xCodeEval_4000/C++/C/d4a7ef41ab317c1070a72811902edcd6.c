#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 1004
#define MAX_M 2004

typedef struct {
    unsigned int data[MAX_N];
} Bitset;

typedef struct {
    Bitset good[MAX_M];
    Bitset bad[MAX_M];
    int bv[MAX_M];
} IG;

int n, m1, m2;
int a, b;
int cl1[MAX_M][2];
int cl2[MAX_M][2];
int used[MAX_M][MAX_M];

void Bitset_set(Bitset* bs, int pos) {
    bs->data[pos >> 5] |= 1u << (pos & 31);
}

void Bitset_reset(Bitset* bs, int pos) {
    bs->data[pos >> 5] &= ~(1u << (pos & 31));
}

int Bitset_test(const Bitset* bs, int pos) {
    return (bs->data[pos >> 5] >> (pos & 31)) & 1;
}

void Bitset_or(Bitset* res, const Bitset* bs1, const Bitset* bs2) {
    int i;
    for (i = 0; i < MAX_N; i++) {
        res->data[i] = bs1->data[i] | bs2->data[i];
    }
}

void Bitset_and(Bitset* res, const Bitset* bs1, const Bitset* bs2) {
    int i;
    for (i = 0; i < MAX_N; i++) {
        res->data[i] = bs1->data[i] & bs2->data[i];
    }
}

void Bitset_xor(Bitset* res, const Bitset* bs1, const Bitset* bs2) {
    int i;
    for (i = 0; i < MAX_N; i++) {
        res->data[i] = bs1->data[i] ^ bs2->data[i];
    }
}

void Bitset_copy(Bitset* dest, const Bitset* src) {
    memcpy(dest->data, src->data, sizeof(unsigned int) * MAX_N);
}

void Bitset_reset_all(Bitset* bs) {
    memset(bs->data, 0, sizeof(unsigned int) * MAX_N);
}

void Bitset_set_all(Bitset* bs) {
    memset(bs->data, 255, sizeof(unsigned int) * MAX_N);
}

void Bitset_shift_left(Bitset* bs, int shift) {
    int full = shift >> 5;
    if (full >= MAX_N) {
        Bitset_reset_all(bs);
        return;
    }
    if (full) {
        memmove(bs->data + full, bs->data, (MAX_N - full) * sizeof(unsigned int));
        memset(bs->data, 0, full * sizeof(unsigned int));
    }

    shift &= 31;
    if (shift) {
        int i;
        for (i = MAX_N - 1; i >= 1; --i) {
            bs->data[i] = (bs->data[i] << shift) | (bs->data[i - 1] >> (32 - shift));
        }
        bs->data[0] <<= shift;
    }
}

void Bitset_shift_right(Bitset* bs, int shift) {
    int full = shift >> 5;
    if (full >= MAX_N) {
        Bitset_reset_all(bs);
        return;
    }
    if (full) {
        memmove(bs->data, bs->data + full, (MAX_N - full) * sizeof(unsigned int));
        memset(bs->data + MAX_N - full, 0, full * sizeof(unsigned int));
    }

    shift &= 31;
    if (shift) {
        int i;
        unsigned int u = (1u << shift) - 1;
        for (i = MAX_N - 1; i >= 1; --i) {
            bs->data[i] = (bs->data[i] >> shift) | ((bs->data[i - 1] & u) << (32 - shift));
        }
        bs->data[0] >>= shift;
    }
}

void Bitset_or_eq(Bitset* bs, const Bitset* other) {
    int i;
    for (i = 0; i < MAX_N; i++) {
        bs->data[i] |= other->data[i];
    }
}

void Bitset_and_eq(Bitset* bs, const Bitset* other) {
    int i;
    for (i = 0; i < MAX_N; i++) {
        bs->data[i] &= other->data[i];
    }
}

void Bitset_xor_eq(Bitset* bs, const Bitset* other) {
    int i;
    for (i = 0; i < MAX_N; i++) {
        bs->data[i] ^= other->data[i];
    }
}

int Bitset_count(const Bitset* bs) {
    int count = 0;
    int i;
    for (i = 0; i < MAX_N; i++) {
        unsigned int val = bs->data[i];
        while (val) {
            count++;
            val &= val - 1;
        }
    }
    return count;
}

int Bitset_count_range(const Bitset* bs, int l, int r) {
    if ((l >> 5) == (r >> 5)) {
        return Bitset_count(bs) - Bitset_count(bs, r, l);
    }

    int count = 0;
    int i;
    if (l & 31) {
        count += Bitset_count(bs, l, (l & ~31) + 31);
        l = (l & ~31) + 32;
    }
    l >>= 5;
    if (r & 31) {
        count += Bitset_count(bs, (r & ~31), r);
        r = (r & ~31);
    }
    r >>= 5;
    for (i = l; i < r; i++) {
        count += Bitset_count(bs, i * 32, (i + 1) * 32);
    }
    return count;
}

int Bitset_none(const Bitset* bs) {
    int i;
    for (i = 0; i < MAX_N; i++) {
        if (bs->data[i] != 0) {
            return 0;
        }
    }
    return 1;
}

int Bitset_any(const Bitset* bs) {
    int i;
    for (i = 0; i < MAX_N; i++) {
        if (bs->data[i] != 0) {
            return 1;
        }
    }
    return 0;
}

int Bitset_ctz(const Bitset* bs) {
    int i;
    for (i = 0; i < MAX_N; i++) {
        unsigned int val = bs->data[i];
        if (val != 0) {
            int count = 0;
            while ((val & 1) == 0) {
                count++;
                val >>= 1;
            }
            return count + (i << 5);
        }
    }
    return MAX_N << 5;
}

int Bitset_clz(const Bitset* bs) {
    int i;
    for (i = MAX_N - 1; i >= 0; i--) {
        unsigned int val = bs->data[i];
        if (val != 0) {
            int count = 0;
            while (val != 0) {
                count++;
                val >>= 1;
            }
            return count - 32 + ((MAX_N - 1 - i) << 5);
        }
    }
    return 0;
}

void Bitset_print(const Bitset* bs) {
    int i;
    for (i = 0; i < MAX_N; i++) {
        printf("%u ", bs->data[i]);
    }
    printf("\n");
}

void IG_add_implication(IG* ig, int a, int b) {
    a = a > 0 ? a - 1 : n + a - 1;
    b = b > 0 ? b - 1 : n + b - 1;
    if (b < n) {
        Bitset_set(&ig->good[a], b);
    }
    else {
        Bitset_set(&ig->bad[a], b - n);
    }
}

void IG_add(IG* ig, int a, int b) {
    IG_add_implication(ig, -a, b);
    IG_add_implication(ig, -b, a);
}

void IG_transitive_closure(IG* ig) {
    int i, j, k;
    for (i = 0; i < 2 * n; i++) {
        if (i < n) {
            Bitset_set(&ig->good[i], i);
        }
        else {
            Bitset_set(&ig->bad[i], i - n);
        }
    }

    for (k = 0; k < 2 * n; k++) {
        for (i = 0; i < 2 * n; i++) {
            int ok = 0;
            if (k < n) {
                if (Bitset_test(&ig->good[i], k)) {
                    ok = 1;
                }
            }
            else {
                if (Bitset_test(&ig->bad[i], k - n)) {
                    ok = 1;
                }
            }
            if (ok) {
                Bitset_or(&ig->good[i], &ig->good[i], &ig->good[k]);
                Bitset_or(&ig->bad[i], &ig->bad[i], &ig->bad[k]);
            }
        }
    }

    for (i = 0; i < 2 * n; i++) {
        if (i < n) {
            if (Bitset_test(&ig->bad[i], i) && Bitset_test(&ig->good[i + n], i)) {
                ig->bv[i] = 1;
            }
        }
        else {
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
                }
                else {
                    if (Bitset_test(&ig->bad[i], j - n)) {
                        ig->bv[i] = 1;
                    }
                }
            }
        }
    }
}

int IG_has_solution(const IG* ig) {
    int i;
    for (i = 0; i < n; i++) {
        if (Bitset_test(&ig->bad[i], i) && Bitset_test(&ig->good[i + n], i)) {
            return 0;
        }
    }
    return 1;
}

void IG_select(IG* ig, int v, int* num, int* sof) {
    int t = v;
    if (num[v] == 0) {
        t += n;
    }
    if (ig->bv[t]) {
        return;
    }
    int k = 0;
    sof[k++] = v;
    int ok = 1;
    int i;
    for (i = 0; i < n; i++) {
        if (Bitset_test(&ig->good[t], i)) {
            if (num[i] == 0) {
                ok = 0;
                break;
            }
            if (num[i] == -1) {
                num[i] = 1;
                sof[k++] = i;
            }
        }
        if (Bitset_test(&ig->bad[t], i)) {
            if (num[i] == 1) {
                ok = 0;
                break;
            }
            if (num[i] == -1) {
                num[i] = 0;
                sof[k++] = i;
            }
        }
    }

    if (!ok) {
        for (i = 0; i < k; i++) {
            num[sof[i]] = -1;
        }
        return;
    }
}

void IG_print_solution_and_die(const IG* ig, int f1, int f2, int* num) {
    memset(num, -1, sizeof(int) * MAX_N);
    if (f1 != -1) {
        if (f1 < n) {
            num[f1] = 1;
        }
        else {
            f1 -= n;
            num[f1] = 0;
        }
        IG_select(ig, f1, num, NULL);
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
            IG_select(ig, f2, num, NULL);
        }
    }
    int i;
    for (i = 0; i < n; i++) {
        if (num[i] == -1) {
            num[i] = 0;
            IG_select(ig, i, num, NULL);
            if (!ig->bv[i]) {
                num[i] = 1;
                IG_select(ig, i, num, NULL);
            }
        }
    }
    for (i = 0; i < n; i++) {
        if (i) {
            printf(" ");
        }
        printf("%d", num[i]);
    }
    printf("\n");
    exit(0);
}

int IG_check_bad(const IG* ig, int v1, int v2) {
    Bitset t;
    Bitset_or(&t, &ig->good[v1], &ig->good[v2]);
    Bitset_and(&t, &t, &ig->bad[v1]);
    Bitset_and(&t, &t, &ig->bad[v2]);
    return !Bitset_none(&t);
}

void solve(pii* cl1, pii* cl2, IG* g1, IG* g2, int m1, int m2) {
    memset(used, 0, sizeof(int) * MAX_M * MAX_M);
    int i, j, k;
    for (i = 0; i < m1; i++) {
        int v1 = cl1[i][0] > 0 ? cl1[i][0] - 1 : n + cl1[i][0] - 1;
        int v2 = cl1[i][1] > 0 ? cl1[i][1] - 1 : n + cl1[i][1] - 1;
        v1 = -v1 - 1;
        v2 = -v2 - 1;
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
        if (IG_check_bad(g2, v1, v2)) {
            continue;
        }
        IG_print_solution_and_die(g2, v1, v2, NULL);
    }
}

int main() {
    scanf("%d %d %d", &n, &m1, &m2);
    int i;
    for (i = 0; i < m1; i++) {
        scanf("%d %d", &a, &b);
        cl1[i][0] = a;
        cl1[i][1] = b;
        IG_add(&g1, a, b);
    }
    for (i = 0; i < m2; i++) {
        scanf("%d %d", &a, &b);
        cl2[i][0] = a;
        cl2[i][1] = b;
        IG_add(&g2, a, b);
    }
    IG_transitive_closure(&g1);
    IG_transitive_closure(&g2);

    int r1 = IG_has_solution(&g1);
    int r2 = IG_has_solution(&g2);
    if (!r1 && !r2) {
        printf("SIMILAR\n");
        return 0;
    }
    if (!r1) {
        IG_print_solution_and_die(&g2, -1, -1, NULL);
    }
    if (!r2) {
        IG_print_solution_and_die(&g1, -1, -1, NULL);
    }
    solve(cl1, cl2, &g1, &g2, m1, m2);
    solve(cl2, cl1, &g2, &g1, m2, m1);
    printf("SIMILAR\n");
    return 0;
}
