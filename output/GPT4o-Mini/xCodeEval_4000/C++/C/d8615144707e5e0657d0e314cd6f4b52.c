#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <immintrin.h>

#define MAX_N 1004
#define MAX_M 2004
#define MAX_C 1000002

typedef struct {
    uint32_t data[(MAX_N + 31) / 32];
} Bitset;

typedef struct {
    Bitset good[MAX_M], bad[MAX_M];
    bool bv[MAX_M];
} IG;

int n, m1, m2;
int a, b;
int num[MAX_N], sof[MAX_N];
bool used[MAX_M][MAX_M];
int cl1[MAX_C][2], cl2[MAX_C][2];

void reset_bitset(Bitset *bs) {
    memset(bs->data, 0, sizeof(bs->data));
}

void set_bit(Bitset *bs, int pos) {
    bs->data[pos >> 5] |= 1u << (pos & 31);
}

bool test_bit(const Bitset *bs, int pos) {
    return (bs->data[pos >> 5] >> (pos & 31)) & 1;
}

void add_implication(IG *ig, int a, int b) {
    a = (a > 0) ? a - 1 : n + (-a) - 1;
    b = (b > 0) ? b - 1 : n + (-b) - 1;
    if (b < n) {
        set_bit(&ig->good[a], b);
    } else {
        set_bit(&ig->bad[a], b - n);
    }
}

void transitive_closure(IG *ig) {
    for (int i = 0; i < 2 * n; i++) {
        reset_bitset(&ig->good[i]);
        reset_bitset(&ig->bad[i]);
        if (i < n) {
            set_bit(&ig->good[i], i);
        } else {
            set_bit(&ig->bad[i], i - n);
        }
    }

    for (int mid = 0; mid < 2 * n; mid++) {
        for (int i = 0; i < 2 * n; i++) {
            bool ok = false;
            if (mid < n) {
                if (test_bit(&ig->good[i], mid)) {
                    ok = true;
                }
            } else {
                if (test_bit(&ig->bad[i], mid - n)) {
                    ok = true;
                }
            }
            if (ok) {
                for (int j = 0; j < (mid < n ? n : n); j++) {
                    if (mid < n) {
                        if (test_bit(&ig->good[mid], j)) {
                            set_bit(&ig->good[i], j);
                        }
                    } else {
                        if (test_bit(&ig->bad[mid], j - n)) {
                            set_bit(&ig->bad[i], j);
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < 2 * n; i++) {
        if (i < n) {
            if (test_bit(&ig->bad[i], i)) {
                ig->bv[i] = true;
            }
        } else {
            if (test_bit(&ig->good[i], i - n)) {
                ig->bv[i] = true;
            }
        }
    }

    for (int i = 0; i < 2 * n; i++) {
        for (int j = 0; j < 2 * n; j++) {
            if (!ig->bv[j]) continue;
            if (j < n) {
                if (test_bit(&ig->good[i], j)) {
                    ig->bv[i] = true;
                }
            } else {
                if (test_bit(&ig->bad[i], j - n)) {
                    ig->bv[i] = true;
                }
            }
        }
    }
}

bool has_solution(IG *ig) {
    for (int i = 0; i < n; i++) {
        if (test_bit(&ig->bad[i], i) && test_bit(&ig->good[i + n], i)) {
            return false;
        }
    }
    return true;
}

bool select(IG *ig, int v) {
    int t = v;
    if (num[v] == 0) t += n;
    if (ig->bv[t]) return false;
    int k = 0;
    sof[k++] = v;
    bool ok = true;

    for (int i = 0; i < n; i++) {
        if (test_bit(&ig->good[t], i)) {
            if (num[i] == 0) {
                ok = false;
                break;
            }
            if (num[i] == -1) {
                num[i] = 1;
                sof[k++] = i;
            }
        }
        if (test_bit(&ig->bad[t], i)) {
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
        return false;
    }
    return true;
}

void print_solution_and_die(IG *ig, int f1, int f2) {
    memset(num, -1, sizeof(num));
    if (f1 != -1) {
        if (f1 < n) {
            num[f1] = 1;
        } else {
            f1 -= n;
            num[f1] = 0;
        }
        select(ig, f1);
    }
    if (f2 != -1) {
        if (num[f2 < n ? f2 : f2 - n] == -1) {
            if (f2 < n) {
                num[f2] = 1;
            } else {
                f2 -= n;
                num[f2] = 0;
            }
            select(ig, f2);
        }
    }
    for (int i = 0; i < n; i++) {
        if (num[i] != -1) continue;
        num[i] = 0;
        if (!select(ig, i)) {
            num[i] = 1;
            select(ig, i);
        }
    }
    for (int i = 0; i < n; i++) {
        if (i) printf(" ");
        printf("%d", num[i]);
    }
    printf("\n");
    exit(0);
}

bool check_bad(IG *ig, int v1, int v2) {
    Bitset t;
    reset_bitset(&t);
    for (int i = 0; i < (MAX_N + 31) / 32; i++) {
        t.data[i] = (ig->good[v1].data[i] | ig->good[v2].data[i]) & (ig->bad[v1].data[i] | ig->bad[v2].data[i]);
    }
    for (int i = 0; i < (MAX_N + 31) / 32; i++) {
        if (t.data[i]) return true;
    }
    return false;
}

void solve(int cl1[][2], int cl2[][2], IG *g1, IG *g2, int m1, int m2) {
    memset(used, 0, sizeof(used));
    for (int i = 0; i < m1; i++) {
        int v1 = (cl1[i][0] > 0) ? cl1[i][0] - 1 : n + (-cl1[i][0]) - 1;
        int v2 = (cl1[i][1] > 0) ? cl1[i][1] - 1 : n + (-cl1[i][1]) - 1;
        if (v1 > v2) {
            int temp = v1;
            v1 = v2;
            v2 = temp;
        }
        if (used[v1][v2]) continue;
        used[v1][v2] = true;

        if (g2->bv[v1] || g2->bv[v2]) continue;
        if (check_bad(g2, v1, v2)) continue;
        print_solution_and_die(g2, v1, v2);
    }
}

int main() {
    IG g1, g2;
    memset(&g1, 0, sizeof(g1));
    memset(&g2, 0, sizeof(g2));

    scanf("%d %d %d", &n, &m1, &m2);
    for (int i = 0; i < m1; i++) {
        scanf("%d %d", &a, &b);
        cl1[i][0] = a;
        cl1[i][1] = b;
        add_implication(&g1, a, b);
    }
    for (int i = 0; i < m2; i++) {
        scanf("%d %d", &a, &b);
        cl2[i][0] = a;
        cl2[i][1] = b;
        add_implication(&g2, a, b);
    }
    transitive_closure(&g1);
    transitive_closure(&g2);

    bool r1 = has_solution(&g1);
    bool r2 = has_solution(&g2);
    if (!r1 && !r2) {
        printf("SIMILAR\n");
        exit(0);
    }
    if (!r1) {
        print_solution_and_die(&g2, -1, -1);
    }
    if (!r2) {
        print_solution_and_die(&g1, -1, -1);
    }
    solve(cl1, cl2, &g1, &g2, m1, m2);
    solve(cl2, cl1, &g2, &g1, m2, m1);
    printf("SIMILAR\n");
}
