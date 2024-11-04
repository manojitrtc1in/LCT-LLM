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

int Bitset_test(const Bitset *b, int pos) {
    return (b->data[pos >> 5] >> (pos & 31)) & 1;
}

void Bitset_or(Bitset *a, const Bitset *b) {
    for (int i = 0; i < (MAX_N + 31) / 32; ++i) {
        a->data[i] |= b->data[i];
    }
}

void Bitset_and(Bitset *a, const Bitset *b) {
    for (int i = 0; i < (MAX_N + 31) / 32; ++i) {
        a->data[i] &= b->data[i];
    }
}

void Bitset_xor(Bitset *a, const Bitset *b) {
    for (int i = 0; i < (MAX_N + 31) / 32; ++i) {
        a->data[i] ^= b->data[i];
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
        g->bv[i] = 0;
    }
}

int getNum(int a, int n) {
    if (a > 0) return a - 1;
    a = -a;
    return n + a - 1;
}

int neg(int a, int n) {
    if (a < n) return a + n; else return a - n;
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

void transitiveClosure(IG *g, int n) {
    for (int i = 0; i < 2 * n; ++i) {
        if (i < n) {
            Bitset_set(&g->good[i], i);
        } else {
            Bitset_set(&g->bad[i], i - n);
        }
    }
    for (int mid = 0; mid < 2 * n; ++mid) {
        for (int i = 0; i < 2 * n; ++i) {
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
    for (int i = 0; i < 2 * n; ++i) {
        if (i < n) {
            if (Bitset_test(&g->bad[i], i)) g->bv[i] = 1;
        } else {
            if (Bitset_test(&g->good[i], i - n)) g->bv[i] = 1;
        }
    }
    for (int i = 0; i < 2 * n; ++i) {
        for (int j = 0; j < 2 * n; ++j) {
            if (!g->bv[j]) continue;
            if (j < n) {
                if (Bitset_test(&g->good[i], j)) g->bv[i] = 1;
            } else {
                if (Bitset_test(&g->bad[i], j - n)) g->bv[i] = 1;
            }
        }
    }
}

int hasSolution(IG *g, int n) {
    for (int i = 0; i < n; ++i) {
        if (Bitset_test(&g->bad[i], i) && Bitset_test(&g->good[i + n], i)) {
            return 0;
        }
    }
    return 1;
}

int num[MAX_N], sof[MAX_N];

int select(IG *g, int v, int n) {
    int t = v;
    if (num[v] == 0) t += n;
    if (g->bv[t]) return 0;
    int k = 0;
    sof[k++] = v;
    int ok = 1;
    for (int i = 0; i < n; ++i) {
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
        for (int i = 0; i < k; ++i) {
            num[sof[i]] = -1;
        }
        return 0;
    }
    return 1;
}

void printSolutionAndDie(int f1, int f2, int n) {
    memset(num, -1, sizeof(num));
    if (f1 != -1) {
        if (f1 < n) {
            num[f1] = 1;
        } else {
            f1 -= n;
            num[f1] = 0;
        }
        select(NULL, f1, n);
    }
    if (f2 != -1) {
        if (num[f2 < n ? f2 : f2 - n] == -1) {
            if (f2 < n) {
                num[f2] = 1;
            } else {
                f2 -= n;
                num[f2] = 0;
            }
            select(NULL, f2, n);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (num[i] != -1) continue;
        num[i] = 0;
        if (!select(NULL, i, n)) {
            num[i] = 1;
            select(NULL, i, n);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (i) printf(" ");
        printf("%d", num[i]);
    }
    printf("\n");
    exit(0);
}

int checkBad(IG *g, int v1, int v2) {
    Bitset temp;
    Bitset_init(&temp);
    for (int i = 0; i < (MAX_N + 31) / 32; ++i) {
        temp.data[i] = (g->good[v1].data[i] | g->good[v2].data[i]) & (g->bad[v1].data[i] | g->bad[v2].data[i]);
    }
    for (int i = 0; i < (MAX_N + 31) / 32; ++i) {
        if (temp.data[i]) return 1;
    }
    return 0;
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
    for (int i = 0; i < m1; ++i) {
        int v1 = getNum(cl1[i].x);
        int v2 = getNum(cl1[i].y);
        v1 = neg(v1, n);
        v2 = neg(v2, n);
        if (v1 > v2) {
            int temp = v1;
            v1 = v2;
            v2 = temp;
        }
        if (used[v1][v2]) continue;
        used[v1][v2] = 1;
        if (g2->bv[v1] || g2->bv[v2]) continue;
        if (checkBad(g2, v1, v2)) continue;
        printSolutionAndDie(v1, v2, n);
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
    
    pii cl1[MAX_C], cl2[MAX_C];
    
    for (int i = 0; i < m1; ++i) {
        next_int(&a);
        next_int(&b);
        cl1[i] = (pii){a, b};
        add(&g1, a, b, n);
    }
    
    for (int i = 0; i < m2; ++i) {
        next_int(&a);
        next_int(&b);
        cl2[i] = (pii){a, b};
        add(&g2, a, b, n);
    }
    
    transitiveClosure(&g1, n);
    transitiveClosure(&g2, n);
    
    int r1 = hasSolution(&g1, n);
    int r2 = hasSolution(&g2, n);
    
    if (!r1 && !r2) {
        printf("SIMILAR\n");
        exit(0);
    }
    if (!r1) {
        printSolutionAndDie(-1, -1, n);
    }
    if (!r2) {
        printSolutionAndDie(-1, -1, n);
    }
    
    solve(cl1, cl2, &g1, &g2, m1, m2);
    solve(cl2, cl1, &g2, &g1, m2, m1);
    
    printf("SIMILAR\n");
}
