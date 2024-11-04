#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_N 1004
#define MAX_M 2004

typedef struct {
    bool data[MAX_N];
} Bitset;

typedef struct {
    Bitset good[MAX_M];
    Bitset bad[MAX_M];
    bool bv[MAX_M];
} IG;

int n, m1, m2;
int cl1[MAX_M][2];
int cl2[MAX_M][2];
bool used[MAX_M][MAX_M];

void addImplication(Bitset *a, Bitset *b) {
    for (int i = 0; i < n; i++) {
        if (b->data[i]) {
            a->data[i] = true;
        }
    }
}

void add(IG *g, int a, int b) {
    addImplication(&g->good[a], &g->bad[b]);
    addImplication(&g->good[b], &g->bad[a]);
}

void transitiveClosure(IG *g) {
    for (int i = 0; i < 2 * n; i++) {
        if (i < n) {
            g->good[i].data[i] = true;
        } else {
            g->bad[i].data[i - n] = true;
        }
    }

    for (int mid = 0; mid < 2 * n; mid++) {
        for (int i = 0; i < 2 * n; i++) {
            bool ok = false;
            if (mid < n) {
                if (g->good[i].data[mid]) {
                    ok = true;
                }
            } else {
                if (g->bad[i].data[mid - n]) {
                    ok = true;
                }
            }
            if (ok) {
                addImplication(&g->good[i], &g->good[mid]);
                addImplication(&g->bad[i], &g->bad[mid]);
            }
        }
    }

    for (int i = 0; i < 2 * n; i++) {
        if (i < n) {
            if (g->bad[i].data[i]) {
                g->bv[i] = true;
            }
        } else {
            if (g->good[i].data[i - n]) {
                g->bv[i] = true;
            }
        }
    }

    for (int i = 0; i < 2 * n; i++) {
        for (int j = 0; j < 2 * n; j++) {
            if (!g->bv[j]) {
                continue;
            }
            if (j < n) {
                if (g->good[i].data[j]) {
                    g->bv[i] = true;
                }
            } else {
                if (g->bad[i].data[j - n]) {
                    g->bv[i] = true;
                }
            }
        }
    }
}

bool hasSolution(IG *g) {
    for (int i = 0; i < n; i++) {
        if (g->bad[i].data[i] && g->good[i + n].data[i]) {
            return false;
        }
    }
    return true;
}

void select(IG *g, int v, int *num, int *sof) {
    int t = v;
    if (num[v] == 0) {
        t += n;
    }
    if (g->bv[t]) {
        return;
    }
    int k = 0;
    sof[k++] = v;
    bool ok = true;
    for (int i = 0; i < n; i++) {
        if (g->good[t].data[i]) {
            if (num[i] == 0) {
                ok = false;
                break;
            }
            if (num[i] == -1) {
                num[i] = 1;
                sof[k++] = i;
            }
        }
        if (g->bad[t].data[i]) {
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

void printSolutionAndDie(IG *g, int f1, int f2, int *num) {
    memset(num, -1, sizeof(int) * n);
    if (f1 != -1) {
        if (f1 < n) {
            num[f1] = 1;
        } else {
            f1 -= n;
            num[f1] = 0;
        }
        select(g, f1, num, NULL);
    }
    if (f2 != -1) {
        if (num[f2 < n ? f2 : f2 - n] == -1) {
            if (f2 < n) {
                num[f2] = 1;
            } else {
                f2 -= n;
                num[f2] = 0;
            }
            select(g, f2, num, NULL);
        }
    }
    for (int i = 0; i < n; i++) {
        if (num[i] != -1) {
            continue;
        }
        num[i] = 0;
        select(g, i, num, NULL);
        if (!num[i]) {
            num[i] = 1;
            select(g, i, num, NULL);
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

bool checkBad(IG *g, int v1, int v2) {
    Bitset t;
    for (int i = 0; i < n; i++) {
        t.data[i] = (g->good[v1].data[i] || g->good[v2].data[i]) && (g->bad[v1].data[i] || g->bad[v2].data[i]);
    }
    for (int i = 0; i < n; i++) {
        if (t.data[i]) {
            return true;
        }
    }
    return false;
}

void solve(IG *g1, IG *g2, int m1, int m2) {
    memset(used, false, sizeof(used));
    for (int i = 0; i < m1; i++) {
        int v1 = cl1[i][0] - 1;
        int v2 = cl1[i][1] - 1;
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
        used[v1][v2] = true;

        if (g2->bv[v1] || g2->bv[v2]) {
            continue;
        }
        if (checkBad(g2, v1, v2)) {
            continue;
        }
        printSolutionAndDie(g2, v1, v2, NULL);
    }
}

int main() {
    scanf("%d %d %d", &n, &m1, &m2);
    for (int i = 0; i < m1; i++) {
        scanf("%d %d", &cl1[i][0], &cl1[i][1]);
        add(&g1, cl1[i][0] - 1, cl1[i][1] - 1);
    }
    for (int i = 0; i < m2; i++) {
        scanf("%d %d", &cl2[i][0], &cl2[i][1]);
        add(&g2, cl2[i][0] - 1, cl2[i][1] - 1);
    }
    transitiveClosure(&g1);
    transitiveClosure(&g2);

    bool r1 = hasSolution(&g1);
    bool r2 = hasSolution(&g2);
    if (!r1 && !r2) {
        printf("SIMILAR\n");
        return 0;
    }
    if (!r1) {
        printSolutionAndDie(&g2, -1, -1, NULL);
    }
    if (!r2) {
        printSolutionAndDie(&g1, -1, -1, NULL);
    }
    solve(&g1, &g2, m1, m2);
    solve(&g2, &g1, m2, m1);
    printf("SIMILAR\n");

    return 0;
}
