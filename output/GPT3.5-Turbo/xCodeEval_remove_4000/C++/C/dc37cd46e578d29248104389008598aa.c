#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int p;
    int q;
} F;

typedef struct {
    int tr[202020];
} Fenw;

int x[101010];
int a[101010];
Fenw f1;
Fenw f[2];

int min(int a, int b) {
    return (a < b) ? a : b;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

void add(Fenw *fenw, int pos) {
    for (int i = pos; i <= 200020; i |= i + 1) {
        fenw->tr[i]++;
    }
}

int sum(Fenw *fenw, int pos) {
    int res = 0;
    for (int i = pos; i >= 0; i = (i & (i + 1)) - 1) {
        res += fenw->tr[i];
    }
    return res;
}

int solve1(int v[][2], int size, int w) {
    F allF[2 * size + 1];
    int allFSize = 0;
    for (int i = 0; i < size; i++) {
        F from = {v[i][0], v[i][1] + w};
        F to = {v[i][0], v[i][1] - w};
        allF[allFSize++] = from;
        allF[allFSize++] = to;
    }
    allF[allFSize++] = (F){0, 1};
    qsort(allF, allFSize, sizeof(F), [](const void *a, const void *b) {
        F *f1 = (F *)a;
        F *f2 = (F *)b;
        if (f1->p * 1LL * f2->q < f2->p * 1LL * f1->q) {
            return -1;
        } else if (f1->p * 1LL * f2->q > f2->p * 1LL * f1->q) {
            return 1;
        } else {
            return 0;
        }
    });
    int vSize = sizeof(v) / sizeof(v[0]);
    for (int i = 0; i < vSize; i++) {
        F from = {v[i][0], v[i][1] + w};
        F to = {v[i][0], v[i][1] - w};
        int fromIndex = -1;
        int toIndex = -1;
        for (int j = 0; j < allFSize; j++) {
            if (from.p == allF[j].p && from.q == allF[j].q) {
                fromIndex = j;
            }
            if (to.p == allF[j].p && to.q == allF[j].q) {
                toIndex = j;
            }
        }
        v[i][0] = fromIndex;
        v[i][1] = toIndex;
    }
    qsort(v, vSize, sizeof(v[0]), [](const void *a, const void *b) {
        int *v1 = (int *)a;
        int *v2 = (int *)b;
        if (v1[0] < v2[0] || (v1[0] == v2[0] && v1[1] > v2[1])) {
            return -1;
        } else if (v1[0] > v2[0] || (v1[0] == v2[0] && v1[1] < v2[1])) {
            return 1;
        } else {
            return 0;
        }
    });
    long long res = 0;
    memset(f1.tr, 0, sizeof(f1.tr));
    for (int i = 0; i < vSize; i++) {
        res += i - sum(&f1, v[i][1] - 1);
        add(&f1, v[i][1]);
    }
    return res;
}

long long solve2(int v[][2], int size, int w) {
    F allF[2 * size + 1];
    int allFSize = 0;
    for (int i = 0; i < size; i++) {
        F from = {v[i][0], v[i][1] + w};
        F to = {v[i][0], v[i][1] - w};
        allF[allFSize++] = from;
        allF[allFSize++] = to;
    }
    allF[allFSize++] = (F){0, 1};
    qsort(allF, allFSize, sizeof(F), [](const void *a, const void *b) {
        F *f1 = (F *)a;
        F *f2 = (F *)b;
        if (f1->p * 1LL * f2->q < f2->p * 1LL * f1->q) {
            return -1;
        } else if (f1->p * 1LL * f2->q > f2->p * 1LL * f1->q) {
            return 1;
        } else {
            return 0;
        }
    });
    int vSize = sizeof(v) / sizeof(v[0]);
    for (int i = 0; i < vSize; i++) {
        F from = {v[i][0], v[i][1] + w};
        F to = {v[i][0], v[i][1] - w};
        int fromIndex = -1;
        int toIndex = -1;
        for (int j = 0; j < allFSize; j++) {
            if (from.p == allF[j].p && from.q == allF[j].q) {
                fromIndex = j;
            }
            if (to.p == allF[j].p && to.q == allF[j].q) {
                toIndex = j;
            }
        }
        v[i][0] = fromIndex;
        v[i][1] = toIndex;
        add(&f[i % 2], v[i][0]);
    }
    long long res = 0;
    for (int i = 0; i < vSize; i++) {
        res += sum(&f[(i + 1) % 2], v[i][0], v[i][1]);
    }
    return res;
}

long long solve(int n, int w) {
    int v[2][101010][2];
    int vSize[2] = {0, 0};
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x[i], &a[i]);
        if (x[i] < 0) {
            v[0][vSize[0]][0] = abs(x[i]);
            v[0][vSize[0]][1] = abs(a[i]);
            vSize[0]++;
        } else {
            v[1][vSize[1]][0] = abs(x[i]);
            v[1][vSize[1]][1] = abs(a[i]);
            vSize[1]++;
        }
    }
    long long ans = 0;
    ans += solve1(v[0], vSize[0], w);
    ans += solve1(v[1], vSize[1], w);
    ans += solve2(v[0], vSize[0], w);
    ans += solve2(v[1], vSize[1], w);
    return ans;
}

int main() {
    int n, w;
    scanf("%d %d", &n, &w);
    printf("%lld\n", solve(n, w));
    return 0;
}
