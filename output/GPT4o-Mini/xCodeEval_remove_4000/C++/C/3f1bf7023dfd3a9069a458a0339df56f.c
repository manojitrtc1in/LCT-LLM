#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <immintrin.h>

#define MAX_N 1004
#define MAX_M 2004

typedef struct {
    unsigned data[(MAX_N + 31) / 32];
} Bitset;

void Bitset_init(Bitset *b) {
    memset(b->data, 0, sizeof(b->data));
}

void Bitset_set(Bitset *b) {
    memset(b->data, 255, sizeof(b->data));
}

void Bitset_set_pos(Bitset *b, int pos) {
    b->data[pos >> 5] |= 1u << (pos & 31);
}

void Bitset_reset(Bitset *b) {
    memset(b->data, 0, sizeof(b->data));
}

void Bitset_reset_pos(Bitset *b, int pos) {
    b->data[pos >> 5] &= ~(1u << (pos & 31));
}

void Bitset_flip_pos(Bitset *b, int pos) {
    b->data[pos >> 5] ^= 1u << (pos & 31);
}

int Bitset_test(const Bitset *b, int pos) {
    return (b->data[pos >> 5] >> (pos & 31)) & 1;
}

void Bitset_or(Bitset *b, const Bitset *other) {
    for (int i = 0; i < (MAX_N + 31) / 32; i++) {
        b->data[i] |= other->data[i];
    }
}

void Bitset_and(Bitset *b, const Bitset *other) {
    for (int i = 0; i < (MAX_N + 31) / 32; i++) {
        b->data[i] &= other->data[i];
    }
}

void Bitset_xor(Bitset *b, const Bitset *other) {
    for (int i = 0; i < (MAX_N + 31) / 32; i++) {
        b->data[i] ^= other->data[i];
    }
}

void Bitset_shift_left(Bitset *b, int shift) {
    const int full = shift >> 5;
    if (full >= (MAX_N + 31) / 32) {
        Bitset_reset(b);
        return;
    }
    if (full) {
        memmove(b->data + full, b->data, ((MAX_N + 31) / 32 - full) * sizeof(unsigned));
        memset(b->data, 0, full * sizeof(unsigned));
    }

    shift &= 31;
    if (shift) {
        for (int i = (MAX_N + 31) / 32 - 1; i >= 1; --i) {
            b->data[i] = (b->data[i] << shift) | (b->data[i - 1] >> (32 - shift));
        }
        b->data[0] <<= shift;
    }
}

void Bitset_shift_right(Bitset *b, int shift) {
    const int full = shift >> 5;
    if (full >= (MAX_N + 31) / 32) {
        Bitset_reset(b);
        return;
    }
    if (full) {
        memmove(b->data, b->data + full, ((MAX_N + 31) / 32 - full) * sizeof(unsigned));
        memset(b->data + (MAX_N + 31) / 32 - full, 0, full * sizeof(unsigned));
    }

    shift &= 31;
    if (shift) {
        for (int i = 0; i < (MAX_N + 31) / 32 - 1; ++i) {
            b->data[i] = (b->data[i] >> shift) | ((b->data[i + 1] & ((1u << shift) - 1)) << (32 - shift));
        }
        b->data[(MAX_N + 31) / 32 - 1] >>= shift;
    }
}

int Bitset_count(const Bitset *b) {
    int count = 0;
    for (int i = 0; i < (MAX_N + 31) / 32; i++) {
        count += __builtin_popcount(b->data[i]);
    }
    return count;
}

int Bitset_none(const Bitset *b) {
    for (int i = 0; i < (MAX_N + 31) / 32; i++) {
        if (b->data[i]) return 0;
    }
    return 1;
}

typedef struct {
    Bitset good[MAX_M], bad[MAX_M];
    int bv[MAX_M];
} IG;

