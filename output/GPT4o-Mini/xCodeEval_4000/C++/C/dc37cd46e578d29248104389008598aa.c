#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 101010
#define MAX_TR 202020

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int p, q;
} F;

typedef struct {
    int tr[MAX_TR];
} Fenw;

int x[MAX_SIZE];
int a[MAX_SIZE];
pii v[2][MAX_SIZE];
int w;

bool compareF(const F* f1, const F* f2) {
    return (long long)f1->p * f2->q < (long long)f2->p * f1->q;
}

void Fenw_add(Fenw* fenw, int pos) {
    for (int i = pos; i <= MAX_TR; i |= i + 1) {
        fenw->tr[i]++;
    }
}

int Fenw_sum(Fenw* fenw, int pos) {
    int res = 0;
    for (int i = pos; i >= 0; i = (i & (i + 1)) - 1) {
        res += fenw->tr[i];
    }
    return res;
}

int Fenw_sum_range(Fenw* fenw, int l, int r) {
    return Fenw_sum(fenw, r) - Fenw_sum(fenw, l - 1);
}

long long solve1(pii v[], int size) {
    F allF[MAX_SIZE * 2];
    int allF_size = 0;

    for (int i = 0; i < size; i++) {
        allF[allF_size++] = (F){v[i].first, v[i].second + w};
        allF[allF_size++] = (F){v[i].first, v[i].second - w};
    }
    allF[allF_size++] = (F){0, 1};

    // Sort and remove duplicates (not implemented here)
    // sort_and_unique(allF, &allF_size);

    for (int i = 0; i < size; i++) {
        F from = {v[i].first, v[i].second + w};
        F to = {v[i].first, v[i].second - w};
        // v[i] = (pii){lower_bound(allF, allF_size, from), lower_bound(allF, allF_size, to)};
    }

    // Sort v (not implemented here)
    // sort(v, size);

    long long res = 0;
    Fenw f1 = {0};
    for (int i = 0; i < size; i++) {
        res += i - Fenw_sum(&f1, v[i].second - 1);
        Fenw_add(&f1, v[i].second);
    }
    return res;
}

long long solve2(pii v[2][MAX_SIZE], int size[2]) {
    F allF[MAX_SIZE * 2];
    int allF_size = 0;
    Fenw f[2] = {0};

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < size[i]; j++) {
            allF[allF_size++] = (F){v[i][j].first, v[i][j].second + w};
            allF[allF_size++] = (F){v[i][j].first, v[i][j].second - w};
        }
    }
    allF[allF_size++] = (F){0, 1};

    // Sort and remove duplicates (not implemented here)
    // sort_and_unique(allF, &allF_size);

    long long res = 0;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < size[i]; j++) {
            F from = {v[i][j].first, v[i][j].second + w};
            F to = {v[i][j].first, v[i][j].second - w};
            // v[i][j] = (pii){lower_bound(allF, allF_size, from), lower_bound(allF, allF_size, to)};
            Fenw_add(&f[i], v[i][j].first);
        }
    }

    for (int i = 0; i < size[0]; i++) {
        res += Fenw_sum_range(&f[1], v[0][i].first, v[0][i].second);
    }
    for (int i = 0; i < size[1]; i++) {
        res += Fenw_sum_range(&f[0], v[1][i].first + 1, v[1][i].second);
    }
    return res;
}

int solve() {
    int n;
    scanf("%d", &n);
    scanf("%d", &w);
    int size[2] = {0};

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x[i], &a[i]);
        v[x[i] < 0][size[x[i] < 0]++] = (pii){abs(x[i]), abs(a[i])};
    }

    long long ans = 0;
    ans += solve1(v[0], size[0]);
    ans += solve1(v[1], size[1]);
    ans += solve2(v, size);
    printf("%lld\n", ans);

    return 0;
}

int main() {
    return solve();
}