void IG_init(IG *g) {
    for (int i = 0; i < MAX_M; i++) {
        Bitset_init(&g->good[i]);
        Bitset_init(&g->bad[i]);
        g->bv[i] = 0;
    }
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

void IG_addImplication(IG *g, int a, int b, int n) {
    a = getNum(a, n);
    b = getNum(b, n);
    if (b < n) {
        Bitset_set_pos(&g->good[a], b);
    } else {
        Bitset_set_pos(&g->bad[a], b - n);
    }
}

void IG_add(IG *g, int a, int b, int n) {
    IG_addImplication(g, -a, b, n);
    IG_addImplication(g, -b, a, n);
}

void IG_transitiveClosure(IG *g, int n) {
    for (int i = 0; i < 2 * n; i++) {
        if (i < n) {
            Bitset_set_pos(&g->good[i], i);
        } else {
            Bitset_set_pos(&g->bad[i], i - n);
        }
    }
    for (int mid = 0; mid < 2 * n; mid++) {
        for (int i = 0; i < 2 * n; i++) {
            int ok = 0;
            if (mid < n) {
                if (Bitset_test(&g->good[i], mid)) {
                    ok = 1;
                }
            } else {
                if (Bitset_test(&g->bad[i], mid - n)) {
                    ok = 1;
                }
            }
            if (ok) {
                Bitset_or(&g->good[i], &g->good[mid]);
                Bitset_or(&g->bad[i], &g->bad[mid]);
            }
        }
    }

    for (int i = 0; i < 2 * n; i++) {
        if (i < n) {
            if (Bitset_test(&g->bad[i], i)) g->bv[i] = 1;
        } else {
            if (Bitset_test(&g->good[i], i - n)) g->bv[i] = 1;
        }
    }

    for (int i = 0; i < 2 * n; i++) {
        for (int j = 0; j < 2 * n; j++) {
            if (!g->bv[j]) continue;
            if (j < n) {
                if (Bitset_test(&g->good[i], j)) g->bv[i] = 1;
            } else {
                if (Bitset_test(&g->bad[i], j - n)) g->bv[i] = 1;
            }
        }
    }
}

int IG_hasSolution(IG *g, int n) {
    for (int i = 0; i < n; i++) {
        if (Bitset_test(&g->bad[i], i) && Bitset_test(&g->good[i + n], i)) {
            return 0;
        }
    }
    return 1;
}

int num[MAX_N], sof[MAX_N];

int IG_select(IG *g, int v, int n) {
    int t = v;
    if (num[v] == 0) t += n;
    if (g->bv[t]) return 0;
    int k = 0;
    sof[k++] = v;
    int ok = 1;
    for (int i = 0; i < n; i++) {
        if (Bitset_test(&g->good[t], i)) {
            if (num[i] == 0) {
                ok = 0;
                break;
            }
            if (num[i] == -1) {
                num[i] = 1;
                sof[k++] = i;
            }
        }
        if (Bitset_test(&g->bad[t], i)) {
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
        for (int i = 0; i < k; i++) {
            num[sof[i]] = -1;
        }
        return 0;
    }
    return 1;
}

void IG_printSolutionAndDie(IG *g, int f1, int f2, int n) {
    memset(num, -1, sizeof(num));
    if (f1 != -1) {
        if (f1 < n) {
            num[f1] = 1;
        } else {
            f1 -= n;
            num[f1] = 0;
        }
        IG_select(g, f1, n);
    }
    if (f2 != -1) {
        if (num[f2 < n ? f2 : f2 - n] == -1) {
            if (f2 < n) {
                num[f2] = 1;
            } else {
                f2 -= n;
                num[f2] = 0;
            }
            IG_select(g, f2, n);
        }
    }
    for (int i = 0; i < n; i++) {
        if (num[i] != -1) continue;
        num[i] = 0;
        if (!IG_select(g, i, n)) {
            num[i] = 1;
            IG_select(g, i, n);
        }
    }
    for (int i = 0; i < n; i++) {
        if (i) printf(" ");
        printf("%d", num[i]);
    }
    printf("\n");
    exit(0);
}

int IG_checkBad(IG *g, int v1, int v2) {
    Bitset temp;
    Bitset_init(&temp);
    Bitset_or(&temp, &g->good[v1]);
    Bitset_or(&temp, &g->good[v2]);
    Bitset_or(&temp, &g->bad[v1]);
    Bitset_or(&temp, &g->bad[v2]);
    return !Bitset_none(&temp);
}

char buf[65537];
char *ch = buf;

char get_char() {
    if (*ch == 0) {
        ch = buf;
        fread(buf, sizeof(char), 65536, stdin);
    }
    return *(ch++);
}

char _ch;

void next_int(int *ans) {
    *ans = 0;
    while (((_ch = get_char()) < '0' || _ch > '9') && _ch != '-');
    int neg = 0;
    if (_ch == '-') {
        neg = 1;
        _ch = get_char();
    }
    do {
        *ans = *ans * 10 + _ch - '0';
    } while ((_ch = get_char()) >= '0' && _ch <= '9');
    if (neg) *ans = -(*ans);
}

void solve(pii *cl1, pii *cl2, IG *g1, IG *g2, int m1, int m2) {
    memset(used, 0, sizeof(used));
    for (int i = 0; i < m1; i++) {
        int v1 = getNum(cl1[i].x);
        int v2 = getNum(cl1[i].y);
        v1 = neg(v1);
        v2 = neg(v2);
        if (v1 > v2) {
            int temp = v1;
            v1 = v2;
            v2 = temp;
        }
        if (used[v1][v2]) continue;
        used[v1][v2] = 1;

        if (g2->bv[v1] || g2->bv[v2]) continue;
        if (IG_checkBad(g2, v1, v2)) continue;
        IG_printSolutionAndDie(g2, v1, v2, n);
    }
}

int main() {
    int n, m1, m2;
    next_int(&n);
    next_int(&m1);
    next_int(&m2);
    IG g1, g2;
    IG_init(&g1);
    IG_init(&g2);
    pii cl1[MAX_M], cl2[MAX_M];

    for (int i = 0; i < m1; i++) {
        int a, b;
        next_int(&a);
        next_int(&b);
        cl1[i] = (pii){a, b};
        IG_add(&g1, a, b, n);
    }
    for (int i = 0; i < m2; i++) {
        int a, b;
        next_int(&a);
        next_int(&b);
        cl2[i] = (pii){a, b};
        IG_add(&g2, a, b, n);
    }
    IG_transitiveClosure(&g1, n);
    IG_transitiveClosure(&g2, n);

    int r1 = IG_hasSolution(&g1, n);
    int r2 = IG_hasSolution(&g2, n);
    if (!r1 && !r2) {
        printf("SIMILAR\n");
        exit(0);
    }
    if (!r1) {
        IG_printSolutionAndDie(&g2, -1, -1, n);
    }
    if (!r2) {
        IG_printSolutionAndDie(&g1, -1, -1, n);
    }
    solve(cl1, cl2, &g1, &g2, m1, m2);
    solve(cl2, cl1, &g2, &g1, m2, m1);
    printf("SIMILAR\n");
}
